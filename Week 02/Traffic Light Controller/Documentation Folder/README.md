# Documentation of Traffic Light Controller

---

# Objective

The objective of this project is to design, simulate, and implement a **Traffic Light Controller** using an Arduino UNO that controls three LEDs representing the **Red**, **Yellow**, and **Green** traffic signals. The system also integrates a **pedestrian push button** that immediately interrupts the normal traffic sequence, activates the RED signal for a fixed duration, and then resumes the normal operation.

The project demonstrates the fundamentals of Arduino programming, digital output control, push-button interfacing, timing operations, and event-driven programming.

---

# Problem Statement

Write an Arduino program that simulates a traffic light system using **three LEDs**:

- RED ON for **5 seconds**
- YELLOW ON for **2 seconds**
- GREEN ON for **4 seconds**

Additional Requirements:

- Add a pedestrian push button on **Arduino Pin 7**
- When the button is pressed, immediately force the RED signal
- Hold RED for **8 seconds**
- Print the active traffic light state along with the current timestamp (`millis()`) on the Serial Monitor

---

# Project Requirements

The implemented project satisfies all the given requirements:

- Arduino UNO based implementation
- Three LED traffic light simulation
- Pedestrian push button support
- Automatic traffic signal sequencing
- Immediate RED signal override
- 8-second pedestrian crossing mode
- Serial Monitor logging with timestamps
- Wokwi simulation compatible

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| Push Button | 1 |
| 220Ω Resistors | 3 |
| 10kΩ Pull-down Resistor | 1 |
| Jumper Wires | As Required |

---

# Software & Development Tools

- Arduino IDE
- Wokwi Online Simulator
- GitHub

---

# Libraries Used

No external libraries are required.

The project uses only the built-in Arduino framework.

---

# Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Red LED | D2 |
| Yellow LED | D3 |
| Green LED | D4 |
| Push Button | D7 |

---

# Circuit Connections

## 1. Red LED

- Arduino Pin **D2**
- 220Ω Resistor
- Red LED Anode (+)
- LED Cathode (-) → GND

---

## 2. Yellow LED

- Arduino Pin **D3**
- 220Ω Resistor
- Yellow LED Anode (+)
- LED Cathode (-) → GND

---

## 3. Green LED

- Arduino Pin **D4**
- 220Ω Resistor
- Green LED Anode (+)
- LED Cathode (-) → GND

---

## 4. Push Button

One terminal of Push Button

→ **+5V**

Second terminal

→ **Arduino Pin D7**

→ **10kΩ Pull-down Resistor**

→ **GND**

The pull-down resistor ensures that Pin D7 remains LOW whenever the push button is not pressed, preventing false triggering.

---

# Circuit Overview

```text
                Arduino UNO

D2 ───220Ω────► RED LED ─────► GND

D3 ───220Ω────► YELLOW LED ──► GND

D4 ───220Ω────► GREEN LED ───► GND


                  +5V
                   │
             Push Button
                   │
                  D7
                   │
                10kΩ
                   │
                  GND
```

---

# Working Principle

The Traffic Light Controller continuously follows a predefined traffic signal sequence.

### Normal Traffic Sequence

1. RED LED remains ON for **5 seconds**.
2. RED turns OFF and YELLOW turns ON for **2 seconds**.
3. YELLOW turns OFF and GREEN turns ON for **4 seconds**.
4. The sequence repeats continuously.

---

### Pedestrian Crossing

Whenever the pedestrian push button is pressed:

- The current traffic sequence is interrupted immediately.
- The RED signal turns ON instantly.
- RED remains active for **8 seconds**.
- After completion, the controller resumes the normal traffic sequence.

---

# Program Flow

```text
Power ON
    │
    ▼
Initialize Pins
    │
    ▼
RED (5 sec)
    │
    ▼
YELLOW (2 sec)
    │
    ▼
GREEN (4 sec)
    │
    ▼
Pedestrian Button Pressed?
       │
   ┌───┴───┐
   │       │
  NO      YES
   │       │
   │       ▼
   │   RED (8 sec)
   │       │
   └───────┘
       │
       ▼
Repeat Cycle
```

---

# Implementation Steps

### Step 1

Create a new Arduino UNO project in the Wokwi Simulator.

---

### Step 2

Add the following components:

- Arduino UNO
- Breadboard
- Red LED
- Yellow LED
- Green LED
- Push Button
- Three 220Ω resistors
- One 10kΩ pull-down resistor

---

### Step 3

Connect each LED to the assigned Arduino pin through a 220Ω resistor.

---

### Step 4

Connect the push button to Arduino Pin D7 using a 10kΩ pull-down resistor.

---

### Step 5

Upload the Arduino program (`traffic_light.ino`) into the Wokwi project.

---

### Step 6

Start the simulation.

---

### Step 7

Observe the traffic light sequence:

- RED
- YELLOW
- GREEN

---

### Step 8

Open the Serial Monitor to verify that each traffic light state is printed with its timestamp.

---

### Step 9

Press the push button while the simulation is running.

The system should:

- Interrupt the current signal
- Switch immediately to RED
- Keep RED ON for 8 seconds
- Resume the normal sequence

---

### Step 10

Verify that all screenshots and demonstration videos are captured successfully.

---

# Serial Monitor Output

Example Output

```text
Traffic Light Controller Started

[0 ms] RED

[5000 ms] YELLOW

[7000 ms] GREEN

[9000 ms] Pedestrian Request -> RED (8 sec)

Returning to Normal Traffic Cycle

[17000 ms] RED
```

---

# Wokwi Simulation

The complete project has been designed, simulated, and tested using the Wokwi Online Simulator.

**Simulation Link**

https://wokwi.com/projects/469047666148879361

---

# Testing Performed

The following test cases were successfully verified:

- Arduino startup
- RED signal operation
- YELLOW signal operation
- GREEN signal operation
- Automatic traffic sequencing
- Push button detection
- Immediate RED override
- 8-second pedestrian crossing
- Serial Monitor timestamp logging
- Continuous traffic cycle

---

# Do's

- Verify all circuit connections before simulation.
- Use a 220Ω resistor with every LED.
- Use a 10kΩ pull-down resistor with the push button.
- Check LED polarity before powering the circuit.
- Keep the Serial Monitor open during testing.
- Test each LED individually before running the complete project.
- Save the Wokwi project after successful verification.

---

# Don'ts

- Do not connect LEDs directly to Arduino pins without resistors.
- Do not reverse LED polarity.
- Do not leave the push button input floating.
- Do not short any Arduino pins.
- Do not modify pin assignments without updating the code.
- Do not disconnect components while the simulation is running.

---

# Troubleshooting Guide

| Issue | Possible Solution |
|--------|-------------------|
| LED not glowing | Verify LED polarity and resistor connections |
| Wrong LED sequence | Check Arduino pin assignments in the code |
| Push button not responding | Verify D7 connection and pull-down resistor |
| Random button activation | Ensure the 10kΩ resistor is connected correctly |
| Serial Monitor shows nothing | Confirm baud rate is 115200 |
| Simulation not starting | Verify all component connections in Wokwi |

---

# Learning Outcomes

Through this project, the following concepts were successfully learned:

- Arduino Programming
- Digital Output Control
- LED Interfacing
- Push Button Interfacing
- Timing Operations
- Event-Driven Programming
- Conditional Statements
- Serial Communication
- Traffic Signal Logic
- Embedded System Fundamentals

---

# Future Enhancements

The project can be extended with:

- Four-way traffic intersection
- Vehicle density detection using sensors
- Emergency vehicle priority system
- LCD/OLED status display
- IoT-based traffic monitoring
- Automatic night mode
- Solar-powered traffic controller
- Smart traffic optimization using AI

---

# Conclusion

The Traffic Light Controller successfully fulfills all the requirements specified in the problem statement. The system accurately simulates a real-world traffic signal using three LEDs while providing a safe pedestrian crossing mechanism through an immediate RED signal override. The project demonstrates digital output control, timing operations, push-button interfacing, and Serial Monitor logging, making it an excellent introductory embedded systems application. The implementation has been thoroughly verified using the Wokwi Simulator and serves as a strong foundation for more advanced smart traffic management systems.
