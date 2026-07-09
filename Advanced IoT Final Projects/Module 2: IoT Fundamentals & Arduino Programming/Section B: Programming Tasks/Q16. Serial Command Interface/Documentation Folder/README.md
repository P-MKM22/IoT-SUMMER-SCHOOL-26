# Documentation of Question 16

# Project Information

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

# Objective

To develop a Serial Command Interface using Arduino UNO that accepts commands from the Serial Monitor to control the built-in LED, monitor its status, and validate user inputs. The project demonstrates Serial communication, digital output control, command parsing, and basic embedded system programming.

---

# Problem Statement

Write a program that receives commands over Serial Monitor and controls hardware:

- **LED_ON** → Turn built-in LED ON
- **LED_OFF** → Turn built-in LED OFF
- **BLINK_X** → Blink LED X times (X is 1–9)
- **STATUS** → Print pin states
- **RESET** → Restart blink counter

Implement input validation: unknown commands should print **"ERROR: Unknown command"**.

---

# Components Required

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| USB Cable | 1 |

> **Note:** No external LED or resistor is required since the Arduino UNO uses its built-in LED connected internally to Digital Pin 13.

---

# Circuit Connections

This project does not require any external hardware connections.

### Built-in LED

| Arduino Pin | Purpose |
|-------------|---------|
| D13 (LED_BUILTIN) | Controls the built-in LED |

### USB Connection

| Connection | Purpose |
|------------|---------|
| USB Cable | Program uploading and Serial communication |

### Power

- Arduino UNO is powered directly through the USB cable.
- No external power supply is required.

### Ground (GND)

- Internal circuitry shares a common ground.
- No external GND wiring is necessary.

### Resistor

- No external resistor is required because the Arduino UNO already contains a current-limiting resistor for the built-in LED.

### INPUT_PULLUP

- Not used in this project because there are no push buttons or digital input devices.

### Precautions

- Set the Serial Monitor baud rate to **9600**.
- Ensure **Line Ending** is set to **Newline**.
- Enter commands exactly as specified.
- Use values only between **1 and 9** for the **BLINK_X** command.

---

# Software Requirements

- Arduino IDE 2.x or later
- Wokwi Online Simulator
- Arduino AVR Board Package
- USB Driver (if using a physical Arduino UNO)

---

# Execution Procedure

## Step 1

Open **Arduino IDE** or **Wokwi**.

---

## Step 2

Create a new **Arduino UNO** project.

---

## Step 3

Copy and paste the provided Arduino program into the editor.

---

## Step 4

Verify (compile) the program to ensure there are no compilation errors.

---

## Step 5

Upload the program to the Arduino UNO or start the Wokwi simulation.

---

## Step 6

Wait until the following startup message appears in the Serial Monitor:

```text
=== Serial Command Interface ===
Available Commands:
LED_ON
LED_OFF
BLINK_X
STATUS
RESET
```

---

## Step 7

Open the **Serial Monitor**.

Configure:

- Baud Rate: **9600**
- Line Ending: **Newline**

---

## Step 8

Test the supported commands one by one.

Turn the LED ON:

```text
LED_ON
```

Turn the LED OFF:

```text
LED_OFF
```

Blink the LED five times:

```text
BLINK_5
```

Display current status:

```text
STATUS
```

Reset the blink counter:

```text
RESET
```

Test an invalid command:

```text
HELLO
```

Expected output:

```text
ERROR: Unknown command
```

---

## Step 9

Observe the built-in LED while executing each command.

Verify that:

- LED turns ON.
- LED turns OFF.
- LED blinks the requested number of times.
- STATUS displays LED state and blink counter.
- RESET clears the blink counter.
- Invalid commands generate the correct error message.

---

## Step 10

Capture screenshots and demonstration videos of all required outputs for repository submission.

---

# Program Logic

1. Initialize Serial communication at **9600 baud**.
2. Configure the built-in LED as an output.
3. Continuously monitor the Serial port for incoming commands.
4. Read and clean the received command.
5. Compare the command with supported operations.
6. Execute the corresponding LED function.
7. Update the blink counter when blinking occurs.
8. Display system status when requested.
9. Reset the blink counter when the RESET command is received.
10. Print an error message for unsupported commands.
11. Repeat continuously.

---

# Expected Output

Successful execution should produce the following results:

- `LED_ON` turns the built-in LED ON.
- `LED_OFF` turns the built-in LED OFF.
- `BLINK_3` blinks the LED three times.
- `STATUS` displays the LED state and total blink count.
- `RESET` resets the blink counter to zero.
- Invalid commands display:

```text
ERROR: Unknown command
```

---

# Files Included

```text
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
│   └── README.md
│
└── README.md
```

---

# Wokwi Simulation

This Wokwi simulation demonstrates the complete implementation of the **Serial Command Interface**. It allows users to test all supported Serial commands (`LED_ON`, `LED_OFF`, `BLINK_X`, `STATUS`, and `RESET`) and observe the built-in LED behavior and Serial Monitor responses in a virtual Arduino UNO environment.

**Project Link:**

https://wokwi.com/projects/469067354722784257
---

# Precautions

- Use the correct baud rate (**9600**).
- Select **Newline** in the Serial Monitor.
- Type commands exactly as specified.
- Do not enter values outside **1–9** for the blink command.
- Wait until blinking completes before entering another command.
- Upload the correct sketch before testing.

---

# Do's

- Verify the code before uploading.
- Test every supported command.
- Observe the built-in LED during execution.
- Save screenshots of each successful command.
- Keep the USB connection stable.
- Verify the output in the Serial Monitor.

---

# Don'ts

- Do not change the baud rate.
- Do not disconnect the board while uploading.
- Do not enter unsupported command formats.
- Do not use invalid blink values.
- Do not close the Serial Monitor while testing.

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| No Serial output | Incorrect baud rate | Set Serial Monitor to 9600 baud |
| Commands not working | Incorrect line ending | Select **Newline** |
| LED not blinking | Incorrect code uploaded | Upload the correct sketch again |
| STATUS not updating | Blink command not executed | Execute a valid BLINK_X command first |
| ERROR displayed | Invalid command entered | Enter a supported command exactly as specified |
| Upload failed | Incorrect COM port or board | Select the correct Arduino board and port |

---

# Learning Outcomes

- Learned Serial communication using Arduino UNO.
- Understood command-based hardware control.
- Implemented command parsing using String operations.
- Controlled digital outputs through Serial commands.
- Applied input validation techniques.
- Maintained program state using variables.
- Practiced debugging using the Serial Monitor.
- Improved understanding of embedded system interaction.

---

# Conclusion

The Serial Command Interface project successfully demonstrates interactive communication between a computer and an Arduino UNO through the Serial Monitor. The implementation supports multiple user commands for LED control, blink counting, status monitoring, and command validation. The project provides practical experience in Serial communication, digital I/O control, command parsing, and embedded software development, serving as a strong foundation for more advanced IoT and automation applications.
