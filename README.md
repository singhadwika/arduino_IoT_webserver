# arduino_IoT_webserver

## Overview

**arduino_IoT_webserver** is an ESP32-based project that creates a web server to control connected devices (like LEDs) and monitor real-time sensor data (e.g., temperature and humidity). The project serves an interactive web-based control panel, allowing users to control devices and view sensor readings directly from their browser, making it a powerful and flexible tool for IoT applications.

## Features

- **Web-Based Control Panel**: An intuitive interface to control devices connected to the ESP32.
- **Real-Time Data Monitoring**: Display real-time temperature and humidity data using a DHT11 sensor.
- **AJAX-Based Dynamic Updates**: Smooth and dynamic updates of sensor data without refreshing the page.
- **Device Control**: Control GPIO-connected devices like LEDs, relays, or motors directly from the web interface.

## Requirements

### Hardware
- **ESP32 Development Board**: The main microcontroller with integrated Wi-Fi and Bluetooth capabilities.
- **DHT11 Sensor**: To measure temperature and humidity.
- **LED or Other Devices**: Connected to GPIO pins for demonstration purposes.
- **USB Cable**: For programming the ESP32.
- **Breadboard and Jumper Wires**: For easy circuit assembly.

### Software
- **Arduino IDE**: The development environment for writing and uploading code to the ESP32.
- **ESP32 Board Definitions**: Installed via the Arduino IDE's Board Manager.
- **Required Libraries**:
  - `WiFi.h`: For connecting the ESP32 to a Wi-Fi network.
  - `ESPAsyncWebServer.h`: To set up the asynchronous web server.
  - `DHT.h`: For reading data from the DHT11 sensor.

## Getting Started

### 1. Setting Up the Environment

1. Install the ESP32 board definitions in the Arduino IDE.
2. Install the required libraries through the Arduino Library Manager or by manually downloading them.

### 2. Hardware Connections

- **ESP32 to DHT11 Sensor**:
  - VCC → 3.3V (ESP32)
  - GND → GND (ESP32)
  - Data Pin → GPIO 4 (ESP32)

- **ESP32 to LED**:
  - Anode (+) → GPIO 2 (ESP32)
  - Cathode (-) → GND (ESP32)

### 3. Uploading the Code

1. Connect the ESP32 to your computer via USB.
2. Open the Arduino IDE and load the provided source code.
3. Replace the placeholders in the code with your Wi-Fi SSID and password.
4. Upload the code to the ESP32.
5. Open the Serial Monitor to find the ESP32’s IP address.
