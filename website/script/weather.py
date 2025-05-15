import serial
import re

ser = serial.Serial('/dev/ttyACM0', 9600)

try:
    while True:
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        match = re.search(r"Température\s*:\s*([\d.]+)\s*°C\s*Humidité\s*:\s*([\d.]+)\s*%", line)
        if match:
            temperature = match.group(1)
            humidity = match.group(2)
            print(f"Température : {temperature} °C | Humidité : {humidity} %")
            break

except KeyboardInterrupt:
    ser.close()
