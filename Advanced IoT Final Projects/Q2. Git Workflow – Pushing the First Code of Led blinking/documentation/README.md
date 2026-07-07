# Q2 – Documentation

## Overview

This document provides the technical documentation for the **LED Blinking using Arduino Uno** project. It explains the hardware setup, circuit connections, program logic, expected output, and troubleshooting guidelines.

---

# Hardware Requirements

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| LED (5 mm) | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As per requirement |
| USB Cable | 1 |

---

# Hardware Connections

Follow the steps below to assemble the circuit correctly.

### Step 1 – Prepare the Components

Gather the Arduino Uno, LED, 220 Ω resistor, breadboard, jumper wires, and USB cable.

---

### Step 2 – Place the LED

Insert the LED into the breadboard.

- **Long leg (Anode)** → Connect to **Arduino Digital Pin 9**
- **Short leg (Cathode)** → Connect to the **220 Ω resistor**

---

### Step 3 – Connect the Resistor

Connect one end of the **220 Ω resistor** to the **LED cathode (short leg)**.

Connect the other end of the resistor to the **Arduino GND** pin.

---

### Step 4 – Connect Digital Pin 9

Using a jumper wire, connect **Digital Pin 9** of the Arduino Uno to the **LED anode (long leg)**.

---

### Step 5 – Connect Ground

Using another jumper wire, connect the **Arduino GND** pin to the free end of the resistor.

---

### Step 6 – Verify the Connections

Before uploading the program, ensure that:

- The LED anode is connected to Digital Pin 9.
- The LED cathode is connected to the resistor.
- The resistor is connected to Arduino GND.
- All jumper wires are firmly connected.

---

# Connection Summary

| Arduino Pin | Connected To |
|--------------|--------------|
| Digital Pin 9 | LED Anode (+) |
| GND | 220 Ω Resistor |
| 220 Ω Resistor | LED Cathode (−) |

---

# Hardware Setup

The assembled hardware setup of the project is available in the **assets** folder.

```text
assets/hardware_setup.png
```

---

# Working Output

The image showing the LED operating after uploading the program is available in the **assets** folder.

```text
assets/led_working_image.png
```

---

# Program Logic

The Arduino executes the following sequence continuously:

1. Configure Digital Pin 9 as an OUTPUT.
2. Turn the LED ON.
3. Keep the LED ON for 5 seconds.
4. Turn the LED OFF.
5. Keep the LED OFF for 1 second.
6. Repeat the sequence indefinitely.

---

# Code Explanation

### setup()

- Configures Digital Pin 9 as an output pin.

### loop()

- Sets Pin 9 HIGH to turn the LED ON.
- Waits for 5 seconds.
- Sets Pin 9 LOW to turn the LED OFF.
- Waits for 1 second.
- Repeats the process continuously.

---

# Demonstration Video

A complete demonstration of the project is available in the **assets** folder.

```text
assets/led_blinking_demo.mp4
```

---

# Expected Output

After uploading the program to the Arduino Uno:

- The LED turns **ON** for **5 seconds**.
- The LED turns **OFF** for **1 second**.
- This blinking cycle repeats continuously until the board is powered off or reprogrammed.

---

# Troubleshooting

| Issue | Possible Solution |
|--------|-------------------|
| LED does not glow | Check the LED polarity and jumper wire connections. |
| Upload failed | Verify the correct Arduino board and COM port are selected. |
| LED stays OFF | Ensure the code is uploaded successfully and Pin 9 is connected correctly. |
| LED remains ON continuously | Check the program logic and delay values. |

---

# Conclusion

This experiment demonstrates the basic operation of digital output control using the Arduino Uno. It introduces GPIO pin configuration, LED interfacing, timing functions using `delay()`, and simple embedded programming concepts. This project serves as a foundation for more advanced Arduino and IoT applications.

---

# References

- Arduino IDE
- Arduino Uno Datasheet
- Official Arduino Documentation
