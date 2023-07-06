# python3 -i &
# echo "import serial" > /proc/$!/fd/0
# echo "ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600)"
#my_string='import serial
#ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600)
#while True:
#	pass'
# my_string = 'import serial; ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600); input("");'
#echo $my_string | python3 -i
echo '
import serial
ser = serial.Serial("/dev/serial/by-id/usb-MBED_MBED_CMSIS-DAP_10107ee87189b1060027e1cf3deb984576d1-if01", baudrate=9600)
while True:
	pass' | python3 -i &
