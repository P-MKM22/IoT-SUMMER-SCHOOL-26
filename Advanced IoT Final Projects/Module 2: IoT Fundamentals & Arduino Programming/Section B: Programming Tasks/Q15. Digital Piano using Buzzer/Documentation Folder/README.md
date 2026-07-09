# Documentation of Question 15

---

# Project Information

| Field | Details |
|-------|---------|
| **Question Number** | Q15 |
| **Project Title** | Digital Piano using Buzzer |
| **Module** | Module 2: IoT Fundamentals & Arduino Programming |
| **Section** | Section B: Programming Tasks |
| **Board** | Arduino UNO |
| **Programming Language** | Arduino C/C++ |
| **Simulation Platform** | Wokwi |
| **IDE** | Arduino IDE / Wokwi |

---

# Objective

The objective of this project is to design and simulate a simple Digital Piano using an Arduino UNO, five push buttons, and a passive buzzer. The system should generate musical notes based on button presses, switch between Major and Minor scales, detect simultaneous button presses, and play a substitute chord note while demonstrating the use of digital inputs and sound generation using Arduino.

---

# Problem Statement

Develop a 4-key musical instrument using push buttons and a passive buzzer with the following functionalities:

- Play **Do (262 Hz)**, **Re (294 Hz)**, **Mi (330 Hz)**, and **Fa (349 Hz)** using four push buttons.
- Stop the sound immediately when the button is released.
- Play **Sol (392 Hz)** whenever two or more musical buttons are pressed simultaneously.
- Add a fifth push button to toggle between Major and Minor scales.
- Maintain separate Git commits for each implemented feature.

---

# Components Required

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Passive Buzzer | 1 |
| Push Buttons | 5 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# Circuit Connections

## Push Buttons

| Button | Arduino Pin | Other Terminal |
|---------|-------------|----------------|
| Do | D2 | GND |
| Re | D3 | GND |
| Mi | D4 | GND |
| Fa | D5 | GND |
| Major / Minor Toggle | D6 | GND |

> **Note:** The program uses the Arduino's internal `INPUT_PULLUP` resistor. Therefore, external pull-up or pull-down resistors are not required.

---

## Passive Buzzer

| Buzzer Pin | Arduino |
|------------|---------|
| Positive (+) | D8 |
| Negative (-) | GND |

---

# Software Requirements

- Arduino IDE (for physical hardware)
- Wokwi Online Simulator
- Git & GitHub (for version control)

---

# Execution Procedure

## Step 1 — Create the Circuit

1. Open Wokwi.
2. Create a new Arduino UNO project.
3. Add:
   - Arduino UNO
   - Passive Buzzer
   - Five Push Buttons
4. Arrange the components neatly on the workspace.

---

## Step 2 — Connect the Components

- Connect the buzzer positive terminal to **Digital Pin D8**.
- Connect the buzzer negative terminal to **GND**.
- Connect one terminal of every push button to its assigned digital pin.
- Connect the opposite terminal of every push button to **GND**.

---

## Step 3 — Upload the Program

1. Open **digital_piano.ino**.
2. Copy the complete Arduino program.
3. Paste it into the Arduino editor.
4. Save the sketch.
5. Start the simulation.

---

## Step 4 — Verify the Operation

Perform the following tests:

### Test 1 — Individual Notes

Press each musical button individually.

Expected Result:

- Do → 262 Hz
- Re → 294 Hz
- Mi → 330 Hz (Major)
- Fa → 349 Hz

The buzzer should immediately stop when the button is released.

---

### Test 2 — Major / Minor Mode

Press the Mode button.

Expected Result:

- The system switches between Major and Minor scales.
- The Serial Monitor displays the currently selected mode.

---

### Test 3 — Chord Substitute

Press two or more musical buttons simultaneously.

Expected Result:

- The buzzer should generate the Sol note (392 Hz).

---

### Test 4 — Continuous Operation

Operate the piano repeatedly.

Expected Result:

- Notes should play correctly without system crashes.
- The buzzer should stop immediately when no key is pressed.

---

# Program Logic

The Arduino continuously monitors the state of all push buttons using digital inputs configured with `INPUT_PULLUP`.

Whenever a button is pressed:

- The corresponding musical frequency is selected.
- The `tone()` function generates the sound.
- Releasing all buttons immediately calls `noTone()` to stop the buzzer.

If the Mode button is pressed:

- The program toggles between Major and Minor scales.
- Future note frequencies are selected from the active scale.

If two or more note buttons are pressed simultaneously:

- The program ignores the individual notes.
- The Sol note (392 Hz) is generated instead.

---

# Expected Output

- Individual button presses produce the assigned musical notes.
- Releasing buttons immediately silences the buzzer.
- Simultaneous key presses generate the Sol note.
- Mode switching changes the active musical scale.
- Serial Monitor displays system status and selected scale.

---

# Files Included

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

Project Link:

https://wokwi.com/projects/469052689987593217

---

# Precautions

- Use a **Passive Buzzer**, not an Active Buzzer.
- Verify all digital pin connections before simulation.
- Ensure the buzzer polarity is correct.
- Keep all GND connections common.
- Do not modify the assigned pin numbers without updating the code.
- Use `INPUT_PULLUP` exactly as implemented in the program.

---

# Do's

- Verify every connection before starting the simulation.
- Save the sketch before execution.
- Monitor the Serial Monitor for debugging.
- Press the Mode button once to change scales.
- Test every button individually before testing multiple-button operation.

---

# Don'ts

- Do not connect the buzzer directly to 5V.
- Do not use an Active Buzzer.
- Do not remove the common ground connection.
- Do not change pin assignments without updating the program.
- Do not press the Mode button continuously; use a single press to toggle.

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|----------|----------------|----------|
| No sound from buzzer | Incorrect wiring | Verify buzzer connections |
| Continuous sound | Button stuck or wiring issue | Check push button orientation |
| Wrong note generated | Incorrect pin mapping | Verify digital pin assignments |
| Mode does not change | Toggle button not connected correctly | Verify D6 connection |
| Sol note not detected | Wokwi limitation with simultaneous mouse clicks | Assign keyboard shortcuts to buttons or use keyboard controls |

---

# Learning Outcomes

After completing this project, the following concepts were understood:

- Digital Input Handling
- Push Button Interfacing
- Passive Buzzer Operation
- Musical Frequency Generation
- tone() and noTone() Functions
- INPUT_PULLUP Configuration
- Multi-button Detection
- Conditional Programming
- Serial Communication
- Embedded System Development
- Wokwi Circuit Simulation
- Git Version Control
- Technical Documentation

---

# Conclusion

The Digital Piano using Buzzer project successfully demonstrates the generation of musical notes using Arduino digital inputs and a passive buzzer. The system fulfills all the required functionalities, including note generation, Major/Minor scale switching, chord substitution using simultaneous key presses, and immediate sound termination on button release. The project was successfully simulated using Wokwi and documented following standard engineering practices.
