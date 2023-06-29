import rclpy
from rclpy.node import Node
import os
import serial
import subprocess

from sensor_msgs.msg import Joy

serial_port = "/dev/serial/by-id/"
password = "123456"

class MotorController(Node):

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
        return x / 3

    def actuate_forward(self, forward):
        
        mapped_throttle = self.map(forward)
        
        return [mapped_throttle, mapped_throttle, 0, 0, -mapped_throttle, -mapped_throttle]
        # print(command)
        # self.ser.write(command.encode())

    def actuate_lateral(self, turn):
        mapped_throttle = self.map(turn)
        command = f"$LT {-mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {-mapped_throttle:.2f} {mapped_throttle:.2f}\r"
        print(command)
        self.ser.write(command.encode())

    def actuate_turn(self, turn):
        
        mapped_throttle = self.map(turn)
        
        return [-mapped_throttle, mapped_throttle, 0, 0, mapped_throttle, -mapped_throttle]
        # command = f"$LT {mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {-mapped_throttle:.2f} {-mapped_throttle:.2f}\r"
        # command = f"$LT {-mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {mapped_throttle:.2f} {-mapped_throttle:.2f}\r"
        # print(command)
        # self.ser.write(command.encode())

    def listener_callback(self, message):
        # self.get_logger().info(f"Receiving: {message.axes}, {message.buttons}")
        if self.ser != None:
            forward = -float(message.axes[1])
            turn = float(message.axes[0])
            rise = float(message.axes[3])
            # print(f"forward: {forward:.02f}, turn: {turn:.02f}, rise: {rise:.02f}, ")

            T_forward = self.actuate_forward(forward)
            # self.actuate_lateral(turn)
            T_turn = self.actuate_turn(turn)
            print(T_forward, T_turn)
            T_total = [x + y for x, y in zip(T_forward, T_turn)]

            command = f"$LT {T_total[0]:.02f} {T_total[1]:.02f} 0 0 {T_total[4]:.02f} {T_total[5]:.02f}\r"

            self.ser.write(command.encode())
            self.get_logger().info(f"Sending: {command}")
     
def main(args=None):
    rclpy.init(args=args)
    motor_controller = MotorController("motor_controller_node")
    rclpy.spin(motor_controller)
    motor_controller.destroy_node()
    rclpy.shutdown()

# set eth0 IPv4 using sudo ifconfig eth0 169.254.1.172 (or whatever fits the ip address on the master computer) netmask 255.255.0.0
