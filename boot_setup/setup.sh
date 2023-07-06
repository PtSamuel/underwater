#!/bin/bash
echo "Configuring eth1 ip..."
echo "123456" | sudo -S ip addr flush dev eth0
sudo ip addr flush dev eth1
sudo ifconfig eth1 169.254.1.172 netmask 255.255.0.0

echo "Setting up can0..."
sudo modprobe mttcan
sudo ip link set can0 type can bitrate 50000
if [ $? -eq 0]; then
  echo "can0 set up successfully."
else
  echo "can0 set up failure."
fi
sudo ip link set can0 up

echo "Setting up wifi..."
cd ~/create_ap
sudo make install
sudo create_ap wlan0 eth0 WaterJetson thisisstupid &

echo "Setting up serial port placeholder..."
sudo chmod a+rw /dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01
# ~/Desktop/underwater/motor_control/port_placeholder.sh
echo '
import serial
ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600)
while True:
	pass' | python3 -i & >> ~/Desktop/underwater/boot_setup/log.txt
