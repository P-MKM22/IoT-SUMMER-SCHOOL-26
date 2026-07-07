# Week 04 – Drone Control Systems, Flight Stabilization, and Control Algorithms

## Overview

Week 04 focused on the advanced concepts involved in drone flight control and autonomous navigation. The sessions covered flight stabilization techniques, control algorithms, coordinate systems, failsafe mechanisms, and software used for drone mission planning. We also learned how controllers and filtering techniques help maintain stable flight in real-world drone applications.

---

## Learning Objectives

- Understand drone flight control systems.
- Learn how drone stabilization is achieved.
- Study Mission Planner software.
- Understand different flight modes and failsafe mechanisms.
- Learn the NED coordinate system.
- Explore PID controllers and Bang-Bang control.
- Understand the role of the Extended Kalman Filter (EKF).
- Study drone thrust generation and stability.

---

## Topics Covered

### 1. Mission Planner Software

- Introduction to Mission Planner
- Drone configuration
- Flight monitoring
- Mission planning
- Parameter tuning

---

### 2. Flight Modes

- Stabilize Mode
- Position Hold (Pos Hold)
- Altitude Hold (Alt Hold)
- Land Mode
- Return to Launch (RTL)
- Return to Home (RTH)

---

### 3. Failsafe Mechanisms

- Battery Failsafe
- GPS Failsafe
- Radio Signal Loss Failsafe
- Automatic Return-to-Home
- Emergency Landing

---

### 4. NED Coordinate System

Understanding the navigation reference frame used in drones.

- **X-axis** → North
- **Y-axis** → East
- **Z-axis** → Down

Applications:
- Drone navigation
- Position estimation
- Autonomous flight

---

### 5. Drone Thrust and Stability

- Thrust generation using BLDC motors
- Relationship between thrust and weight
- Ascending (Thrust > Weight)
- Descending (Thrust < Weight)
- Hovering (Thrust = Weight)

---

### 6. Under-Actuated Drone System

- Understanding under-actuated systems
- Why quadcopters are naturally unstable
- Need for continuous feedback control
- Importance of fast control loops

---

### 7. Flight Control Response

- Human reaction time (~250 ms)
- Drone controller response (~10 ms)
- Importance of real-time control

---

### 8. Extended Kalman Filter (EKF)

- Introduction to EKF
- Sensor fusion
- State estimation
- Position estimation
- Orientation estimation

---

### 9. PID Controller

- Proportional Control
- Integral Control
- Derivative Control
- Drone attitude stabilization
- Roll, Pitch and Yaw control

---

### 10. Bang-Bang Controller

- ON/OFF control algorithm
- Threshold-based switching
- Basic automatic control applications

---

### 11. Battery and Motor Management

- Battery monitoring
- Power distribution
- Motor synchronization
- Efficient power utilization

---

## Practical Learning

- Explored Mission Planner software.
- Studied different autonomous flight modes.
- Understood drone failsafe operations.
- Learned the NED navigation coordinate system.
- Studied drone thrust and hovering principles.
- Learned how PID controllers stabilize drones.
- Explored the Extended Kalman Filter (EKF).
- Understood Bang-Bang control algorithms.
- Discussed battery management and motor control.

---

## Tools & Software Used

- Mission Planner
- Flight Controller
- GPS Module
- BLDC Motors
- ESC
- LiPo Battery
- Arduino IDE
- ESP32

---

## Skills Acquired

- Drone Flight Control
- Mission Planning
- Autonomous Navigation
- PID Controller Basics
- Extended Kalman Filter
- Flight Stabilization
- Navigation Systems
- Drone Safety Mechanisms
- Control Algorithms

---

## Learning Outcomes

By the end of Week 04, I was able to:

- Understand the working of drone flight controllers.
- Configure and understand Mission Planner software.
- Explain different drone flight modes.
- Understand failsafe mechanisms for safe drone operation.
- Interpret the NED coordinate system.
- Explain how drones generate thrust and maintain stability.
- Understand the role of PID controllers in flight stabilization.
- Learn the importance of EKF for sensor fusion and navigation.
- Gain knowledge of autonomous drone control techniques.

---

## Summary

Week 04 introduced advanced drone control concepts, including Mission Planner, flight modes, failsafe systems, PID control, Extended Kalman Filters, drone stability, and navigation. These topics provided a strong foundation for understanding how modern autonomous drones maintain stable and reliable flight.
