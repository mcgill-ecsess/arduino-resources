# Introduction to Arduino
> Made for Forge McGill 2025 - Hardware hackathon by The Factory

# Table of content
- [Joystick](./joystick/)
- [Motor Driver](./motor_driver/)

# Setup
- Arduino
  - An Arduino UNO (R3 or R4)
  - A usb cable (**R3**: type B to type A; **R4**: type C - type C)
- Joystick module(s)
- Motor driver (you will be given L9110 and/or L298N module)
- Jumper cables
- Screw driver

# Debug, Serial Monitor, etc.
- 

# Fancy stuff (for the advanced players)
## `arduino-cli`
- Create sketch
```sh
cd path/to/project/
arduino-cli sketch new SketchName
```

- Compile to AVR UNO board:
```sh
arduino-cli compile -b arduino:avr:uno SketchName
```

- Upload to UNO board:
```sh
arduino-cli upload -b arduino:avr:uno SketchName
```

- Install libraries
```sh
arduino-cli lib install LibraryName
```

