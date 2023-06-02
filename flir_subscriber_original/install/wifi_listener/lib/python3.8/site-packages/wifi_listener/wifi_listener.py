import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial

class WifiSubscriberNode(Node):

    def __init__(self, name):
        super().__init__(name)
        self.subscriber = self.create_subscription(
            Joy,
            'joystick',
            self.listener_callback,
            10
        )
        ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600, timeout=1)
        if ser.is_open:
            print("Serial successfully established")
            self.ser = ser
        else:
            print("Serial connection failed")
            self.ser = None

    def map(self, x):
        return (x + 1) / 2

    def listener_callback(self, message):
        self.get_logger().info(f"Receiving: {message.axes}, {message.buttons}")
        if self.ser != None:
            for i in range(1, 5):
                command = f"$L{i} {self.map(message.axes[i - 1])}\r"
                self.ser.write(command.encode())

def main(args=None):
    rclpy.init(args=args)
    wifi_listener = WifiSubscriberNode("wifi_listener_node")
    rclpy.spin(wifi_listener)
    wifi_listener.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()