# Voice-Controlled Smart Elevator using ESP32

## Overview

This project presents a Voice-Controlled Smart Elevator system designed to improve accessibility and convenience in vertical transportation. The elevator can be controlled through voice commands transmitted via Bluetooth and processed by an ESP32 microcontroller. A manual push-button override is also provided for reliable operation in noisy environments or during voice recognition failures.

## Features

* 🎤 Voice-controlled elevator operation
* 📶 Bluetooth communication with ESP32
* ⚙️ PWM-based motor speed control for smooth movement
* 🚪 Automatic double-door mechanism
* 🔘 Manual push-button override control
* 📟 LCD display for command confirmation and floor status
* 🔋 12V power supply with 5Ah battery backup
* 📍 IR sensor-based floor detection
* 🛡️ Hybrid control system for enhanced reliability

## Hardware Components

* ESP32 Microcontroller
* Bluetooth Module
* Drum Motor
* DC Motors
* L298 Motor Driver
* IR Sensors
* LCD Display
* Push Buttons
* Relay Module
* 12V Adapter
* 5Ah Backup Battery
* Pulley Mechanism

## System Architecture

1. Voice commands are sent through a mobile voice-bot application via Bluetooth.
2. ESP32 receives and processes the commands.
3. PWM controls motor speed for smooth elevator movement.
4. IR sensors detect floor positions.
5. LCD displays elevator status and command feedback.
6. Manual buttons provide backup control when needed.

## Applications

* Smart Buildings
* Accessibility Assistance
* Touchless Elevator Systems
* IoT-Based Automation Projects

## Future Improvements

* Multi-language voice recognition
* Enhanced security and authentication
* Mobile application integration
* Personalized user preferences
* Smart building ecosystem connectivity

## Technologies Used

* ESP32
* Embedded C
* Arduino IDE
* Bluetooth Communication
* PWM Motor Control
* Voice Recognition Application

## Project Outcome

Successfully developed a prototype voice-controlled elevator capable of smooth vertical movement, automated door operation, floor detection, LCD feedback, and reliable operation through both voice and manual controls.
