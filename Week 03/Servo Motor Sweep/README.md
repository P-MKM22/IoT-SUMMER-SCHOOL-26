# Servo Motor Sweep

## Overview

The **Servo Motor Sweep** project was completed during **Week 03** of the **IoT Summer School 2026**. It demonstrates actuator control using an **SG90 servo motor**, where the servo angle is controlled through a **10kΩ potentiometer**. A push button is also incorporated to perform an automatic servo sweep from **0° to 180° and back to 0°**.

The project introduces analog input processing, servo motor control, and user interaction, providing a practical understanding of actuator-based IoT applications.

---

## Key Features

- Servo angle control using a potentiometer.
- Analog value (0–1023) mapped to servo angle (0°–180°).
- Automatic servo sweep using a push button.
- Live display of potentiometer value and servo angle.
- Smooth and responsive servo movement.
- Compatible with Arduino Uno and Wokwi Simulator.

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| SG90 Servo Motor | 1 |
| 10kΩ Potentiometer | 1 |
| Push Button | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

## Software Requirements

- Arduino IDE
- Servo Library
- Wokwi Online Simulator

---

## Project Structure

```text
Week 03
│
└── Servo Motor Sweep
    │
    ├── Assets
    │   ├── Different servo angle(1).png
    │   ├── Different servo angle(2).png
    │   ├── Servo Motor Sweep hardware setup.png
    │   └── Servo Motor Sweep demo.mp4
    │
    ├── Code
    │   └── Servo_motor_sweep.ino
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## How It Works

The potentiometer acts as an analog input device whose value is continuously read by the Arduino. This value is converted into a corresponding servo angle using the `map()` function, allowing the servo motor to rotate smoothly between **0° and 180°**.

When the push button is pressed, the Arduino temporarily overrides manual control and commands the servo to perform one complete sweep across its full range before returning control to the potentiometer.

---

## Serial Monitor Output

```text
Potentiometer : 512 | Servo Angle : 90°
Potentiometer : 735 | Servo Angle : 129°
Potentiometer : 1023 | Servo Angle : 180°
```

---

## Project Assets

This project includes:

- Hardware setup image
- Servo angle demonstration images
- Working demonstration video
- Arduino source code
- Project documentation

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469196284053317633

The Wokwi simulation demonstrates manual servo control using the potentiometer and automatic sweeping using the push button. It also displays real-time potentiometer values and servo angles through the Serial Monitor.

---

## Applications

- Robotic Arm Control
- Camera Pan-Tilt Systems
- Smart Door Mechanisms
- Automated Positioning Systems
- Educational Robotics Projects
- Industrial Motion Control

---

## Skills Learned

- Servo motor interfacing
- Analog sensor reading
- ADC to angle mapping
- Push button interfacing
- Arduino Servo Library
- Real-time actuator control

---

## Possible Improvements

- Add an OLED/LCD to display the servo angle.
- Control the servo wirelessly using Bluetooth or Wi-Fi.
- Save preset servo positions in EEPROM.
- Support multiple servo motors.
- Replace the potentiometer with a joystick for two-axis control.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Servo Library Documentation
3. SG90 Servo Motor Datasheet
4. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
