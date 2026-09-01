# Automatic Hybrid Power Management System

An Arduino-based hybrid power management system designed to monitor multiple energy sources and automatically manage power selection based on source availability and predefined priority.

## Overview

The system integrates solar, wind, mains, and battery backup to provide continuous power availability. Voltage levels from the connected sources are monitored using voltage sensor modules, and the Arduino controls relay modules to switch between available power sources.

The system also provides real-time information through a 16×2 LCD display.

## Features

- Automatic power source selection
- Priority-based switching between available sources
- Real-time voltage monitoring
- Solar and wind energy integration
- Relay-based source switching
- Battery voltage monitoring
- Battery charging and discharging status indication
- LCD-based system monitoring

## Working Principle

The Arduino continuously monitors the voltage levels of the connected power sources.

Based on source availability and the configured priority, the system automatically selects an appropriate power source and controls the corresponding relay module.

The LCD provides real-time system information, including voltage readings, source status, and battery charging or discharging information.

## Hardware Used

- Arduino Uno
- Solar Panel
- Wind Energy Generation Setup
- Voltage Sensor Modules
- 16×2 LCD Display with I2C Interface
- Relay Modules
- Lithium-Ion Battery
- Battery Charging Module
- DC-DC Converter Module
- LEDs
- Perfboard and Connecting Wires

## Software

- Arduino IDE
- Embedded C / Arduino Programming

## Future Enhancements

- IoT-based remote monitoring
- Data logging and energy usage analysis
- Advanced battery management
- MPPT-based solar power optimization

