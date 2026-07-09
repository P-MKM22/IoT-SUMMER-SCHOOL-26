# Q 18 – State Machine Implementation

## Project Information

| Field | Details |
|-------|---------|
| Project Title | State Machine Implementation |
| Question Number | Q18 |
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

Implement a simple vending machine state machine with four states:

- **IDLE**
- **COIN_INSERTED**
- **ITEM_SELECTED**
- **DISPENSING**

Use three buttons as inputs:

- Insert Coin
- Select Item
- Cancel

Use LEDs to indicate the current operating state and print every state transition to the Serial Monitor. The program must also include a comment block documenting the state transition diagram.

> **Note:** This implementation extends the basic requirement by using additional LEDs to provide a dedicated visual indication for the **ITEM_SELECTED** and **CANCELLED** states, improving system visualization while preserving the required state machine functionality.

---

# Project Overview

This project demonstrates the implementation of a Finite State Machine (FSM) for a vending machine using Arduino UNO. The vending machine progresses through different operational states based on button inputs. Each state is represented using LEDs, while every state transition is logged to the Serial Monitor.

The enhanced implementation includes dedicated LED indications for the Item Selected and Cancelled states, making the operation easier to understand during demonstration and testing.

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Blue LED | 1 |
| Green LED | 1 |
| White LED | 1 |
| 220Ω Resistors | 5 |
| Push Buttons | 3 |
| Jumper Wires | As Required |

---

# Pin Configuration

| Arduino Pin | Component | Function |
|-------------|-----------|----------|
| D8 | Red LED | IDLE State |
| D9 | Yellow LED | Coin Inserted |
| D10 | Blue LED | Item Selected |
| D11 | Green LED | Dispensing |
| D12 | White LED | Cancelled |
| D2 | Push Button | Insert Coin |
| D3 | Push Button | Select Item |
| D4 | Push Button | Cancel |

---

# Circuit Connections

## LED Connections

### Red LED

- Anode (+) → D8
- Cathode (−) → 220Ω Resistor → GND

Indicates the **IDLE** state.

### Yellow LED

- Anode (+) → D9
- Cathode (−) → 220Ω Resistor → GND

Indicates that a coin has been inserted.

### Blue LED

- Anode (+) → D10
- Cathode (−) → 220Ω Resistor → GND

Indicates that an item has been selected.

### Green LED

- Anode (+) → D11
- Cathode (−) → 220Ω Resistor → GND

Indicates the dispensing operation.

### White LED

- Anode (+) → D12
- Cathode (−) → 220Ω Resistor → GND

Indicates transaction cancellation.

---

## Push Button Connections

### Insert Coin Button

- One terminal → D2
- Other terminal → GND

### Select Item Button

- One terminal → D3
- Other terminal → GND

### Cancel Button

- One terminal → D4
- Other terminal → GND

---

## INPUT_PULLUP

All push buttons use Arduino's internal pull-up resistors.

```cpp
pinMode(buttonPin, INPUT_PULLUP);
```

Advantages:

- Eliminates external pull-up resistors.
- Stable digital input.
- Simplifies wiring.
- Reads LOW when pressed.

---

## Power Supply

- Arduino UNO powered through USB.
- All components share a common ground.

---

# Features Implemented

- Finite State Machine implementation
- Four vending machine states
- Insert Coin operation
- Item Selection
- Transaction Cancellation
- Automatic Dispensing
- Individual LED indication for each operating state
- Serial Monitor state transition logging
- Button debouncing
- Enhanced visual feedback
- Arduino IDE compatible
- Wokwi compatible

---

# Working Principle

Initially, the vending machine remains in the **IDLE** state with the red LED illuminated.

When the Insert Coin button is pressed, the system transitions to **COIN_INSERTED**, activating the yellow LED.

Pressing the Select Item button moves the machine into **ITEM_SELECTED**, where the blue LED indicates that an item has been selected.

At this stage, the user may either:

- Cancel the transaction, or
- Confirm dispensing.

During dispensing, the green LED remains ON while the machine simulates item delivery. Once dispensing is complete, the machine automatically returns to the IDLE state.

Whenever the transaction is cancelled, the white LED briefly indicates the cancellation before returning to the IDLE state.

Every transition is simultaneously displayed on the Serial Monitor.

---

# Program Flow

```text
                   Start
                     │
                     ▼
            Initialize Hardware
                     │
                     ▼
                IDLE State
                     │
             Insert Coin Button
                     │
                     ▼
            COIN_INSERTED State
              │             │
       Cancel │             │ Select Item
              ▼             ▼
            IDLE      ITEM_SELECTED
                           │       │
                    Cancel │       │ Confirm
                           ▼       ▼
                         IDLE   DISPENSING
                                   │
                                   ▼
                                 IDLE
```

---

# Project Structure

```text
Q18. State Machine Implementation
│
├── Assets
│   ├── State Machine Implementation hardware setup.png
│   ├── Insert coin in machine.png
│   ├── Item selected.png
│   ├── Item dispensing.png
│   ├── Item cancelled.png
│   └── State Machine Implementation demo.mp4
│
├── Code
│   └── State_machine_implementation.ino
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

# Wokwi Simulation

This Wokwi simulation demonstrates the complete implementation of the vending machine state machine using Arduino UNO. Users can simulate coin insertion, item selection, cancellation, and dispensing while observing LED state indicators and Serial Monitor state transitions.

**Project Link:**

https://wokwi.com/projects/469075815287370753

---

# Assets Included

### Hardware Screenshot

- State Machine Implementation hardware setup.png

### Operation Screenshots

- Insert coin in machine.png
- Item selected.png
- Item dispensing.png
- Item cancelled.png

### Demonstration Video

- State Machine Implementation demo.mp4

---

# Git Commit History

```text
feat: initialize Q18 vending machine state machine
feat: implement finite state machine logic
feat: add LED state indication
feat: implement item selection
feat: implement dispensing state
feat: implement transaction cancellation
feat: add Serial Monitor transition logging
docs: add project README
docs: add documentation
docs: upload hardware setup screenshot
docs: upload operation screenshots
docs: upload demonstration video
```

---

# Learning Outcomes

- Learned the concept of Finite State Machines (FSM).
- Implemented multiple operating states in Arduino.
- Controlled digital outputs using LEDs.
- Interfaced multiple push buttons using INPUT_PULLUP.
- Managed state transitions based on user input.
- Logged system events using the Serial Monitor.
- Improved embedded system programming skills.
- Understood event-driven programming concepts.
- Practiced hardware-software integration using Arduino.

---

# Conclusion

The State Machine Implementation project successfully demonstrates the practical application of Finite State Machine principles in embedded systems. By integrating multiple operating states, push button inputs, LED indicators, and Serial communication, the vending machine effectively simulates a real-world embedded control system. The enhanced LED visualization further improves usability and demonstrates scalable embedded system design techniques.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
