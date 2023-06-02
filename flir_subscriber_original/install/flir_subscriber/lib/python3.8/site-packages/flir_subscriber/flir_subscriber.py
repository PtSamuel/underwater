#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from flir_subscriber import run_model

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
import numpy as np
from cv_bridge import CvBridge

# import sys
# sys.path.append("/home/samuel/flir_subscriber/src/flir_subscriber/flir_subscriber/")

class ImageSubscriber(Node):
    def __init__(self, name):
        super().__init__(name)
        self.prev = None
        self.running_interval = None
        self.alpha = 0.1
        self.sub =  self.create_subscription(
            Image, "blackfly_0/image_raw", self.listener_callback, 10
        )
        self.bridge = CvBridge()

    def draw_label(self, capture_display, prediction):
        font = cv2.FONT_HERSHEY_SIMPLEX
        font_scale = 1.0
        font_color = (255, 255, 255)
        stroke_color = (0, 0, 0)
        thickness = 2

        text_size, _ = cv2.getTextSize(prediction, font, font_scale, thickness)

        text_x = 10
        text_y = text_size[1] + 10

        offset = 1
        for dx in range(-offset, offset + 1):
            for dy in range(-offset, offset + 1):
                cv2.putText(capture_display, prediction, (text_x + dx, text_y + dy), font, font_scale, stroke_color, thickness, cv2.LINE_AA)

        cv2.putText(capture_display, prediction, (text_x, text_y), font, font_scale, font_color, thickness, cv2.LINE_AA)

    def listener_callback(self, msg):
        
        width = msg.width
        height = msg.height
        capture = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        self.get_logger().info(f"width: {width}, height: {height}, image shape: {capture.shape}")

        capture_display = capture
        # capture_display = cv2.resize(capture, (width // 4, height // 4))
        # capture_inference = cv2.resize(capture, (224, 224))
        # p, prediction = run_model.predict(capture_inference)

        cur = self.get_clock().now()
        if self.prev is None:
            self.prev = cur
        else:
            interval = cur - self.prev
            if self.running_interval is None:
                self.running_interval = interval.nanoseconds
            else:
                self.running_interval = (1 - self.alpha) * self.running_interval + self.alpha * interval.nanoseconds
            self.prev = cur
        
        if self.running_interval is None: 
            show = ""
        else: 
            fps = 1 / (self.running_interval * 1e-9)
            show = f"{fps:.2f} FPS"
            
        # show = f"result: {prediction} ({float(p):.3%}), {fps:.2f} FPS"
        self.get_logger().info(show)
        self.draw_label(capture_display, show)

        cv2.imshow("capture", capture_display)
        cv2.waitKey(50)

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber("flir_subscriber")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
