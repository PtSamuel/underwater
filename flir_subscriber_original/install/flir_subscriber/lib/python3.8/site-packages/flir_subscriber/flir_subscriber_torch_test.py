#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
import numpy as np
from cv_bridge import CvBridge

import torch
import torchvision.models as models
import torchvision.transforms as transforms
from PIL import Image
import json

class ImageSubscriber(Node):
    def __init__(self, name):
        super().__init__(name)
        model = models.resnet50(pretrained=True)
        model.eval()
        self.model = model
        self.preprocess = transforms.Compose([
            transforms.Resize(256),
            transforms.CenterCrop(224),
            transforms.ToTensor(),
            transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
        ])
        self.labels_path = "~/flir_subscriber/src/flir_subscriber/resource/resnet_labels.txt"

        self.get_logger().info("model ready.")      

        self.sub =  self.create_subscription(
            Image, "blackfly_0/image_raw", self.listener_callback, 10
        )
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        
        width = msg.width
        height = msg.height
        capture = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        input_tensor = self.preprocess(capture)
        input_batch = input_tensor.unsqueeze(0)
        with torch.no_grad():
            output = self.model(input_batch)

        _, predicted_idx = torch.max(output, 1)

        with open(self.labels_path, 'r') as f:
            labels = json.load(f)

        predicted_label = labels[predicted_idx.item()]
        self.get_logger().info(f"Predicted label: {predicted_label}")

        font = cv2.FONT_HERSHEY_SIMPLEX
        font_scale = 1
        color = (255, 255, 255)
        thickness = 2  
        text_size, _ = cv2.getTextSize(text, font, font_scale, thickness)

        x = 0
        y = int(text_size[1] / 2)
        cv2.putText(image, text, (x, y), font, font_scale, color, thickness)

        self.get_logger().info(f"width: {width}, height: {height}, image shape: {capture.shape}")

        cv2.imshow("capture", capture)
        cv2.waitKey(50)

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber("flir_subscriber")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
