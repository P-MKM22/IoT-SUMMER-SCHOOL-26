# Documentation of Question 22

## Overview

This document provides the complete technical documentation for the **Ultrasonic Parking Sensor** project developed using the Arduino Uno and HC-SR04 ultrasonic sensor. The system continuously measures the distance between a vehicle and an obstacle, providing visual and audible alerts that help the driver park safely.

The implementation uses non-blocking programming with `millis()` to control LED blinking and buzzer operation while continuously measuring distance, satisfying the bonus requirement of the assignment.

---

## Documentation Contents

This documentation includes:

- Project overview
- Hardware configuration
- Circuit implementation
- Software implementation
- Distance calculation
- Alert logic
- Execution procedure
- Working principle
- Expected outputs
- Code explanation
- Libraries used
- Learning outcomes
- Best practices
- References

---

## Project Structure

```text
Q22. Ultrasonic Parking Sensor
│
├── Assets
│   ├── .gitkeep
│   ├── Ultrasonic Parking Sensor demo.mp4
│   ├── Ultrasonic parking sensor distance greater than 50cm.png
│   ├── Ultrasonic parking sensor distance less than 10cm.png
│   ├── Ultrasonic parking sensor distance less than 20cm.png
│   └── Ultrasonic parking sensor hardware setup.png
│
├── Code
│   └── UPS.ino
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

## Implementation Details

### Hardware Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Green LED
- Yellow LED
- Red LED
- Active/Passive Buzzer
- 220 Ω Resistors
- Breadboard
- Jumper Wires

### Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |

### Distance Formula

The measured pulse duration from the ultrasonic sensor is converted into distance using:

```cpp
distance = (duration * 0.034) / 2;
```

where:

- **duration** = Echo pulse duration in microseconds
- **0.034 cm/µs** = Speed of sound
- Division by **2** accounts for the round-trip travel of the ultrasonic wave.

---

## Execution Steps

### Step 1

Open the Arduino IDE or Wokwi simulator.

### Step 2

Connect the HC-SR04 sensor according to the specified pin configuration.

### Step 3

Connect the Green, Yellow and Red LEDs through 220 Ω resistors.

### Step 4

Connect the buzzer to digital pin D8 and GND.

### Step 5

Upload the provided Arduino program.

### Step 6

Open the Serial Monitor and set the baud rate to **9600 bps**.

### Step 7

Move an object towards or away from the ultrasonic sensor.

### Step 8

Observe the measured distance printed on the Serial Monitor.

### Step 9

Verify that the alert system behaves as follows:

- Distance greater than 50 cm
  - Green LED blinks
  - Serial Monitor displays **SAFE**
  - Buzzer OFF

- Distance between 20 cm and 50 cm
  - Yellow LED ON
  - Buzzer beeps every 500 ms

- Distance between 10 cm and 20 cm
  - Red LED ON
  - Buzzer beeps every 200 ms

- Distance less than 10 cm
  - Yellow and Red LEDs flash rapidly
  - Buzzer remains continuously ON

### Step 10

Verify that the LEDs and buzzer operate without interrupting distance measurements, demonstrating successful use of `millis()`.

---

## Working Principle

The HC-SR04 sensor emits ultrasonic pulses through its Trigger pin. These sound waves travel until they strike an object and reflect back to the sensor.

The Echo pin remains HIGH for the duration of the sound wave's travel. Arduino measures this pulse duration using the `pulseIn()` function.

The measured duration is converted into distance using the speed of sound formula.

The calculated distance determines the current parking zone:

- Safe Zone
- Warning Zone
- Danger Zone
- Critical Zone

The system continuously updates the LEDs, buzzer, and Serial Monitor without blocking execution by using the `millis()` function for timing-based events.

---

## Expected Output

### Safe Zone (>50 cm)

- Green LED blinks
- Yellow LED OFF
- Red LED OFF
- Buzzer OFF
- Serial Monitor prints:

```
Distance: 82.4 cm
SAFE
```

---

### Warning Zone (20–50 cm)

- Yellow LED ON
- Green LED OFF
- Red LED OFF
- Buzzer beeps every 500 ms

Example:

```
Distance: 34.6 cm
```

---

### Danger Zone (10–20 cm)

- Red LED ON
- Green LED OFF
- Yellow LED OFF
- Buzzer beeps every 200 ms

Example:

```
Distance: 14.8 cm
```

---

### Critical Zone (<10 cm)

- Yellow LED flashes rapidly
- Red LED flashes rapidly
- Green LED OFF
- Continuous buzzer

Example:

```
Distance: 7.2 cm
```

---

## Code Explanation

### Sensor Initialization

The Trigger and Echo pins are configured for ultrasonic distance measurement.

### Distance Measurement

The program sends a 10 µs trigger pulse and measures the echo duration.

### Distance Calculation

The duration is converted into centimeters using the standard speed of sound equation.

### Alert Processing

Conditional statements classify the measured distance into one of four parking zones.

### Non-blocking Timing

Instead of using `delay()`, the program uses the `millis()` function to control:

- LED blinking
- Buzzer beeping intervals

This allows the Arduino to continue measuring distance while simultaneously updating the outputs.

### Serial Monitoring

The measured distance is continuously displayed on the Serial Monitor, along with the **SAFE** message whenever the distance exceeds 50 cm.

---

## Libraries Used

No external libraries are required.

The project uses only standard Arduino functions including:

- `pinMode()`
- `digitalWrite()`
- `pulseIn()`
- `tone()`
- `noTone()`
- `millis()`
- `Serial.begin()`
- `Serial.print()`

---

## Learning Outcomes

After completing this project, the following concepts were learned:

- Working principle of ultrasonic distance sensors
- Time-of-flight distance measurement
- Arduino digital input and output control
- LED indication techniques
- Audible warning systems using buzzers
- Non-blocking programming with `millis()`
- Conditional decision making
- Embedded system event handling
- Real-time monitoring using Serial communication

---

## Best Practices

- Use 220 Ω resistors for all LEDs.
- Avoid using `delay()` in real-time embedded systems.
- Keep sensor wiring short to reduce electrical noise.
- Secure all breadboard connections before testing.
- Validate measured distances using the Serial Monitor.
- Use modular functions to improve code readability and maintainability.
- Test each alert zone individually before final deployment.

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469171212359044097

**Description**

The Wokwi simulation demonstrates the complete parking assistance system using an Arduino Uno, HC-SR04 ultrasonic sensor, three LEDs, and a buzzer. It validates the real-time distance measurement, LED indications, buzzer alerts, Serial Monitor output, and the non-blocking implementation using `millis()` without requiring physical hardware.

---

## References

1. Arduino Documentation — https://docs.arduino.cc/
2. HC-SR04 Ultrasonic Sensor Datasheet
3. Arduino Language Reference — https://www.arduino.cc/reference/en/
4. Wokwi Arduino Simulator — https://wokwi.com/
5. Arduino `tone()` Function Documentation
6. Arduino `millis()` Function Documentation

---

## Conclusion

This project demonstrates the implementation of a real-time ultrasonic parking assistance system capable of measuring obstacle distance and providing progressive visual and audible alerts. By using non-blocking programming with `millis()`, the system remains responsive while continuously monitoring distance and updating outputs. The design provides a practical introduction to embedded sensing, event-driven programming, and real-time control, making it suitable for both academic learning and future smart parking applications.
