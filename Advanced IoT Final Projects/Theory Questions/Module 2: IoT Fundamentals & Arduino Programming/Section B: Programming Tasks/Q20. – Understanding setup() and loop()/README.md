# Q 20 – Understanding setup() and loop() Functions in Arduino

## Question

**Explain the `setup()` and `loop()` functions in Arduino. What happens if you put a long `delay()` inside `loop()`? How does this affect sensor reading responsiveness? What is the non-blocking alternative? (2 Marks)**

---

# Introduction

Every Arduino program, also known as a sketch, is built around two essential functions: `setup()` and `loop()`. These functions control how the Arduino initializes the hardware and repeatedly executes the program during operation.

---

# setup() Function

The `setup()` function is executed **only once** when the Arduino board is powered on or reset.

### Purpose

- Initialize input and output pins.
- Start Serial communication.
- Initialize sensors and communication modules.
- Configure hardware before the main program begins.

### Example

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
```

---

# loop() Function

The `loop()` function executes **continuously** after `setup()` has finished. It contains the main program logic that keeps the Arduino running.

### Purpose

- Read sensor values.
- Control actuators.
- Process user inputs.
- Execute repetitive tasks.

### Example

```cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

---

# Difference Between setup() and loop()

| Feature | setup() | loop() |
|---------|----------|---------|
| Execution | Runs once | Runs continuously |
| Purpose | Initialization | Main program execution |
| Typical Tasks | Configure hardware and Serial communication | Read sensors, process logic, control outputs |

---

# What Happens if a Long delay() is Used Inside loop()?

A long `delay()` pauses the entire program for the specified duration. During this time, the Arduino cannot execute any other instructions.

### Effects

- Sensor readings are delayed.
- Button presses may be missed.
- Slow system response.
- Delayed actuator control.
- Reduced responsiveness of the embedded system.

---

# Effect on Sensor Reading Responsiveness

Suppose an Arduino reads a temperature sensor every second, but the program contains:

```cpp
delay(5000);
```

The Arduino waits for **5 seconds** before reading the sensor again. Any changes occurring during this period are not detected immediately, making the system less responsive and unsuitable for real-time applications.

---

# Non-Blocking Alternative

Instead of using `delay()`, Arduino programs can use the **`millis()`** function to perform timing operations without stopping the execution of other tasks.

### Advantages of millis()

- Reads sensors continuously.
- Responds quickly to button presses.
- Allows multiple tasks to run simultaneously.
- Improves responsiveness.
- Suitable for real-time IoT and embedded applications.

### Example

```cpp
unsigned long previousTime = 0;
const unsigned long interval = 1000;

void loop() {
  if (millis() - previousTime >= interval) {
    previousTime = millis();
    Serial.println("Read Sensor");
  }
}
```

---

# Practical IoT Example

A **smart weather station** continuously monitors temperature, humidity, and air quality.

- Using `delay(5000)` causes sensor updates only every five seconds, delaying alerts and reducing responsiveness.
- Using `millis()` allows the system to read sensors, update the display, and send cloud data simultaneously without blocking program execution.

---

# Conclusion

The `setup()` function is used for one-time initialization, while the `loop()` function repeatedly executes the main program. Using a long `delay()` inside `loop()` blocks the processor, reducing sensor responsiveness and overall system performance. The `millis()` function provides a non-blocking alternative that enables responsive, real-time Arduino and IoT applications.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
