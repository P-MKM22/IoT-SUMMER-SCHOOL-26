# Documentation of Question 17

# Project Information

| Field | Details |
|-------|---------|
| Project Title | PWM Fading Night Light |
| Question Number | Q17 |
| Module | Module 2: IoT Fundamentals & Arduino Programming |
| Section | Section B: Programming Tasks |
| Board | Arduino UNO |
| Programming Language | Arduino C/C++ |
| Development Environment | Arduino IDE |
| Simulation Platform | Wokwi |
| Repository | IoT-SUMMER-SCHOOL-26 |
| Date | July 2026 |

---

# Objective

To develop an automatic PWM-based night light using Arduino UNO that generates different lighting effects using Pulse Width Modulation (PWM). The project allows users to switch between Slow Breathing, Fast Pulse, and SOS modes using a push button while displaying the active mode on the Serial Monitor.

---

# Problem Statement

Create an automatic night light that fades an LED in and out (breathing effect) continuously.

Implement three modes switchable via a button:

1. **Slow Breathing (3-second cycle)**
2. **Fast Pulse (0.5-second cycle)**
3. **SOS Pattern (... --- ...)**

Display the current mode on the Serial Monitor.

---

# Components Required

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Push Button | 1 |
| Jumper Wires | As Required |

---

# Circuit Connections

## LED Connection

| LED Pin | Arduino Connection |
|---------|--------------------|
| Anode (+) | Digital Pin D9 (PWM) |
| Cathode (-) | 220Ω Resistor → GND |

The LED is connected to Digital Pin **D9**, which supports PWM. PWM allows the LED brightness to change smoothly, producing breathing and pulse lighting effects.

---

## Push Button Connection

| Push Button Pin | Arduino Connection |
|-----------------|--------------------|
| Terminal 1 | Digital Pin D2 |
| Terminal 2 | GND |

The push button changes the operating mode whenever it is pressed.

---

## INPUT_PULLUP

The button is configured using:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

Advantages:

- Eliminates the need for an external pull-up resistor.
- Keeps the input HIGH when the button is released.
- Reads LOW when the button is pressed.
- Provides stable and noise-free button readings.

---

## Power Connections

| Arduino Pin | Connection |
|-------------|------------|
| 5V | Supplies the circuit through USB |
| GND | Common Ground |

---

## Resistor

A **220Ω resistor** is connected in series with the LED to limit current and protect the LED from excessive current flow.

---

## Precautions

- Ensure the LED polarity is correct.
- Connect the resistor in series with the LED.
- Use only PWM-supported pin **D9**.
- Connect the push button correctly.
- Upload the correct Arduino sketch before testing.

---

# Software Requirements

- Arduino IDE 2.x or later
- Wokwi Online Simulator
- Arduino AVR Boards Package
- USB Driver (for physical Arduino UNO)

---

# Execution Procedure

## Step 1

Open **Arduino IDE** or **Wokwi**.

---

## Step 2

Create a new **Arduino UNO** project.

---

## Step 3

Add the following components:

- Arduino UNO
- Breadboard
- LED
- 220Ω Resistor
- Push Button

---

## Step 4

Connect the components according to the circuit connection table.

---

## Step 5

Copy and paste the Arduino program into the editor.

---

## Step 6

Compile (Verify) the program to check for compilation errors.

---

## Step 7

Upload the program to the Arduino UNO or start the Wokwi simulation.

---

## Step 8

Open the Serial Monitor.

Configure:

- Baud Rate: **9600**

---

## Step 9

Observe that the LED starts in **Slow Breathing Mode** by default.

The LED gradually fades from OFF to maximum brightness and back to OFF.

---

## Step 10

Press the push button once.

The LED changes to:

**Mode 2 – Fast Pulse**

The Serial Monitor displays:

```text
Mode 2 : Fast Pulse
```

---

## Step 11

Press the push button again.

The LED changes to:

**Mode 3 – SOS Pattern**

The LED blinks:

```text
... --- ...
```

The Serial Monitor displays:

```text
Mode 3 : SOS Pattern
```

---

## Step 12

Press the button again.

The Arduino returns to:

**Mode 1 – Slow Breathing**

The Serial Monitor displays:

```text
Mode 1 : Slow Breathing
```

---

## Step 13

Verify that:

- Button changes the operating mode.
- PWM fading is smooth.
- Fast Pulse operates correctly.
- SOS pattern follows Morse code.
- Serial Monitor displays the current mode correctly.

---

## Step 14

Capture screenshots of:

- Hardware setup
- Serial Monitor
- Working demonstration

Record the demonstration video for repository submission.

---

# Program Logic

1. Initialize Serial communication.
2. Configure the LED as PWM output.
3. Configure the push button using INPUT_PULLUP.
4. Start in Slow Breathing mode.
5. Continuously monitor the push button.
6. Change the operating mode whenever the button is pressed.
7. Execute the selected lighting pattern.
8. Display the active mode on the Serial Monitor.
9. Repeat continuously.

---

# Expected Output

The system should perform the following operations:

- LED smoothly fades in and out in Slow Breathing mode.
- LED rapidly fades in and out in Fast Pulse mode.
- LED blinks the SOS Morse code pattern (... --- ...).
- Each button press changes the operating mode.
- The current mode is displayed on the Serial Monitor.

---

# Files Included

```text
Q17. PWM Fading Night Light
│
├── Assets
│   ├── PWM fading hardware setup.png
│   ├── PWM fading serial monitor.png
│   └── PWM Fading Demo.mp4
│
├── Code
│   └── PWM_fading.ino
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

# Wokwi Simulation

This Wokwi simulation demonstrates the complete implementation of the PWM Fading Night Light using Arduino UNO. The simulation allows users to observe smooth PWM fading, switch between the three lighting modes using a push button, and monitor the active mode through the Serial Monitor.

**Project Link:**

https://wokwi.com/projects/469073682047197185

---

# Precautions

- Verify all wiring before powering the circuit.
- Connect the LED with the correct polarity.
- Use a 220Ω resistor with the LED.
- Use only PWM pin D9.
- Press the push button gently.
- Wait for the SOS sequence to finish before changing modes.
- Verify the program before uploading.

---

# Do's

- Verify the circuit connections.
- Test all three operating modes.
- Observe the Serial Monitor output.
- Save screenshots of successful execution.
- Record the demonstration video.
- Maintain proper wiring throughout testing.

---

# Don'ts

- Do not connect the LED without a resistor.
- Do not use a non-PWM pin for the LED.
- Do not disconnect the Arduino while uploading.
- Do not short the power pins.
- Do not press the button repeatedly during the SOS sequence.

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| LED does not glow | Incorrect LED polarity | Reverse the LED connections |
| LED brightness does not change | Connected to non-PWM pin | Connect LED to D9 |
| Button not working | Incorrect wiring | Verify D2 and GND connections |
| Mode does not change | Button not pressed correctly | Check INPUT_PULLUP wiring |
| No Serial output | Incorrect baud rate | Set Serial Monitor to 9600 baud |
| Compilation error | Missing or incorrect code | Verify and upload the correct sketch |

---

# Learning Outcomes

- Learned PWM-based LED brightness control.
- Understood the breathing LED effect.
- Implemented multiple operating modes.
- Learned push button interfacing using INPUT_PULLUP.
- Generated SOS Morse code using LED blinking.
- Displayed real-time system status on the Serial Monitor.
- Practiced Arduino PWM programming.
- Improved embedded system programming skills.
- Developed event-driven applications using Arduino.

---

# Conclusion

The PWM Fading Night Light project successfully demonstrates the practical use of Pulse Width Modulation for creating dynamic lighting effects with Arduino UNO. By integrating multiple operating modes, push button control, and Serial communication, the project provides hands-on experience with PWM programming, digital input handling, and embedded system design. It serves as an excellent example of implementing interactive lighting applications for IoT and embedded systems.
