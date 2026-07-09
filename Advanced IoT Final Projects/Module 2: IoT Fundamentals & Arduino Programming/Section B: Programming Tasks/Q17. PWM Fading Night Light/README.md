# Q 17 – PWM Fading Night Light

## Project Information

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

# Problem Statement

Create an automatic night light that fades an LED in and out (breathing effect) continuously.

Implement three modes switchable via a push button:

1. **Slow Breathing** (3-second cycle)
2. **Fast Pulse** (0.5-second cycle)
3. **SOS Pattern** (... --- ...)

Display the current operating mode on the Serial Monitor.

---

# Project Overview

The PWM Fading Night Light demonstrates the use of Pulse Width Modulation (PWM) to control LED brightness and create smooth lighting effects. The LED automatically operates in different lighting modes, while a push button allows the user to switch between breathing, pulse, and SOS emergency signaling modes.

The project introduces PWM control, button interfacing, mode switching, Serial communication, and state management using Arduino UNO.

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Push Button | 1 |
| Jumper Wires | As Required |

---

# Pin Configuration

| Pin | Purpose |
|-----|---------|
| D9 | PWM LED Output |
| D2 | Push Button Input (INPUT_PULLUP) |
| GND | Common Ground |

---

# Circuit Connections

### LED Connection

- LED Anode (+) → Digital Pin **D9**
- LED Cathode (−) → **220Ω Resistor**
- Other end of Resistor → **GND**

The LED is connected to a PWM-supported pin so that its brightness can be varied smoothly.

### Push Button Connection

- One terminal → **Digital Pin D2**
- Other terminal → **GND**

The push button uses Arduino's internal pull-up resistor by configuring:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

Using **INPUT_PULLUP** eliminates the need for an external resistor and ensures stable button readings.

### Power Supply

- Arduino is powered through the USB cable.
- All components share a common ground.

---

# Features Implemented

- Automatic breathing LED effect
- Smooth PWM brightness control
- Slow breathing mode (3-second cycle)
- Fast pulse mode (0.5-second cycle)
- SOS Morse Code pattern
- Push button mode selection
- Serial Monitor mode indication
- Continuous operation
- Debounced button switching
- Arduino IDE compatible
- Wokwi compatible

---

# Working Principle

After power-up, the Arduino initializes the PWM output and Serial communication. The LED starts in Slow Breathing mode by gradually increasing and decreasing its brightness using PWM.

Whenever the push button is pressed, the operating mode changes sequentially:

- Slow Breathing
- Fast Pulse
- SOS Pattern

The current mode is immediately displayed on the Serial Monitor. The selected lighting effect continues until the button is pressed again.

---

# Program Flow

```text
                Start
                  │
                  ▼
      Initialize Arduino Pins
                  │
                  ▼
     Initialize Serial Monitor
                  │
                  ▼
      Set Default Mode (Mode 1)
                  │
                  ▼
        Check Push Button
                  │
      ┌───────────┴───────────┐
      ▼                       ▼
 Button Pressed?            No
      │                       │
      ▼                       │
 Change Mode                 │
      │                       │
      └───────────┬───────────┘
                  ▼
      Execute Selected Mode
                  │
                  ▼
      Display Mode on Serial
                  │
                  ▼
             Repeat Forever
```

---

# Project Structure

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

This Wokwi simulation demonstrates the complete implementation of the PWM Fading Night Light. It allows users to observe all three lighting modes, test push button mode switching, and monitor the active mode through the Serial Monitor in a virtual Arduino UNO environment.

**Project Link:**

https://wokwi.com/projects/469073682047197185

---

# Assets Included

### Hardware Screenshot

- PWM fading hardware setup.png

### Serial Monitor Screenshot

- PWM fading serial monitor.png

### Demonstration Video

- PWM Fading Demo.mp4

---

# Git Commit History

```text
feat: initialize Q17 PWM fading night light project
feat: implement slow breathing mode
feat: implement fast pulse mode
feat: implement SOS pattern mode
feat: add push button mode switching
feat: display current mode on Serial Monitor
docs: add project README
docs: add documentation
docs: upload hardware screenshot
docs: upload serial monitor screenshot
docs: upload demonstration video
```

---

# Learning Outcomes

- Learned PWM-based LED brightness control.
- Understood the breathing LED effect.
- Implemented multiple operating modes using state management.
- Interfaced a push button using INPUT_PULLUP.
- Generated SOS Morse code using LED blinking.
- Displayed real-time system information on the Serial Monitor.
- Improved understanding of embedded system programming.
- Practiced Arduino digital I/O and PWM programming.
- Developed event-driven user interaction using push buttons.

---

# Conclusion

The PWM Fading Night Light successfully demonstrates the practical implementation of PWM brightness control using Arduino UNO. The project combines smooth LED fading, multiple lighting modes, push button interaction, and Serial communication into a single embedded application. It provides a strong foundation for understanding PWM control, state-based programming, and user interface design in embedded and IoT systems.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
