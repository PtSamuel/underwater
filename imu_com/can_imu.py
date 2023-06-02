import can
import struct
from read_imu import to_hex
import time

bus = can.interface.Bus(channel="can0", bustype='socketcan')

def to_short(opt, byte_arr):
    little_endian = bytearray(reversed(byte_arr))
    return struct.unpack(opt, little_endian)[0]

count = 0 
start = time.time()
while True:
    message = bus.recv()
    id = message.arbitration_id
    data = message.data
    if id == 0x5:
        # alpha = to_short('h', data[0:2])
        # beta = to_short('h', data[2:4])
        # gamma = to_short('h', data[4:6])
        count += 1
        # print(to_hex(data))
        # print(f"{alpha:<6d}, {beta:<6d}, {gamma:<6d}, {count / (time.time() - start) : .6f}")
        print(f"{count / (time.time() - start) : .6f}")
        # print(f"{alpha / 0x7FFF : .6f}, {beta / 0x7FFF : .6f}, {gamma / 0x7FFF : .6f}")