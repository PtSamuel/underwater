import serial
import sys
import time

levels = 9

interval = float(sys.argv[1])
print("interval:", interval, "ms")

ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600, timeout=1)
while True:
    for i in range(levels + 1):
        command = f"$L1 {i/levels}\r"
        print(command)
        ser.write(command.encode())
        time.sleep(interval / 1000)



