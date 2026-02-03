# Ultrasonic Distance Sensor — Arduino UNO R4 WiFi

Project to measure distance using an ultrasonic sensor (e.g., HC-SR04) with an Arduino `uno_r4_wifi` board.

## Files
- `src/main.cpp` — Arduino sketch: triggers the ultrasonic sensor, measures echo pulse width, converts to distance (cm), and prints to Serial.
- `platformio.ini` — PlatformIO configuration: board, framework, serial ports, and monitor speed.

## Hardware
- Board: Arduino UNO R4 WiFi (`uno_r4_wifi`)
- Ultrasonic sensor: HC-SR04 (or compatible)

Wiring:
- VCC -> 5V
- GND -> GND
- Trig -> Digital pin `9`
- Echo -> Digital pin `10`

> Ensure the echo voltage level is safe for the board. UNO R4 WiFi is compatible with typical HC-SR04 signals, but follow sensor and board datasheets.

## Software / Configuration
`platformio.ini` includes:
- platform = `renesas-ra`
- board = `uno_r4_wifi`
- framework = `arduino`
- monitor_speed = `9600`
- upload_port = `COM9`
- monitor_port = `COM9`

## Build & Upload (PlatformIO)
From project root (Windows / CLion Terminal):

- Build:  
  `pio run -e uno_r4_wifi`

- Upload:  
  `pio run -e uno_r4_wifi -t upload`

- Open Serial Monitor (9600 baud):  
  `pio device monitor -p COM9 -b 9600`  
  or use the built-in CLion / PlatformIO serial monitor set to `COM9` and `9600`.

## Behavior
- The sketch sends a 10 µs trigger pulse on pin `9`, measures the echo pulse on pin `10`, converts time to distance using the speed of sound, and prints `distance :<value> cm` every second.

## Troubleshooting
- No serial output: verify `COM9` and board selection, check USB connection.
- Incorrect distances: verify wiring, sensor orientation, and that nothing too close (<2 cm) or too far (>~400 cm).
- Pin conflicts: ensure other shields or code do not use pins `9` and `10`.

## License
Specify your project license (e.g., MIT) by adding a `LICENSE` file.
