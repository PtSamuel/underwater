import rclpy
from rclpy.node import Node
import os
import serial
import subprocess

from sensor_msgs.msg import Joy

serial_port = "/dev/serial/by-id/"
password = "123456"

class JoySubscriber(Node):

    def __init__(self, name):
        super().__init__(name)
        self.subscriber = self.create_subscription(
            Joy,
            'joystick',
            self.listener_callback,
            10
        )

        if os.path.isdir(serial_port):
            files = os.listdir(serial_port)
            
            if len(files) == 0:
                print("Empty folder:", serial_port)
                self.ser = None
            else:
                serial_device = serial_port + files[0] # usually /dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10101a31f19238b029dba7106e00dcf30f11-if01
               
                command = f"echo {password} | sudo chmod a+rw {serial_device}"
                result = subprocess.run(command, shell=True, capture_output=True, text=True)
                print("Grant access result:", result)

                ser = serial.Serial(serial_device, baudrate=9600, timeout=1)
                if ser.is_open:
                    print("Serial successfully established at", serial_device)
                    self.ser = ser
                else:
                    print("Serial connection failed at", serial_device)
                    self.ser = None
    
    def map(self, x):
        return x / 8

    def listener_callback(self, message):
        self.get_logger().info(f"Receiving: {message.axes}, {message.buttons}")
        if self.ser != None:
            command = f"$LT {self.map(message.axes[1])}\r"
            self.ser.write(command.encode())
            self.get_logger().info(f"Sending: {command}")
     
def main(args=None):
    rclpy.init(args=args)
    joy_subscriber = JoySubscriber("joy_subscriber_node")
    rclpy.spin(joy_subscriber)
    joy_subscriber.destroy_node()
    rclpy.shutdown()

# set eth0 IPv4 using sudo ifconfig eth0 169.254.1.172 (or whatever fits the ip address on the master computer) netmask 255.255.0.0