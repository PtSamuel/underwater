import os
import serial
import subprocess
import sys

serial_port = "/dev/serial/by-id/"
password = "123456"
safe_throttle_max = 0.5

def open_port():	
    if os.path.isdir(serial_port):
        files = os.listdir(serial_port)
        
        if len(files) == 0:
            print("Empty folder:", serial_port)
        else:
            serial_device = serial_port + files[0] # usually /dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10101a31f19238b029dba7106e00dcf30f11-if01
            command = f"echo {password} | sudo chmod a+rw {serial_device}"
            result = subprocess.run(command, shell=True, capture_output=True, text=True)
            print("Grant access result:", result)

            ser = serial.Serial(serial_device, baudrate=9600, timeout=1)
            if ser.is_open:
                print("Serial successfully established at", serial_device)
                return ser
            else:
                print("Serial connection failed at", serial_device)
    
    return None

def map(x):
    return x / 8

def send_throttle(ser, t):
    command = f"$LT {t}\r"
    ser.write(command.encode())

def protection(t):
    if abs(t) > safe_throttle_max:
        print(f"Throttle clipped to [{-safe_throttle_max}, {safe_throttle_max}]")
        return safe_throttle_max * (1 if t > 0 else -1)
    return t

def main():

    ser = open_port()

    if ser == None:
        print("Failed to open port:", serial_port)
        return
    
    args = sys.argv
    throttle = float(0 if len(args) == 1 else args[1])
    send_throttle(ser, protection(throttle))

    while True:
        try:
            read = input("Enter throttle in [-1.0, 1.0]: ")
            throttle = float(read)
            throttle = protection(throttle)
            send_throttle(ser, throttle)
        except KeyboardInterrupt:
            print("Received", KeyboardInterrupt)
            print("Zeroing throttle")
            send_throttle(ser, 0)
            break
        except Exception as e:
            print("Invalid throttle:", e)

if __name__ == "__main__":
    main()


# set eth0 IPv4 using sudo ifconfig eth0 169.254.1.172 (or whatever fits the ip address on the master computer) netmask 255.255.0.0
