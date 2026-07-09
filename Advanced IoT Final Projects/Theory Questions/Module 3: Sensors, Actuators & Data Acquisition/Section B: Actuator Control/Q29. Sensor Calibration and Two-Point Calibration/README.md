# Q 29 – Sensor Calibration and Two-Point Calibration Method
 
## Question

**What is sensor calibration and why is it important in IoT systems? How would you calibrate an analog soil moisture sensor to give accurate percentage readings? Describe the two-point calibration method. (2 Marks)**

---

# Introduction

Sensor calibration is the process of comparing a sensor's output with known reference values and adjusting its readings to improve measurement accuracy. Calibration ensures that sensor data is reliable, consistent, and suitable for real-world IoT applications.

---

# What is Sensor Calibration?

Sensor calibration is the process of correcting a sensor's readings by using known reference points. It minimizes measurement errors caused by manufacturing variations, environmental conditions, sensor aging, and installation differences.

---

# Why is Sensor Calibration Important in IoT Systems?

- Improves measurement accuracy.
- Ensures reliable and consistent sensor data.
- Reduces measurement errors.
- Enhances decision-making in IoT applications.
- Increases the overall reliability of automated systems.

---

# Calibrating an Analog Soil Moisture Sensor

An analog soil moisture sensor provides different analog values depending on the moisture level of the soil. To convert these values into an accurate moisture percentage, the sensor must first be calibrated.

### Calibration Procedure

1. Place the sensor in completely **dry soil** (or keep it in air) and record the analog reading.
2. Place the sensor in **fully wet soil** (or immerse the sensing probe in water) and record the analog reading.
3. Use these two values as reference points.
4. Convert future sensor readings into a percentage using linear mapping.

Example:

- Dry Reading = **850**
- Wet Reading = **350**

Any reading between these values can be converted into a moisture percentage using a mapping formula.

---

# Two-Point Calibration Method

The **Two-Point Calibration Method** uses two known reference values to establish the operating range of the sensor.

### Step 1 – Dry Reference

Measure the sensor output under completely dry conditions.

Example:

```text
Dry Reading = 850
```

This corresponds to:

```text
0% Moisture
```

---

### Step 2 – Wet Reference

Measure the sensor output under completely wet conditions.

Example:

```text
Wet Reading = 350
```

This corresponds to:

```text
100% Moisture
```

---

### Step 3 – Convert Sensor Reading

Future sensor values are converted into moisture percentage using linear interpolation.

Example:

```text
Moisture (%) = Map(Current Reading, Dry Reading, Wet Reading, 0, 100)
```

This provides accurate and consistent moisture percentage values for irrigation and monitoring applications.

---

# Practical IoT Example

A **Smart Irrigation System** uses an analog soil moisture sensor to monitor soil conditions.

- The sensor is calibrated using dry and wet reference values.
- The Arduino converts the analog reading into a moisture percentage.
- If the moisture level falls below a predefined threshold (e.g., 30%), the irrigation pump is automatically switched ON.
- When the moisture level reaches the desired value, the pump is turned OFF, conserving water and improving crop health.

---

# Conclusion

Sensor calibration is essential for obtaining accurate and reliable measurements in IoT systems. The two-point calibration method uses known dry and wet reference values to convert raw sensor readings into meaningful percentage values. This technique improves the accuracy of analog soil moisture sensors and enables efficient automation in applications such as smart irrigation.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
