#!/usr/bin/python
import serial

s = serial.Serial()
s.port = "/dev/ttyUSB0"
s.baudrate = 115200
s.timeout = 2

s.open()

while True:
    l = s.read(1024)
    for i in range(len(l)):
        print "%02x "%ord(l[i])
