# Documentation of Q 25

## Servo Motor Sweep

### Overview

The **Servo Motor Sweep** project is developed as part of the **Advanced IoT Final Projects** under **Module 3: Sensors, Actuators & Data Acquisition**, **Section B: Actuator Control** during the **IoT and Drone Building Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

This project demonstrates the control of an **SG90 Servo Motor** using a **10kΩ Potentiometer**. The potentiometer position is mapped from **0–1023** to a servo angle of **0°–180°**. Additionally, a push button performs one complete servo sweep from **0° → 180° → 0°**, while the Serial Monitor displays the potentiometer value and corresponding servo angle.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Pin Configuration
- Circuit Configuration
- Working Principle
- Step-by-Step Implementation
- Serial Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- References
- Conclusion

---

## Project Structure

```text
Module 3: Sensors, Actuators & Data Acquisition
│
└── Section B: Actuator Control
    │
    └── Q25. Servo Motor Sweep
        │
        ├── Assets
        │   ├── .gitkeep
        │   ├── Different servo angle(1).png
        │   ├── Different servo angle(2).png
        │   ├── Servo Motor Sweep demo.mp4
        │   └── Servo Motor Sweep hardware setup.png
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

## Hardware Components

- Arduino Uno
- SG90 Servo Motor
- 10kΩ Potentiometer
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | D9 |
| Potentiometer | A0 |
| Push Button | D2 |

---

## Circuit Configuration

- Connect the **SG90 Servo Signal** pin to **Digital Pin 9**.
- Connect the **Potentiometer Output** pin to **Analog Pin A0**.
- Connect one terminal of the **Push Button** to **Digital Pin 2** and the other to **GND**.
- Connect all components to **5V** and **GND** with a common ground.

---

## Working Principle

The potentiometer generates an analog value between **0 and 1023**, which is mapped to a servo angle between **0° and 180°**. The servo continuously follows the potentiometer position.

When the push button is pressed, the servo temporarily performs one complete sweep from **0° to 180° and back to 0°** before returning to potentiometer control. The Serial Monitor displays the live potentiometer reading and servo angle.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno, SG90 Servo Motor, potentiometer, and push button according to the circuit configuration.

### Step 2: Initialize the Servo

Include the Servo library and attach the servo motor to **Digital Pin 9**.

### Step 3: Read Potentiometer Value

Read the analog value from the potentiometer connected to **A0**.

### Step 4: Map the Servo Angle

Convert the analog value (**0–1023**) into an angle (**0°–180°**) using the `map()` function.

### Step 5: Move the Servo

Rotate the servo according to the mapped angle.

### Step 6: Detect Button Press

Monitor the push button using the Arduino's internal **INPUT_PULLUP** resistor.

### Step 7: Execute Servo Sweep

When the button is pressed, rotate the servo from **0° → 180° → 0°**.

### Step 8: Display Output

Display the potentiometer value and servo angle on the Serial Monitor.

---

## Serial Output

```text
Potentiometer : 512 | Servo Angle : 90°
Potentiometer : 768 | Servo Angle : 135°
Potentiometer : 1023 | Servo Angle : 180°
```

---

## Code Explanation

- Initializes the Servo library.
- Reads analog input from the potentiometer.
- Maps the analog value to the servo angle.
- Controls the servo position in real time.
- Detects push button input.
- Performs an automatic servo sweep.
- Displays live values on the Serial Monitor.

---

## Software Concepts Used

- Servo Motor Control
- Analog Input Reading
- ADC Mapping
- Push Button Interfacing
- Serial Communication
- Arduino Servo Library

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Servo Motor Sweep hardware setup.png | Circuit connection |
| Different servo angle(1).png | Servo at different angle |
| Different servo angle(2).png | Additional servo position |
| Servo Motor Sweep demo.mp4 | Project demonstration video |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469196284053317633

**Description**

The simulation demonstrates real-time servo angle control using a potentiometer and an automatic sweep triggered by a push button. The Serial Monitor displays the potentiometer value and corresponding servo angle during operation.

---

## Learning Outcomes

- Servo motor interfacing
- Analog input processing
- Angle mapping using `map()`
- Push button interfacing
- Real-time actuator control
- Serial communication

---

## Best Practices

- Use a common ground for all components.
- Ensure a stable 5V power supply.
- Avoid forcing the servo beyond its limits.
- Verify all connections before uploading.
- Test the Serial Monitor after programming.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Servo Library Documentation
3. SG90 Servo Motor Datasheet
4. Arduino Language Reference
5. Wokwi Online Simulator – https://wokwi.com/

---

## Conclusion

The **Servo Motor Sweep** project demonstrates accurate actuator control using an SG90 servo motor, potentiometer, and push button. It provides practical experience in analog input processing, servo positioning, user interaction, and embedded programming, forming a strong foundation for robotics and IoT automation projects.
