# Q 37 – Wi-Fi Security for IoT

## Question

**Research and write 250 words on: Common Wi-Fi attack vectors on IoT devices (WPA2 vulnerabilities, evil twin attacks), Best practices for securing ESP32 Wi-Fi connections (certificate pinning, WPA3), and Why hardcoding passwords in IoT source code is dangerous. Reference at least 2 sources in your answer.**

---

# Introduction

Wi-Fi enables IoT devices to communicate with cloud services, mobile applications, and other connected systems. However, wireless communication also exposes IoT devices to various cyber threats. Poor Wi-Fi security can result in unauthorized access, data theft, device compromise, and disruption of critical IoT services. Therefore, implementing strong wireless security measures is essential for building secure and reliable IoT systems.

---

# Common Wi-Fi Attack Vectors on IoT Devices

### 1. WPA2 Vulnerabilities

Although **WPA2** has been widely adopted for securing wireless networks, it is susceptible to attacks when weak passwords are used or devices are improperly configured. Attackers may perform offline dictionary or brute-force attacks against captured authentication handshakes to recover weak pre-shared keys. Strong, randomly generated passwords significantly reduce this risk. Modern security standards such as **WPA3** further improve protection by strengthening the authentication process. :contentReference[oaicite:0]{index=0}

### 2. Evil Twin Attack

An **Evil Twin Attack** occurs when an attacker creates a rogue Wi-Fi access point that imitates a legitimate network by using the same SSID. Unsuspecting IoT devices or users may connect to the fake access point, allowing the attacker to intercept communications, capture credentials, or manipulate transmitted data. Proper authentication, certificate validation, and secure Wi-Fi configuration help reduce the risk of such attacks. :contentReference[oaicite:1]{index=1}

---

# Best Practices for Securing ESP32 Wi-Fi Connections

To improve the security of ESP32-based IoT devices, the following best practices should be followed:

- Prefer **WPA3** whenever supported instead of WPA2.
- Enable **Protected Management Frames (PMF)** to reduce deauthentication attacks.
- Use **TLS/SSL encryption** for all cloud communication.
- Validate server identities and implement **certificate or public-key pinning** only when the application owner controls both the client and server and can manage certificate updates safely. :contentReference[oaicite:2]{index=2}
- Keep ESP32 firmware and libraries updated with the latest security patches.
- Disable unnecessary network services and open ports.
- Use strong, unique Wi-Fi credentials for every deployment.

---

# Why Hardcoding Passwords in IoT Source Code is Dangerous

Hardcoding Wi-Fi credentials directly into source code creates significant security risks.

- Passwords can be extracted if the firmware or source code is leaked.
- The same credentials may be reused across many deployed devices, increasing the impact of a compromise.
- Updating passwords requires rebuilding and reflashing firmware.
- Compromised credentials may provide attackers with unauthorized network access.

A more secure approach is to store credentials in encrypted non-volatile storage or use secure provisioning methods during device setup.

---

# Conclusion

Securing IoT Wi-Fi communication requires a combination of strong authentication, encrypted communication, secure device configuration, and proper credential management. Adopting WPA3, enabling security features such as PMF, using TLS, carefully applying certificate validation where appropriate, and avoiding hardcoded credentials significantly improve the resilience of ESP32-based IoT systems against modern wireless attacks.

---

# References

1. Espressif Systems. **ESP-IDF Programming Guide – Wi-Fi Security**. :contentReference[oaicite:3]{index=3}
2. OWASP Foundation. **Certificate and Public Key Pinning**. :contentReference[oaicite:4]{index=4}
3. OWASP Cheat Sheet Series. **Pinning Cheat Sheet**. :contentReference[oaicite:5]{index=5}
4. CERT Coordination Center. **WPA3 Design Issues and Implementation Vulnerabilities (Dragonblood)**. :contentReference[oaicite:6]{index=6}
5. Computers & Security Journal. **Evil Twins and WPA2 Enterprise: A Coming Security Disaster?** :contentReference[oaicite:7]{index=7}

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
