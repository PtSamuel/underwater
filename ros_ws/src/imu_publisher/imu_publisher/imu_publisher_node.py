import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import threading

import struct
import can
import time

def to_short(opt, byte_arr):
    # little_endian = bytearray(reversed(byte_arr))
    # return struct.unpack(opt, little_endian)[0]

    return struct.unpack('>' + opt, byte_arr)[0]


class IMUPublisher(Node):

    def __init__(self):
        super().__init__('imu_publisher')

        self.bus = can.interface.Bus(channel="can0", bustype='socketcan')
        self.euler = self.create_publisher(String, 'euler_raw', 10)
        self.gyro = self.create_publisher(String, 'gyro_raw', 10)
        self.quat = self.create_publisher(String, 'quat_raw', 10)
        self.acc = self.create_publisher(String, 'acc_raw', 10)
        self.temp = self.create_publisher(String, 'imu_temp_raw', 10)
        self.pres = self.create_publisher(String, 'imu_pres_raw', 10)

        self.start = time.time()
        self.count = [0, 0, 0, 0, 0, 0]
        self.LT = [0x22, 0x32, 0x21, 0x34, 0x51, 0x52]

        self.imu_thread = threading.Thread(target=self.read_all_outputs)
        self.imu_thread.start()

    def log(self, ID):
        try:
            index = self.LT.index(ID)
            self.count[index] += 1
            if sum(self.count) % 500 == 0:
                print([i / (time.time() - self.start) for i in self.count])
        except Exception:
            pass
    
    def read_all_outputs(self):
        count = 0
        start = time.time()
        while True:
            temp = self.bus.recv()
            ID = temp.arbitration_id
            data = temp.data

            message = String()

            if ID == 0x22:
                alpha = to_short('h', data[0:2])
                beta = to_short('h', data[2:4])
                gamma = to_short('h', data[4:6])
                message.data = f"{alpha} {beta} {gamma}"
                self.euler.publish(message)
            elif ID == 0x32:
                gyro_x = to_short('h', data[0:2])
                gyro_y = to_short('h', data[2:4])
                gyro_z = to_short('h', data[4:6])
                message.data = f"{gyro_x} {gyro_y} {gyro_z}"
                self.gyro.publish(message)
            elif ID == 0x21:
                Q0 = to_short('h', data[0:2])
                Q1 = to_short('h', data[2:4])
                Q2 = to_short('h', data[4:6])
                Q3 = to_short('h', data[6:8])
                message.data = f"{Q0} {Q1} {Q2} {Q3}"
                self.quat.publish(message)
            elif ID == 0x34:
                acc_x = to_short('h', data[0:2])
                acc_y = to_short('h', data[2:4])
                acc_z = to_short('h', data[4:6])
                message.data = f"{acc_x} {acc_y} {acc_z}"
                self.acc.publish(message)
            elif ID == 0x51: # temperature
                message.data = f"{to_short('h', data)}"
                self.temp.publish(message)
            elif ID == 0x52: # pressure
                message.data = f"{to_short('I', data)}"
                self.pres.publish(message)
            else:
                continue
            
            self.log(ID)

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = IMUPublisher()
    rclpy.spin(imu_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()
