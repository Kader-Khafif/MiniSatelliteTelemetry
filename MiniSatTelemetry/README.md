Satellite Telemetry Emulator

A lightweight satellite telemetry project designed for learning and experimenting with embedded systems, sensor integration, and real-time data acquisition.  
This project uses a microcontroller to collect sensor data (battery level, accelerometer, gyroscope, etc.) and streams it over USB/serial to a ground station computer.

Features

- Collects real-time telemetry from onboard modules:
  - Battery Module (voltage monitoring)
  - RTC Module (DS1307) for timestamping
  - IMU Module (MPU6050) for acceleration and orientation
- Outputs structured telemetry over UART/USB
- C-based firmware (no Arduino framework required)
- Cross-platform: runs on Linux/Windows/Mac with a serial terminal

Repository Structure

|--MiniSatTelemetry/
    |--lib
    |  |
    |  |--BatteryModule # Battery sensing
    |  |  |--BatteryModule.cpp
    |  |  |--BatteryModule.h
    |  |  
    |  |--DS1307Module # RTC timekeeping
    |  |  |--DS1307Module.cpp
    |  |  |--DS1307Module.h
    |  |
    |  |--MPU6050Module.c # IMU orientation
    |  |  |--MPU6050Module.cpp
    |  |  |--MPU6050Module.h
    |  |
    |  |--sharedModule.c # Shared helpers/utilities
    |  |  |--sharedModule.cpp
    |  |  |--sharedModule.h
    |  |
    |--src
       |- main.c # Main firmware loop
    |
    |--README # Project documentation
    |--Docs 
    |--include # Header files
    |--test
    |--platformio.ini

Hardware Requirements
Recommended components:
- Microcontroller: ATmega32U4 / ESP32 (adaptable to other MCUs)
- Sensors:
    - DS1307 (I²C RTC)
    - MPU6050 (I²C Accelerometer + Gyroscope)
    - Voltage divider (for battery monitoring)
- Connectivity: USB or UART serial link
- Power supply: 5V USB or battery

Build & Flash Instructions (VS Code + PlatformIO)

This project is set up for [PlatformIO](https://platformio.org/install), which runs as an extension inside Visual Studio Code.  
A `platformio.ini` file is already included in the repository — no extra configuration needed.

 1. Install Requirements
- [Visual Studio Code](https://code.visualstudio.com/)  
- [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

After installation, you’ll see the alien head icon in the left sidebar.

 2. Open the Project
  2.1. Clone the repository:
  ** git clone https://github.com/Kader-Khafif/MiniSatTelemetry.git**
   **cd MiniSatTelemetry**

  2.2. Open the folder in VS Code
  PlatformIO will automatically recognize the platformio.ini file.

  2.3. Build the Firmware
  In VS Code, click the PlatformIO alien icon → Build  (or use Ctrl+Alt+B).
  PlatformIO will compile the firmware for the board defined in platformio.ini.

  2.4. Upload to Board
  Connect your board via USB.
  In VS Code, click Upload (right arrow icon) under PlatformIO.
  Or run from the terminal: **pio run --target upload**

  2.Open the Serial Monitor
  In VS Code, click Monitor (plug icon) under PlatformIO.
  Or run: **pio device monitor**
  Baud rate is already set in platformio.ini (115200).

Once connected, you should see real-time telemetry output
----- Satellite Data -----
Date: 2025-09-25  Time: 22:09:55
Battery: 2.85 V (87.2 %)
Accel X: 1.01, Y: -0.48, Z: 5.49 m/s²
Gyro  X: 0.28, Y: 0.61, Z: -0.05 rad/s
Pitch: -4.95 °, Roll: -10.42 °, Yaw: 78.48 °
Temp: 25.40 °C

---------------------------


