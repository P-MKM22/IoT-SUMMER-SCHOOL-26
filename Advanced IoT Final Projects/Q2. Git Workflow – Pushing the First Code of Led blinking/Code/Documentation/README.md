# Q2 – Documentation

## Overview

This document provides the technical documentation for the **LED Blinking using Arduino Uno** project. It explains the hardware setup, circuit connections, working principle, program logic, expected output, and troubleshooting guidelines.

---

# Hardware Requirements

| Component | Quantity |
|-----------|---------:|
| Arduino Uno | 1 |
| LED (5 mm) | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As per requirement |
| USB Cable | 1 |

---

# Hardware Connections

Follow these steps to assemble the circuit correctly.

### Step 1 – Place the Arduino Uno

Place the Arduino Uno on a flat surface and connect it to your computer using a USB cable.

---

### Step 2 – Insert the LED

Insert the LED into the breadboard.

- Long leg (Anode) → Arduino Digital Pin 9
- Short leg (Cathode) → 220 Ω Resistor

---

### Step 3 – Connect the Resistor

Connect one end of the 220 Ω resistor to the LED's cathode.

Connect the other end of the resistor to the Arduino GND pin.

---

### Step 4 – Connect Digital Pin 9

Using a jumper wire, connect Arduino Digital Pin 9 to the LED anode.

---

### Step 5 – Connect Ground

Connect the Arduino GND pin to the free end of the resistor.

---

# Circuit Summary

| Arduino Pin | Connected Component |
|--------------|--------------------|
| Digital Pin 9 | LED Anode (+) |
| GND | 220 Ω Resistor |
| 220 Ω Resistor | LED Cathode (-) |
---

# Hardware Setup

The hardware setup image showing the Arduino Uno, LED, resistor, and breadboard connections is available in the **assets** folder.

```text
assets/Hardware Setup.png
```

---

# LED Working Output

The image showing the LED in its working state after uploading the program is available in the **assets** folder.

```text
assets/Led Working Image.png
```

---

# Demonstration Video

A complete demonstration of the project is available in the **assets** folder.

```text
assets/Led Blinking Demo.mp4
```

---

# Program Logic

The Arduino continuously executes the following sequence:

1. Configure Digital Pin 9 as an OUTPUT.
2. Turn the LED ON.
3. Keep the LED ON for 5 seconds.
4. Turn the LED OFF.
5. Keep the LED OFF for 1 second.
6. Repeat the process indefinitely.

---

# Code Explanation

### setup()

- Initializes Digital Pin 9 as an output pin.

### loop()

- Sets Pin 9 HIGH to switch ON the LED.
- Waits for 5000 milliseconds.
- Sets Pin 9 LOW to switch OFF the LED.
- Waits for 1000 milliseconds.
- Repeats continuously.

---

# Expected Output

After uploading the program:

- The LED glows continuously for 5 seconds.
- The LED turns OFF for 1 second.
- The blinking sequence repeats continuously.

---

# Demonstration

A demonstration video is available in the **assets** folder.

```
assets/assets/led_blink_demo.mp4.mp4
```

---

# Troubleshooting

| Issue | Possible Solution |
|--------|-------------------|
| LED does not glow | Check the LED polarity. |
| LED remains OFF | Verify the jumper wire connections. |
| Upload error | Select the correct Arduino board and COM port. |
| LED glows continuously | Verify the uploaded program and delay values. |

---

# Conclusion

This project demonstrates basic digital output control using the Arduino Uno. It introduces fundamental concepts such as GPIO pin configuration, digital signal generation, timing using delay functions, and LED interfacing. This experiment serves as a foundation for more advanced embedded systems and IoT applications.

---

# References

- Arduino IDE
- Arduino Uno Datasheet
- Official Arduino Documentation
