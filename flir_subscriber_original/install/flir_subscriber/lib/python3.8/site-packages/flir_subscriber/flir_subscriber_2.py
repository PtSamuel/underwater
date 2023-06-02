#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
import numpy as np
from cv_bridge import CvBridge

class ImageSubscriber(Node):
    def __init__(self, name):
        super().__init__(name)
        self.startup = True
        self.sub =  self.create_subscription(
            Image, "blackfly_0/image_raw", self.listener_callback, 10
        )
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        
        width = msg.width
        height = msg.height
        encoding = msg.encoding
        data = msg.data
        
        if self.startup:
            with open('save.npy', 'wb') as f:
                np.save(f, data)
            self.startup = False

        bayer_image = np.array(data).reshape([width, height])
        rgb_image = cv2.cvtColor(bayer_image, cv2.COLOR_BayerRG2RGB)

        # image_resized = cv2.resize(image, (1920, 1080))
        cv2.imshow("image_mono", rgb_image)
        cv2.waitKey(50)
        
        self.get_logger().info("Receiving frame", width, height, encoding, rgb_image.shape)

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber("flir_subscriber")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
