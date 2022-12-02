import serial
import time

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)

""" Get arduino data """
def getArduinoData():
    while True:
        data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
        if data:
            print(data)

""" Main function """
def main():
    getArduinoData()
