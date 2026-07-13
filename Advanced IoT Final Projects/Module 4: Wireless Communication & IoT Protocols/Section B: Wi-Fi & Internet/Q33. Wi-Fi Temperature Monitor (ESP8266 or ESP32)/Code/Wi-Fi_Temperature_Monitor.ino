/*
------------------------------------------------------------
Project     : Wi-Fi Temperature Monitor (ESP8266/ESP32)
File Name   : WiFi-Temperature-Monitor.ino

Author      : P Meet Kumar
Roll Number : IoT 009
Date        : 14 July 2026

Program     : IoT and Drone Building Summer School 2026
Institution : Indian Institute of Technology Jammu (IIT Jammu)

Description :
This program creates an ESP32 based Wi-Fi web server
that displays live temperature, humidity, device uptime,
and allows LED control through a browser.
------------------------------------------------------------
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// Wi-Fi Credentials

const char* ssid = "ESP32_Test";
const char* password = "esp321234";

// Pin Configuration

#define DHTPIN 15
#define DHTTYPE DHT11
#define LED_PIN 2

// Object Initialization

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

// Global Variables

bool ledState = false;

float temperature = 0.0;
float humidity = 0.0;

unsigned long startTime = 0;

// HTML Webpage

String webpage =
"<!DOCTYPE html>"
"<html>"
"<head>"

"<meta charset='UTF-8'>"
"<meta http-equiv='refresh' content='10'>"
"<meta name='viewport' content='width=device-width, initial-scale=1'>"

"<title>Wi-Fi Temperature Monitor</title>"

"<style>"

"body{"
"margin:0;"
"font-family:'Segoe UI',Arial,sans-serif;"
"background:#eef4ff;"
"color:#333;"
"}"

"header{"
"background:linear-gradient(90deg,#1565C0,#42A5F5);"
"padding:28px;"
"text-align:center;"
"color:white;"
"}"

"header h1{"
"margin:0;"
"font-size:34px;"
"}"

"header p{"
"margin-top:8px;"
"font-size:17px;"
"}"

".container{"
"width:92%;"
"max-width:1200px;"
"margin:auto;"
"margin-top:30px;"
"}"

".description{"
"background:white;"
"padding:18px;"
"border-radius:12px;"
"box-shadow:0 4px 12px rgba(0,0,0,.15);"
"text-align:center;"
"margin-bottom:25px;"
"}"

".row{"
"display:flex;"
"flex-wrap:wrap;"
"justify-content:center;"
"gap:20px;"
"}"

".card{"
"background:white;"
"width:230px;"
"padding:22px;"
"border-radius:15px;"
"box-shadow:0 5px 15px rgba(0,0,0,.18);"
"text-align:center;"
"transition:0.3s;"
"}"

".card:hover{"
"transform:translateY(-5px);"
"}"

".title{"
"font-size:18px;"
"font-weight:bold;"
"margin-bottom:15px;"
"}"

".value{"
"font-size:30px;"
"font-weight:bold;"
"color:#1565C0;"
"}"

".button-area{"
"text-align:center;"
"margin-top:35px;"
"}"

"button{"
"padding:14px 32px;"
"font-size:18px;"
"background:#1565C0;"
"color:white;"
"border:none;"
"border-radius:8px;"
"cursor:pointer;"
"}"

"button:hover{"
"background:#0D47A1;"
"}"

"table{"
"width:100%;"
"margin-top:35px;"
"border-collapse:collapse;"
"background:white;"
"box-shadow:0 4px 12px rgba(0,0,0,.18);"
"}"

"th{"
"background:#1565C0;"
"color:white;"
"padding:12px;"
"}"

"td{"
"padding:12px;"
"text-align:center;"
"border-bottom:1px solid #ddd;"
"}"

"footer{"
"margin-top:40px;"
"background:#1565C0;"
"color:white;"
"text-align:center;"
"padding:20px;"
"}"

"</style>"

"</head>"

"<body>"

"<header>"

"<h1>Wi-Fi Temperature Monitor</h1>"

"<p>Advanced IoT Final Project | Module 04</p>"

"<p>Indian Institute of Technology Jammu (IIT Jammu)</p>"

"</header>"

"<div class='container'>"

"<div class='description'>"

"<h2>Project Overview</h2>"

"<p>"
"This dashboard provides real-time environmental monitoring "
"through an ESP32 based web server. It displays live sensor "
"data, device uptime, LED status and allows wireless LED "
"control from any device connected to the same Wi-Fi network."
"</p>"

"</div>"

"<div class='row'>";
// Generate Webpage

String getHTML() {

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    temperature = 0.0;
    humidity = 0.0;
  }

  unsigned long uptime = (millis() - startTime) / 1000;

  String html = webpage;

  html += "<div class='card'>";
  html += "<div class='title'>🌡 Temperature</div>";
  html += "<div class='value'>";
  html += String(temperature, 1);
  html += " &deg;C</div>";
  html += "</div>";

  html += "<div class='card'>";
  html += "<div class='title'>💧 Humidity</div>";
  html += "<div class='value'>";
  html += String(humidity, 1);
  html += " %</div>";
  html += "</div>";

  html += "<div class='card'>";
  html += "<div class='title'>💡 LED Status</div>";
  html += "<div class='value'>";
  html += (ledState ? "ON" : "OFF");
  html += "</div>";
  html += "</div>";

  html += "<div class='card'>";
  html += "<div class='title'>⏱ Device Uptime</div>";
  html += "<div class='value'>";
  html += String(uptime);
  html += " sec</div>";
  html += "</div>";

  html += "</div>";

  html += "<div class='button-area'>";

  html += "<form action='/toggle' method='GET'>";

  if (ledState) {
    html += "<button style='background:#E53935;'>Turn OFF LED</button>";
  } else {
    html += "<button style='background:#43A047;'>Turn ON LED</button>";
  }

  html += "</form>";

  html += "</div>";

  html += "<h2 style='text-align:center;margin-top:40px;'>Recent Sensor Readings</h2>";

  html += "<table>";

  html += "<tr>";
  html += "<th>Reading</th>";
  html += "<th>Temperature (°C)</th>";
  html += "<th>Humidity (%)</th>";
  html += "</tr>";

  for (int i = 1; i <= 10; i++) {

    html += "<tr>";

    html += "<td>";
    html += String(i);
    html += "</td>";

    html += "<td>";
    html += String(temperature, 1);
    html += "</td>";

    html += "<td>";
    html += String(humidity, 1);
    html += "</td>";

    html += "</tr>";

  }

  html += "</table>";

  html += "<footer>";

  html += "<h3>Advanced IoT Final Project</h3>";

  html += "<p>";
  html += "Real-time environmental monitoring dashboard developed ";
  html += "using ESP32 and Wi-Fi technology.";
  html += "</p>";

  html += "<p>";
  html += "<b>IoT and Drone Building Summer School 2026</b>";
  html += "</p>";

  html += "<p>";
  html += "Indian Institute of Technology Jammu (IIT Jammu)";
  html += "</p>";

  html += "</footer>";

  html += "</body>";
  html += "</html>";

  return html;
}

// Handle Home Page

void handleRoot() {

  server.send(200, "text/html", getHTML());

}

// Toggle LED

void handleToggle() {

  ledState = !ledState;

  digitalWrite(LED_PIN, ledState);

  server.sendHeader("Location", "/");
  server.send(303, "text/plain", "");

}
// Setup Function

void setup() {

  Serial.begin(115200);

  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  startTime = millis();

  Serial.println();
  Serial.println("==========================================");
  Serial.println("      Wi-Fi Temperature Monitor");
  Serial.println("==========================================");
  Serial.println();

  Serial.print("Connecting to Wi-Fi");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("------------------------------------------");
  Serial.println("Wi-Fi Connected Successfully");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  Serial.print("RSSI       : ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");

  Serial.println("------------------------------------------");

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);

  server.begin();

  Serial.println("HTTP Server Started");
  Serial.println("Open the above IP address in your browser.");
  Serial.println();
}

// Main Loop

void loop() {

  server.handleClient();

}
