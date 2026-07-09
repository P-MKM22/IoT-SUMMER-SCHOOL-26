# Q 15 – Digital Piano using Buzzer

## Project Information

| Field | Details |
|-------|---------|
| **Project Title** | Digital Piano using Buzzer |
| **Question Number** | Q15 |
| **Module** | Module 2: IoT Fundamentals & Arduino Programming |
| **Section** | Section B: Programming Tasks |
| **Board** | Arduino UNO |
| **Programming Language** | Arduino C/C++ |
| **Simulation Platform** | Wokwi |
| **IDE** | Arduino IDE |
| **Repository** | IoT-SUMMER-SCHOOL-26 |
| **Date** | 01 July 2026 |

---

# Problem Statement

Build a **4-key musical instrument** using push buttons and a passive buzzer.

### Requirements

- Four buttons mapped to musical notes:
  - Do (262 Hz)
  - Re (294 Hz)
  - Mi (330 Hz)
  - Fa (349 Hz)
- Button press should play the assigned musical note.
- Button release should immediately silence the buzzer.
- If **two buttons are pressed simultaneously**, play **Sol (392 Hz)** as a chord substitute.
- Add a **5th push button** to switch between **Major** and **Minor** scales.
- Commit each feature separately using Git.

---

# Project Overview

The Digital Piano using Buzzer is an Arduino UNO-based musical instrument that demonstrates the generation of musical notes using digital inputs and a passive buzzer. Five push buttons are utilized, where four buttons generate individual musical notes and the fifth button is used to toggle between Major and Minor scales.

The Arduino continuously monitors the push buttons and produces the corresponding musical frequency using the `tone()` function. Whenever two or more musical keys are pressed simultaneously, the system automatically generates the **Sol (392 Hz)** note as a chord substitute. Releasing all buttons immediately stops the sound using the `noTone()` function.

The project was completely designed, simulated, and verified using the **Wokwi Online Simulator**.

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Passive Buzzer | 1 |
| Push Buttons | 5 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# Pin Configuration

| Arduino Pin | Component |
|-------------|-----------|
| D2 | Do Button |
| D3 | Re Button |
| D4 | Mi Button |
| D5 | Fa Button |
| D6 | Major / Minor Toggle Button |
| D8 | Passive Buzzer |
| GND | Common Ground |

---

# Musical Notes

## Major Scale

| Note | Frequency |
|------|----------:|
| Do | 262 Hz |
| Re | 294 Hz |
| Mi | 330 Hz |
| Fa | 349 Hz |

---

## Minor Scale

| Note | Frequency |
|------|----------:|
| Do | 200 Hz |
| Re | 250 Hz |
| Mi | 290 Hz |
| Fa | 330 Hz |

---

## Chord Substitute

Whenever **two or more musical buttons** are pressed simultaneously, the Arduino generates:

| Note | Frequency |
|------|----------:|
| Sol | 392 Hz |

---

# Features Implemented

- Four musical keys using push buttons.
- Major and Minor scale switching.
- Sol chord substitute for simultaneous key presses.
- Immediate buzzer stop on button release.
- Real-time button monitoring using INPUT_PULLUP.
- Serial Monitor status messages.
- Fully compatible with Wokwi simulator.
- Modular and well-commented Arduino program.

---

# Working Principle

1. Arduino continuously monitors all five push buttons.
2. Pressing any one musical key generates the assigned note.
3. Releasing the key immediately silences the buzzer.
4. If two or more musical buttons are pressed together, Sol (392 Hz) is generated.
5. Pressing the Mode button switches between Major and Minor scales.
6. The current mode is displayed in the Serial Monitor.
7. The process repeats continuously until the system is powered off.

---

# Program Flow

```
Start
   │
Initialize Arduino
   │
Configure Buttons
   │
Configure Passive Buzzer
   │
Read Push Buttons
   │
 ┌───────────────┐
 │Mode Button ?  │
 └──────┬────────┘
        │
Toggle Major / Minor
        │
Read Musical Keys
        │
 ┌──────────────────────┐
 │Two Keys Pressed ?    │
 └──────┬───────────────┘
        │Yes
        ▼
 Play Sol (392 Hz)
        │
        No
        ▼
Play Individual Note
        │
Button Released ?
        │
        ▼
Stop Buzzer
        │
Repeat
```

---

# Project Structure

```
Q15. Digital Piano using Buzzer
│
├── Code
│   └── digital_piano.ino
│
├── Assets
│   ├── Digital Piano Hardware setup.png
│   ├── Digital Piano Working demo.mp4
│   ├── Digital Piano major scale.png
│   └── Digital Piano minor scale.png
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

# Wokwi Simulation

**Project Link**

https://wokwi.com/projects/469052689987593217

The complete project was successfully simulated and verified using the Wokwi online simulator.

---

# Assets Included

The Assets folder contains:

- Digital Piano Hardware setup.png
- Digital Piano Working demo.mp4
- Digital Piano major scale.png
- Digital Piano minor scale.png

---

# Git Commit History

The project was committed separately for each implemented feature following Git version control best practices.

Example commit sequence:

```
feat: initialize digital piano project
feat: add Do Re Mi Fa note generation
feat: implement Sol chord substitute
feat: add major and minor mode toggle
feat: stop buzzer on key release
docs: add project README
docs: add documentation
docs: add project assets
```

---

# Learning Outcomes

Through this project, the following concepts were learned:

- Arduino Digital Input
- Push Button Interfacing
- Passive Buzzer Control
- tone() and noTone() Functions
- Musical Frequency Generation
- INPUT_PULLUP Configuration
- Multi-button Detection
- Conditional Programming
- Serial Communication
- Embedded System Programming
- Wokwi Circuit Simulation
- Git Version Control
- Technical Documentation

---

# Conclusion

The Digital Piano using Buzzer project successfully fulfills all the requirements specified in the problem statement. The system accurately generates musical notes using a passive buzzer, supports Major and Minor scale switching, detects simultaneous button presses to generate the Sol note as a chord substitute, and immediately silences the buzzer when no key is pressed. The project was successfully designed, simulated, tested, and documented using Wokwi, making it a complete demonstration of Arduino-based digital music generation and embedded system programming.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
