#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
# from cv_bridge import cv_bridge
import cv2

class ImageSubscriber(Node):
    def __init__(self, name):
        super().__init__(name)
        self.sub =  self.create_subscription(
            Image, "blackfly_0/image_raw", self.listener_callback, 10)
        # self.cv_bridge = CvBridge()

    def listener_callback(self, data):
        self.get_logger().info("Receiving frame")
        # image = self.cv_bridge.imgmsg_to_cv2(data, "bgr8")
        # self.show(image)

    def show(self, image):
        cv2.imshow("capture", image)

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber("flir_subscriber")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
