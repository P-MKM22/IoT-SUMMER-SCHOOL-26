# Q 40 – MQTT Quality of Service (QoS) Levels

## Question

**Explain QoS (Quality of Service) levels in MQTT: QoS 0 (At most once), QoS 1 (At least once), QoS 2 (Exactly once). In an IoT water level monitoring system, which QoS level would you choose and why?**

---

# Introduction

**Quality of Service (QoS)** in **MQTT (Message Queuing Telemetry Transport)** defines the reliability of message delivery between the MQTT client and the MQTT broker. Different IoT applications require different levels of reliability depending on the importance of the transmitted data, network conditions, and resource constraints. MQTT provides three QoS levels, allowing developers to balance communication reliability, latency, bandwidth usage, and power consumption.

---

# MQTT QoS Levels

| QoS Level | Delivery Guarantee | Description | Advantages | Limitations | Typical IoT Applications |
|-----------|--------------------|-------------|------------|-------------|--------------------------|
| **QoS 0 (At Most Once)** | Message is delivered once or not at all. No acknowledgement is sent. | The sender transmits the message without verifying whether it reaches the receiver. | Fastest communication, lowest bandwidth usage, minimal power consumption. | Messages may be lost during network failures. | Environmental monitoring, periodic temperature readings, weather stations. |
| **QoS 1 (At Least Once)** | Message is guaranteed to arrive at least once. | The sender retransmits the message until an acknowledgement (PUBACK) is received from the receiver. | Reliable delivery with moderate communication overhead. | Duplicate messages may occur and must be handled by the application. | Water level monitoring, smart agriculture, industrial monitoring, home automation. |
| **QoS 2 (Exactly Once)** | Message is guaranteed to arrive exactly once. | Uses a four-step handshake to ensure that each message is delivered only once without duplication. | Highest reliability and data integrity. | Highest latency, bandwidth usage, and processing overhead. | Financial transactions, industrial control systems, critical command execution. |

---

# Comparison of MQTT QoS Levels

| Feature | QoS 0 | QoS 1 | QoS 2 |
|---------|--------|--------|--------|
| Reliability | Low | High | Very High |
| Duplicate Messages | No | Possible | No |
| Message Loss | Possible | No | No |
| Communication Overhead | Very Low | Moderate | High |
| Latency | Lowest | Moderate | Highest |
| Power Consumption | Lowest | Moderate | Highest |

---

# Which QoS Level Should Be Used for an IoT Water Level Monitoring System?

For an **IoT water level monitoring system**, **QoS 1 (At Least Once)** is the most appropriate choice.

### Reasons

- Water level data is important for preventing tank overflow or dry running of pumps.
- Every measurement should reach the cloud or monitoring application reliably.
- Occasional duplicate messages are generally acceptable because the latest sensor reading can overwrite the previous value.
- QoS 1 provides an excellent balance between **reliability**, **network bandwidth**, **latency**, and **power consumption**.
- Compared to QoS 2, it requires fewer communication steps, making it more efficient for battery-powered IoT devices while still ensuring reliable data delivery.

QoS 2 offers the highest reliability but introduces additional communication overhead and latency, making it unnecessary for periodic sensor measurements. QoS 0, while highly efficient, may lose important measurements during network interruptions.

---

# Practical IoT Example

Consider a **smart water tank monitoring system** installed in a residential building.

- An ultrasonic sensor measures the water level every minute.
- The ESP32 publishes the readings to an MQTT broker using **QoS 1**.
- If the acknowledgement from the broker is not received, the ESP32 automatically retransmits the message.
- The cloud dashboard receives reliable water level updates and alerts the user if the tank is nearly empty or full.
- Even if a duplicate message is received, the application processes the latest reading without affecting system operation.

---

# Conclusion

MQTT Quality of Service (QoS) levels provide different guarantees for message delivery, allowing IoT developers to choose the most suitable level based on application requirements. **QoS 0** prioritizes speed and efficiency, **QoS 1** balances reliability with moderate overhead, and **QoS 2** guarantees exactly-once delivery for mission-critical applications. For an IoT water level monitoring system, **QoS 1** is the preferred choice because it ensures reliable data transmission while maintaining efficient use of bandwidth, power, and processing resources.

---

# References

1. OASIS. **MQTT Version 5.0 Specification.** https://docs.oasis-open.org/mqtt/mqtt/v5.0/mqtt-v5.0.html
2. HiveMQ. **MQTT Essentials – Quality of Service (QoS).** https://www.hivemq.com/mqtt-essentials/
3. Eclipse Foundation. **Eclipse Paho MQTT Documentation.** https://www.eclipse.org/paho/
4. MQTT.org. **MQTT – The Standard for IoT Messaging.** https://mqtt.org/
5. IBM. **MQTT Messaging Protocol Overview.** https://www.ibm.com/docs/

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
