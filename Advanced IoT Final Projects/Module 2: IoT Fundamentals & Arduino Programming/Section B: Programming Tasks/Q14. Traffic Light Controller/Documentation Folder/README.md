# Documentation of Question 14

---

# Objective

The objective of this project is to design and simulate a **Traffic Light Controller** using an Arduino UNO that controls three LEDs representing the **Red**, **Yellow**, and **Green** traffic signals. The system also includes a **pedestrian crossing button**, which immediately switches the signal to **RED** for a fixed duration, allowing pedestrians to cross safely before resuming the normal traffic sequence.

---

# Problem Statement

Write an Arduino program that simulates a traffic light system using three LEDs (Red, Yellow, Green):

- RED ON for **5 seconds**
- YELLOW ON for **2 seconds**
- GREEN ON for **4 seconds**

Additional Requirements:

- Add a pedestrian push button on **Pin 7**
- When pressed, immediately force **RED**
- Hold RED for **8 seconds**
- Print the current light state with **timestamp (`millis()`)** on the Serial Monitor

---

# Project Requirements

The project satisfies the following requirements:

- Arduino UNO based traffic controller
- Three LEDs representing traffic signals
- Push button for pedestrian crossing
- Automatic traffic light sequencing
- Immediate RED override on button press
- 8-second pedestrian crossing duration
- Real-time Serial Monitor logging
- Wokwi simulator compatibility

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

# Software & Tools

- Arduino IDE
- Wokwi Online Simulator
- GitHub

---

# Libraries Used

No external libraries are required.

The project uses only Arduino's built-in functions.

---

# Circuit Connections

## Red LED

| LED Pin | Arduino Pin |
|----------|-------------|
| Anode (+) | D2 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## Yellow LED

| LED Pin | Arduino Pin |
|----------|-------------|
| Anode (+) | D3 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## Green LED

| LED Pin | Arduino Pin |
|----------|-------------|
| Anode (+) | D4 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## Push Button

| Button Pin | Arduino Connection |
|-------------|-------------------|
| Terminal 1 | +5V |
| Terminal 2 | Arduino Pin D7 |
| Pull-down | 10kΩ resistor to GND |

The pull-down resistor ensures the input remains LOW when the button is not pressed, preventing false triggering.

---

# Circuit Overview

```
Arduino UNO

D2 ───220Ω──► Red LED ───► GND

D3 ───220Ω──► Yellow LED ─► GND

D4 ───220Ω──► Green LED ──► GND


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

The Traffic Light Controller operates continuously in a cyclic manner.

### Normal Operation

1. RED LED turns ON for 5 seconds.
2. RED turns OFF and YELLOW turns ON for 2 seconds.
3. YELLOW turns OFF and GREEN turns ON for 4 seconds.
4. The cycle repeats continuously.

---

### Pedestrian Crossing

Whenever the push button is pressed:

- Current traffic sequence is interrupted immediately.
- RED signal becomes active.
- RED remains ON for 8 seconds.
- After 8 seconds, the controller automatically resumes the normal traffic sequence.

---

# Program Flow

```
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
Button Pressed?
   │        │
  No       Yes
   │        │
   │        ▼
   │    RED (8 sec)
   │        │
   └────────┘
        │
        ▼
Repeat Cycle
```

---

# Serial Monitor Output

Every traffic signal transition is displayed in the Serial Monitor.

Example:

```
[0 ms] RED

[5000 ms] YELLOW

[7000 ms] GREEN

[9000 ms] Pedestrian Request -> RED (8 sec)

Returning to Normal Traffic Cycle

[17000 ms] RED
```

The timestamp is generated using the `millis()` function.

---

# Wokwi Simulation

The project has been successfully simulated and tested using the Wokwi Online Simulator.

Simulation Link:

https://wokwi.com/projects/469047666148879361

---

# Testing Performed

The following test cases were successfully verified:

- Arduino startup
- RED LED operation
- YELLOW LED operation
- GREEN LED operation
- Automatic signal transition
- Push button detection
- Immediate RED override
- 8-second pedestrian hold
- Serial Monitor timestamp
- Continuous traffic cycle

---

# Expected Output

Normal Operation

```
RED
↓

YELLOW
↓

GREEN
↓

Repeat
```

Pedestrian Request

```
Button Pressed
↓

Immediate RED

↓

Hold for 8 Seconds

↓

Resume Normal Sequence
```

---

# Do's

- Verify all wiring before powering the Arduino.
- Use a 220Ω resistor with every LED.
- Use a 10kΩ pull-down resistor for the push button.
- Check LED polarity before simulation.
- Open the Serial Monitor to observe timestamps.
- Test each LED individually before running the complete program.
- Save the Wokwi project after successful simulation.

---

# Don'ts

- Do not connect LEDs directly without current-limiting resistors.
- Do not reverse LED polarity.
- Do not leave the push button input floating.
- Do not short the Arduino output pins.
- Do not disconnect components while the simulation is running.
- Do not modify pin assignments without updating the code.

---

# Troubleshooting

| Problem | Possible Solution |
|----------|------------------|
| LED not glowing | Check LED polarity and resistor connection |
| Wrong LED sequence | Verify pin assignments in the code |
| Push button not working | Check D7 connection and pull-down resistor |
| Serial Monitor blank | Ensure Serial Monitor is opened at 115200 baud |
| Random button triggering | Verify 10kΩ pull-down resistor connection |
| Wokwi simulation not running | Restart the simulation and verify all connections |

---

# Learning Outcomes

This project demonstrates practical implementation of:

- Arduino Programming
- Digital Output Control
- LED Interfacing
- Push Button Interfacing
- Traffic Signal Logic
- Event-Driven Programming
- Conditional Statements
- Timing Operations
- Serial Communication
- Embedded System Fundamentals

---

# Future Enhancements

- Four-way traffic intersection
- Automatic night mode
- Vehicle density detection
- Emergency vehicle priority
- LCD/OLED traffic status display
- IoT-enabled traffic monitoring
- Smart traffic optimization using sensors

---

# Conclusion

The Traffic Light Controller successfully simulates a real-world traffic signal using Arduino UNO. The project demonstrates digital output control, push button interfacing, timing operations, and event-driven programming. The pedestrian override feature enhances the functionality by providing a safe crossing mechanism while maintaining continuous traffic control. The project has been successfully verified through the Wokwi simulator and satisfies all the requirements specified in the problem statement.
