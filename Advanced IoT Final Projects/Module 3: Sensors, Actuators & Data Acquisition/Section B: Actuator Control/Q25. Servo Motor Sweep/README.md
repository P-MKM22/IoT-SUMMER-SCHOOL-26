# Q 25 – Servo Motor Sweep

## Overview

The **Servo Motor Sweep** project is a part of the **Advanced IoT Final Projects** under **Module 3: Sensors, Actuators & Data Acquisition**, **Section B: Actuator Control**. This project demonstrates precise actuator control by combining analog input from a potentiometer with manual control through a push button.

The potentiometer allows the user to position the **SG90 servo motor** anywhere between **0° and 180°**, while the push button executes an automatic sweep from **0° → 180° → 0°**. The project highlights the practical use of analog-to-angle mapping, real-time actuator control, and user interaction in embedded systems.

---

## Project Highlights

- Real-time servo control using a potentiometer.
- Servo angle mapped from **0–1023** analog input to **0°–180°**.
- Push button initiates one complete automatic servo sweep.
- Live monitoring of potentiometer values and servo angle through the Serial Monitor.
- Simple and responsive actuator control using the Arduino Servo Library.
- Compatible with Arduino Uno and the Wokwi Simulator.

---

## Hardware Used

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
Q25. Servo Motor Sweep
│
├── Assets
│   ├── .gitkeep
│   ├── Different servo angle(1).png
│   ├── Different servo angle(2).png
│   ├── Servo Motor Sweep hardware setup.png
│   └── Servo Motor Sweep demo.mp4
│
├── Code
│   └── Servo_Control.ino
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

## System Overview

The Arduino continuously reads the potentiometer's analog output and converts it into a corresponding servo angle. As the potentiometer rotates, the servo motor responds instantly by moving to the mapped position.

The push button adds an additional operating mode by commanding the servo to perform a complete sweep across its entire range before returning control to the potentiometer. During operation, the Serial Monitor displays both the potentiometer reading and the calculated servo angle, allowing easy observation of the mapping process.

---

## Serial Monitor Output

```text
Potentiometer : 512 | Servo Angle : 90°
Potentiometer : 768 | Servo Angle : 135°
Potentiometer : 1023 | Servo Angle : 180°
```

---

## Project Assets

The repository contains:

- Hardware setup image
- Servo angle demonstration images
- Working demonstration video
- Arduino source code
- Complete technical documentation

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469196284053317633

The simulation demonstrates smooth servo positioning using a potentiometer and automatic sweep functionality triggered by a push button. It also verifies the real-time mapping of analog input values to servo angles through the Serial Monitor.

---

## Applications

- Robotic Arm Positioning
- Camera Pan-Tilt Mechanisms
- Automated Door Systems
- Smart Lock Mechanisms
- Industrial Actuator Control
- Educational Robotics Projects

---

## Learning Outcomes

- Servo motor interfacing with Arduino
- Analog input processing
- Angle mapping using the `map()` function
- Push button interfacing
- Actuator control techniques
- Real-time Serial communication

---

## Future Enhancements

- Add LCD/OLED display for angle indication.
- Integrate Bluetooth or Wi-Fi for wireless control.
- Store preset servo positions in EEPROM.
- Control multiple servo motors simultaneously.
- Develop a joystick-based servo control system.
- Integrate with robotic arm applications.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Servo Library Documentation
3. SG90 Servo Motor Datasheet
4. Arduino Language Reference
5. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
