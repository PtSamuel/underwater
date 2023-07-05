import os
import serial
import subprocess
import sys

serial_port = "/dev/serial/by-id/"
password = "123456"
safe_throttle_max = 0.5
safety_mode = False

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
    command = f"$LT {t[0]} {t[1]} {t[2]} {t[3]} {t[4]} {t[5]}\r"
    ser.write(command.encode())

def protection(t):
    if t > 1.0 or t < -1.0:
        print("t must be in [-1.0, 1.0]")
        return
    if not safety_mode:
        return t
    if abs(t) > safe_throttle_max:
        print(f"Throttle clipped to [{-safe_throttle_max}, {safe_throttle_max}]")
        return safe_throttle_max * (1 if t > 0 else -1)
    else: return t

def main():

    ser = open_port()

    if ser == None:
        print("Failed to open port:", serial_port)
        return

    print(ser.readlines())
    
    args = sys.argv
    throttle = float(0 if len(args) == 1 else args[1])
    send_throttle(ser, [protection(throttle) for _ in range(6)])

    while True:
        try:
            inputs = input("Enter throttles, each in [-1.0, 1.0]: ")
            print(inputs, "len =", len(inputs))
            values = inputs.split()
            print(values)
            if len(values) != 6:
                print("Input should be exactly 6 values")
                continue
            throttles = [protection(float(i)) for i in values]
            send_throttle(ser, throttles)
        except KeyboardInterrupt:
            print("Received", KeyboardInterrupt)
            print("Zeroing throttle")
            send_throttle(ser, [0, 0, 0, 0, 0, 0])
            return
        except Exception as e:
            print("Invalid input:", e)

if __name__ == "__main__":
    main()


# set eth0 IPv4 using sudo ifconfig eth0 169.254.1.172 (or whatever fits the ip address on the master computer) netmask 255.255.0.0
