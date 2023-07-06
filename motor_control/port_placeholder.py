import send_throttle
import time

send_throttle.open_port()
while True:
    time.sleep(1000)
