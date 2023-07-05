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
        
        self.reset_prev = None
        self.on = True
    
    def map(self, x):
        return x

    def map_turn(self, x):
        return x / 3

    def actuate_forward(self, forward):
        
        mapped_throttle = self.map(forward)
        
        return [mapped_throttle, mapped_throttle, 0, 0, -mapped_throttle, -mapped_throttle]
        # print(command)
        # self.ser.write(command.encode())

    def actuate_lateral(self, lateral):
        mapped_throttle = self.map(lateral)
        # command = f"$LT {-mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {-mapped_throttle:.2f} {mapped_throttle:.2f}\r"
        # print(command)
        # self.ser.write(command.encode())
        return [-mapped_throttle, mapped_throttle, 0, 0, -mapped_throttle, mapped_throttle]

    def actuate_vertical(self, dive, rise):
        mapped_vertical = self.map(dive - rise)
        # command = f"$LT 0 0 {mapped_dive:.2f} {mapped_dive:.2f} 0 0\r"
        # print(command)
        return [0, 0, mapped_vertical, mapped_vertical, 0, 0]

    def add_vector(self, v1, v2):
        return [x + y for x, y in zip(v1, v2)]

    def actuate_turn(self, turn):
        
        mapped_throttle = self.map_turn(turn)
        
        return [-mapped_throttle, mapped_throttle, 0, 0, mapped_throttle, -mapped_throttle]
        # command = f"$LT {mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {-mapped_throttle:.2f} {-mapped_throttle:.2f}\r"
        # command = f"$LT {-mapped_throttle:.2f} {mapped_throttle:.2f} 0 0 {mapped_throttle:.2f} {-mapped_throttle:.2f}\r"
        # print(command)
        # self.ser.write(command.encode())

    def listener_callback(self, message):
        
        reset = message.buttons[4]
        if self.reset_prev == 1 and reset == 0:
            self.on = not self.on
            if not self.on:
                print("Pausing control, sending zeros")
                self.ser.write("$LT 0 0 0 0 0 0\r".encode())

        self.reset_prev = reset

        if not self.on:
            return

        # self.get_logger().info(f"Receiving: {message.axes}, {message.buttons}")
        if self.ser != None:
            forward = -message.axes[1]
            lateral = -message.axes[0]
            turn = -message.axes[2]
            dive = (message.axes[4] + 1) / 2
            rise = (message.axes[5] + 1) / 2
            print("dive, rise:", dive, rise)
            # print(f"forward: {forward:.02f}, turn: {turn:.02f}, rise: {rise:.02f}, ")
            T_forward = self.actuate_forward(forward)
            T_lateral = self.actuate_lateral(lateral)
            T_turn = self.actuate_turn(turn)
            T_vertical = self.actuate_vertical(dive, rise)
            # print(T_forward, T_turn)
            T_total = self.add_vector(self.add_vector(self.add_vector(T_forward, T_turn), T_vertical), T_lateral)

            command = f"$LT {T_total[0]:.02f} {T_total[1]:.02f} {T_total[2]:.02f} {T_total[3]:.02f} {T_total[4]:.02f} {T_total[5]:.02f}\r"

            self.ser.write(command.encode())
            self.get_logger().info(f"Sending: {command}")
     
def main(args=None):
    rclpy.init(args=args)
    motor_controller = MotorController("motor_controller_node")
    rclpy.spin(motor_controller)
    motor_controller.destroy_node()
    rclpy.shutdown()

# set eth0 IPv4 using sudo ifconfig eth0 169.254.1.172 (or whatever fits the ip address on the master computer) netmask 255.255.0.0