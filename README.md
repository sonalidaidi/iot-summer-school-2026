# LED Blink

## Project Title
LED Blink using Arduino

## Hardware Required
- Arduino Uno / ESP32
- USB Cable
- LED 
- Potentiometer 

## Circuit Diagram Description
The LED is connected to digital pin 13. If a potentiometer is used, connect one terminal to 5V, one to GND, and the middle terminal to an ADC pin on ESP32.

## How to Upload Code
1. Connect the board to the computer using a USB cable.
2. Open the Arduino IDE.
3. Select the correct board and COM port.
4. Open the `led_blink.ino` file.
5. Click **Verify** to compile the code.
6. Click **Upload** to flash the program to the board.
7. Open the Serial Monitor to view the blink count.

## Expected Output
- The built-in LED blinks every 500 ms.
- The Serial Monitor displays the blink count.
- If a potentiometer is connected, turning it changes the blink speed.

## Troubleshooting Tips
1. Check that the correct board and COM port are selected.
2. Ensure the USB cable supports data transfer.
3. Verify all circuit connections before uploading the code.
