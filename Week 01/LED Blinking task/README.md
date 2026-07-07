# README Documentation

## Project Title

**Arduino Uno LED Blinking Project**

---

## Project Overview

This project demonstrates the implementation of a basic LED blinking circuit using an Arduino Uno. It serves as an introductory embedded systems project that helps understand digital output control, Arduino programming, and hardware interfacing. The LED continuously turns ON and OFF at a fixed time interval, providing a simple demonstration of microcontroller-based output control.

---

## Hardware Required

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| Breadboard | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

## Circuit Diagram Description

The LED is connected to **Digital Pin 9** of the Arduino Uno through a **220 Ω resistor**. The resistor limits the current flowing through the LED to prevent damage. The cathode (negative terminal) of the LED is connected to the **GND** pin of the Arduino, completing the circuit.

### Circuit Connections

| Arduino Pin | Connected To |
|-------------|--------------|
| D9 | 220 Ω Resistor |
| Resistor | LED Anode (+) |
| LED Cathode (-) | GND |

---

## How to Upload the Code

### Step 1

Open the **Arduino IDE**.

### Step 2

Connect the Arduino Uno to your computer using a USB cable.

### Step 3

Open the **LED Blink.ino** file.

### Step 4

Go to **Tools → Board** and select:

```
Arduino Uno
```

### Step 5

Go to **Tools → Port** and select the COM port connected to the Arduino.

### Step 6

Click the **Verify (✓)** button to compile the program.

### Step 7

If the compilation is successful, click the **Upload (→)** button.

### Step 8

Wait until the message

```
Done Uploading.
```

appears in the output window.

### Step 9

Observe the LED connected to Pin 9. It should blink continuously.

---

## Expected Output

- The LED connected to Digital Pin 9 blinks continuously.
- The LED remains ON for approximately 500 milliseconds.
- The LED remains OFF for approximately 500 milliseconds.
- The blinking cycle repeats until the Arduino is powered off or reprogrammed.

---

## Folder Structure

```text
Q5 README Documentation
│
├── Assets
│   ├── Hardware Setup.png
│   ├── LED Working.png
│   └── README Preview.png (Optional)
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

## Project Assets

- Hardware Setup.png
- LED Working.png
- README Preview.png (Optional)

---

## Troubleshooting Tips

### 1. LED does not blink

- Verify that the LED polarity is correct.
- Ensure the resistor is connected properly.
- Check that the LED is connected to Digital Pin 9.

---

### 2. Upload fails

- Confirm that the correct board (**Arduino Uno**) is selected.
- Verify that the correct COM port is selected.
- Ensure the USB cable is securely connected.

---

### 3. Compilation error

- Verify that the code has been copied correctly.
- Ensure there is only one `setup()` function and one `loop()` function.
- Check for missing semicolons or braces.

---

## Learning Outcomes

After completing this project, the following concepts were understood:

- Arduino Uno programming
- Digital output control
- LED interfacing
- Current limiting using a resistor
- Arduino IDE compilation and uploading
- Basic embedded system development
- Professional project documentation

---

## Conclusion

This project provides a practical introduction to Arduino programming and digital electronics by implementing a basic LED blinking application. It demonstrates the complete workflow of hardware setup, software development, code uploading, testing, and documentation while following professional GitHub repository practices.
