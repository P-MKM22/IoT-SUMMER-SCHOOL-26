# Documentation of Question 18

# Project Information

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

# Objective

To design and implement a Finite State Machine (FSM) for a vending machine using Arduino UNO. The project demonstrates state-based programming by controlling LEDs through user inputs, handling state transitions, and displaying all transitions on the Serial Monitor.

---

# Problem Statement

Implement a simple vending machine state machine with **4 states**:

- **IDLE**
- **COIN_INSERTED**
- **ITEM_SELECTED**
- **DISPENSING**

Use **3 buttons** as inputs:

- Insert Coin
- Select Item
- Cancel

Use LEDs to indicate the current operating state and print every state transition to the Serial Monitor. The program must include a comment block documenting the state transition diagram.

---

# Components Required

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

# Circuit Connections

## LED Connections

| LED | Arduino Pin | Purpose |
|-----|-------------|---------|
| Red LED | D8 | IDLE State |
| Yellow LED | D9 | COIN_INSERTED State |
| Blue LED | D10 | ITEM_SELECTED State |
| Green LED | D11 | DISPENSING State |
| White LED | D12 | CANCELLED Indication |

Each LED is connected in series with a **220Ω resistor** before connecting to **GND** to limit current and protect the LED.

---

## Push Button Connections

| Push Button | Arduino Pin |
|-------------|-------------|
| Insert Coin | D2 |
| Select Item | D3 |
| Cancel | D4 |

Each push button has:

- One terminal connected to the Arduino digital pin.
- The other terminal connected to **GND**.

---

## INPUT_PULLUP Configuration

All buttons are configured using:

```cpp
pinMode(buttonPin, INPUT_PULLUP);
```

Advantages:

- No external pull-up resistor required.
- Stable input readings.
- Default input remains HIGH.
- Reads LOW when the button is pressed.

---

## Power Connections

| Arduino Pin | Connection |
|-------------|------------|
| 5V | Arduino USB Power |
| GND | Common Ground for all LEDs and Push Buttons |

---

## Precautions

- Connect every LED with the correct polarity.
- Use one 220Ω resistor for each LED.
- Verify push button wiring before powering the circuit.
- Ensure all components share a common ground.
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
- Five LEDs
- Five 220Ω Resistors
- Three Push Buttons

---

## Step 4

Connect all LEDs and push buttons according to the circuit connection table.

---

## Step 5

Copy and paste the Arduino program into the editor.

---

## Step 6

Compile (Verify) the program to ensure there are no compilation errors.

---

## Step 7

Upload the program to the Arduino UNO or start the Wokwi simulation.

---

## Step 8

Open the **Serial Monitor** and set the baud rate to:

```text
9600
```

---

## Step 9

Observe the initial state.

Expected output:

- Red LED ON
- Serial Monitor:

```text
Current State : IDLE
```

---

## Step 10

Press the **Insert Coin** button.

Expected result:

- Yellow LED ON
- Serial Monitor displays:

```text
Transition : IDLE -> COIN_INSERTED
```

---

## Step 11

Press the **Select Item** button.

Expected result:

- Blue LED ON (or blinking if implemented)
- Serial Monitor displays:

```text
Transition : COIN_INSERTED -> ITEM_SELECTED
```

---

## Step 12

Choose one of the following operations:

### Option 1 – Confirm Purchase

Press the confirmation button.

Expected output:

```text
Transition : ITEM_SELECTED -> DISPENSING
Dispensing Item...
Item Dispensed
Transition : DISPENSING -> IDLE
```

Green LED remains ON during dispensing before returning to the Red LED.

---

### Option 2 – Cancel Transaction

Press the **Cancel** button.

Expected output:

```text
Transition : ITEM_SELECTED -> CANCELLED
Transaction Cancelled
Transition : CANCELLED -> IDLE
```

White LED briefly indicates cancellation before returning to the Red LED.

---

## Step 13

Repeat the process multiple times to verify correct state transitions.

---

## Step 14

Capture the following project assets:

- Hardware setup screenshot
- Insert coin screenshot
- Item selected screenshot
- Item dispensing screenshot
- Item cancelled screenshot
- Demonstration video

---

# Program Logic

1. Initialize Serial communication.
2. Configure LEDs as digital outputs.
3. Configure push buttons using INPUT_PULLUP.
4. Enter the IDLE state after startup.
5. Wait for the Insert Coin button.
6. Move to COIN_INSERTED state.
7. Wait for either Select Item or Cancel.
8. Enter ITEM_SELECTED after selecting an item.
9. Allow confirmation or cancellation.
10. Dispense the item if confirmed.
11. Return to IDLE after dispensing or cancellation.
12. Print every state transition to the Serial Monitor.
13. Repeat continuously.

---

# Expected Output

The vending machine should perform the following sequence:

- Red LED indicates IDLE.
- Yellow LED indicates COIN_INSERTED.
- Blue LED indicates ITEM_SELECTED.
- Green LED indicates DISPENSING.
- White LED indicates transaction cancellation.
- Every state transition appears on the Serial Monitor.
- The machine always returns to IDLE after dispensing or cancellation.

---

# Files Included

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

This Wokwi simulation demonstrates the complete implementation of the vending machine finite state machine using Arduino UNO. Users can simulate coin insertion, item selection, transaction cancellation, and item dispensing while observing LED state indicators and Serial Monitor transition messages.

**Project Link:**

https://wokwi.com/projects/469075815287370753

---

# Precautions

- Verify all wiring before powering the circuit.
- Use a resistor with every LED.
- Ensure correct LED polarity.
- Use INPUT_PULLUP for all push buttons.
- Maintain a common ground connection.
- Verify the sketch before uploading.

---

# Do's

- Verify every hardware connection.
- Test every state transition.
- Observe LED indications carefully.
- Monitor Serial output.
- Save screenshots and demonstration videos.
- Verify proper operation before submission.

---

# Don'ts

- Do not connect LEDs without resistors.
- Do not reverse LED polarity.
- Do not disconnect the Arduino while uploading.
- Do not short the power supply.
- Do not modify the wiring during execution.

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| LED does not glow | Incorrect polarity | Reverse the LED |
| Button not responding | Incorrect wiring | Verify D2, D3, and D4 connections |
| Wrong state transition | Incorrect button sequence | Follow the intended state flow |
| Serial Monitor blank | Incorrect baud rate | Set baud rate to 9600 |
| Upload failed | Wrong COM port or board | Select the correct Arduino UNO and COM port |
| LEDs remain OFF | Missing GND or resistor | Verify power and resistor connections |

---

# Learning Outcomes

- Understood the concept of Finite State Machines (FSM).
- Implemented state-based embedded programming.
- Controlled multiple LEDs using Arduino.
- Interfaced push buttons using INPUT_PULLUP.
- Managed state transitions through user interaction.
- Logged system events using the Serial Monitor.
- Improved debugging and embedded programming skills.
- Practiced hardware-software integration for real-world control systems.

---

# Conclusion

The State Machine Implementation project successfully demonstrates the design and implementation of a finite state machine for a vending machine using Arduino UNO. By integrating multiple operating states, push button inputs, LED indicators, and Serial communication, the project effectively models a real-world embedded control system. The enhanced LED-based visualization improves system understanding while reinforcing key concepts of state-based programming, digital input handling, and embedded system design.
