# Q 16 – Serial Command Interface

## Project Information

| Field | Details |
|-------|---------|
| Project Title | Serial Command Interface |
| Question Number | Q16 |
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

Write a program that receives commands over the Serial Monitor and controls hardware.

Required commands:

- **LED_ON** → Turn the built-in LED ON.
- **LED_OFF** → Turn the built-in LED OFF.
- **BLINK_X** → Blink the built-in LED **X** times (where **X = 1–9**).
- **STATUS** → Display the current LED state and blink counter.
- **RESET** → Reset the blink counter.

Implement input validation so that unknown commands print:

```
ERROR: Unknown command
```

---

# Project Overview

This project demonstrates serial communication between a computer and an Arduino UNO using the Serial Monitor. The Arduino continuously listens for user commands and performs different operations based on the received input.

The project introduces command parsing, serial communication, digital output control, input validation, and simple state management. A blink counter is maintained to keep track of the total number of LED blink operations performed.

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| USB Cable | 1 |

> **Note:** The project uses the Arduino UNO's built-in LED connected internally to Digital Pin 13.

---

# Pin Configuration

| Pin | Purpose |
|-----|---------|
| D13 (LED_BUILTIN) | Built-in LED |
| USB Serial | Serial Communication (9600 baud) |

---

# Circuit Connections

No external wiring is required.

The Arduino UNO already contains:

- Built-in LED connected to Digital Pin 13
- Built-in current limiting resistor
- USB interface for Serial communication

The USB cable is used for:

- Uploading the program
- Sending Serial commands
- Displaying Serial output

---

# Features Implemented

- Turn built-in LED ON
- Turn built-in LED OFF
- Blink LED from 1 to 9 times
- Maintain blink counter
- Display LED status
- Reset blink counter
- Validate Serial commands
- Handle invalid commands
- Simple command parser
- Continuous Serial communication

---

# Working Principle

1. Arduino initializes Serial communication at **9600 baud**.
2. The program continuously checks for incoming Serial data.
3. The received command is converted to uppercase and trimmed.
4. The command is compared against supported commands.
5. If the command is valid, the corresponding operation is executed.
6. If the command is invalid, an error message is displayed.
7. The system waits for the next command indefinitely.

---

# Program Flow

```text
              Start
                 │
                 ▼
        Initialize Serial
                 │
                 ▼
      Wait for Serial Command
                 │
                 ▼
        Read User Command
                 │
        ┌────────┴────────┐
        ▼                 ▼
   Valid Command?       Invalid
        │                 │
        ▼                 ▼
 Execute Function   Print Error Message
        │                 │
        └────────┬────────┘
                 ▼
      Wait for Next Command
```

---

# Project Structure

```
Q16. Serial Command Interface
│
├── Code
│   └── Q16_Serial_Command_Interface.ino
│
├── Assets
│   ├── Serial Interface Hardware setup.png
│   ├── LED ON command.png
│   ├── LED OFF command.png
│   ├── blink command.png
│   ├── blink command complete.png
│   ├── status command.png
│   ├── Reset command.png
│   ├── Unknown command.png
│   ├── Serial interfacing and hardware demo with commands.mp4
│   ├── Serial interfacing command execution demo part 01.mp4
│   └── Serial interfacing command execution demo part 02.mp4
│
├── Documentation
│
└── README.md
```

---

# Wokwi Simulation

**Project Link**

> *(Add your Wokwi project link here.)*

---

# Assets Included

### Hardware

- Serial Interface Hardware setup.png

### Screenshots

- LED ON command.png
- LED OFF command.png
- blink command.png
- blink command complete.png
- status command.png
- Reset command.png
- Unknown command.png

### Demonstration Videos

- Serial interfacing and hardware demo with commands.mp4
- Serial interfacing command execution demo part 01.mp4
- Serial interfacing command execution demo part 02.mp4

---

# Git Commit History

```text
feat: initialize Q16 serial command interface
feat: implement LED ON and LED OFF commands
feat: implement BLINK_X command
feat: add STATUS command
feat: implement RESET functionality
feat: validate unknown commands
docs: add project README
docs: add documentation
docs: upload screenshots
docs: upload demonstration videos
```

---

# Learning Outcomes

- Learned Serial communication using Arduino.
- Understood command-based user interaction.
- Implemented command parsing using String operations.
- Controlled digital outputs through Serial commands.
- Implemented input validation techniques.
- Managed program state using variables.
- Developed reusable command-processing logic.
- Improved debugging using the Serial Monitor.
- Learned practical implementation of embedded command interfaces.

---

# Conclusion

This project successfully implements a Serial Command Interface using the Arduino UNO. It allows users to control the built-in LED through simple text commands while maintaining system status and validating user input. The project demonstrates practical concepts of Serial communication, digital I/O control, command parsing, and embedded system programming, making it an effective introduction to interactive Arduino applications.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
