# Spiderbot Project

## Overview
The Spiderbot project is designed to control a spider-like robot with multiple servos for movement and a camera. It allows users to send commands via Bluetooth to control the robot's movements and camera direction.

## Features
- Control 12 servos for leg movement
- Bluetooth connectivity for remote operation
- Ability to move forward, backward, turn, and control the camera

## Installation
1. Ensure you have the required libraries:
   - `Servo`
   - `SoftwareSerial`
2. Connect the servos to the appropriate PWM pins on the Arduino board.

## Usage
- Commands can be sent via Bluetooth to control the spiderbot:
  - 'F' to move forward
  - 'B' to move backward
  - 'L' to turn left
  - 'R' to turn right
  - 'U' to move the camera up
  - 'D' to move the camera down
  - 'S' to set all servos to a neutral position

## Authors
- Subhranil Baul

## License
This project is licensed under the MIT License.
