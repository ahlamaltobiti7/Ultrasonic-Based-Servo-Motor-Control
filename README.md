# Ultrasonic Sensor Controlled Servo Motor using Arduino Uno

## Project Overview

This project demonstrates how to control an **SG90 Servo Motor** using an **HC-SR04 Ultrasonic Sensor** and an **Arduino Uno**.

The ultrasonic sensor continuously measures the distance between the sensor and an object. Based on the measured distance, the Arduino controls the servo motor rotation angle.

Two different software configurations were implemented and tested:

- **Configuration 1:** The servo rotates to **90°** when an object is detected within **10 cm**.
- **Configuration 2:** The servo rotates to **180°** when an object is detected within **15 cm**.

The project was designed and simulated using **Tinkered AI** to verify the circuit connections and test the Arduino program behavior before implementation.

---

# Project Objectives

- Understand the working principle of the HC-SR04 ultrasonic sensor.
- Interface an ultrasonic sensor with Arduino Uno.
- Control an SG90 servo motor using PWM signals.
- Calculate distance using the speed of sound equation.
- Test different distance thresholds and servo angles.
- Gain practical experience in embedded systems and hardware simulation.

---

# Hardware Components

| Component | Model | Quantity |
|-----------|-------|---------:|
| Microcontroller | Arduino Uno | 1 |
| Ultrasonic Sensor | HC-SR04 | 1 |
| Servo Motor | SG90 Micro Servo | 1 |
| Breadboard | Standard Breadboard | 1 |
| Jumper Wires | Male-to-Male | Several |

---

# Hardware Description

## Arduino Uno

Arduino Uno is the main controller of the system. It reads the ultrasonic sensor data, calculates the distance, and generates the PWM control signal required to rotate the servo motor.

---

## HC-SR04 Ultrasonic Sensor

The HC-SR04 measures distance by transmitting ultrasonic waves at **40 kHz**.

When the transmitted waves hit an object, they are reflected back to the sensor. The Arduino calculates the distance based on the time required for the echo signal to return.

---

## SG90 Servo Motor

The SG90 Micro Servo is controlled using a PWM signal from the Arduino and can rotate between **0° and 180°**.

---

# Circuit Connections

## Power Connections

| Arduino Pin | Connection |
|-------------|------------|
| 5V | Breadboard Positive Rail (+) |
| GND | Breadboard Ground Rail (-) |

---

## HC-SR04 Connections

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC | 5V |
| GND | GND |
| Trig | Digital Pin 9 |
| Echo | Digital Pin 10 |

---

## Servo Motor Connections

| Servo Wire | Arduino Connection |
|------------|-------------------|
| Red | 5V |
| Brown/Black | GND |
| Orange/Yellow | Digital Pin 7 |

---

# Working Principle

The Arduino sends a **10 μs trigger pulse** to the HC-SR04 sensor.

The sensor transmits ultrasonic waves and waits for the reflected signal through the Echo pin.

The Arduino measures the echo duration using:

```cpp
pulseIn(ECHO_PIN, HIGH);
```

The distance is calculated using:

```
Distance = (Duration × 0.0343) / 2
```

Where:

- **Duration** is the echo travel time in microseconds.
- **0.0343 cm/μs** represents the speed of sound.
- Division by **2** is required because the wave travels to the object and back.

---

# Software Configuration 1

## Parameters

| Parameter | Value |
|-----------|------:|
| Distance Threshold | 10 cm |
| Servo Angle | 90° |

## Description

In the first configuration, the servo motor rotates to **90°** when an object is detected at a distance of **10 cm or less**.

When the object moves away, the servo returns to its initial position at **0°**.

---

# Software Configuration 2

## Parameters

| Parameter | Value |
|-----------|------:|
| Distance Threshold | 15 cm |
| Servo Angle | 180° |

## Description

The second configuration uses adjustable parameters:

```cpp
const int DISTANCE_THRESHOLD = 15;
const int SERVO_ANGLE = 180;
```

This approach makes the code easier to modify and reuse.

When an object is detected within **15 cm**, the servo rotates to **180°**.

When the object moves beyond the threshold, the servo returns to **0°**.

---

# Configuration Comparison

| Feature | Configuration 1 | Configuration 2 |
|---------|-----------------|-----------------|
| Distance Threshold | 10 cm | 15 cm |
| Servo Movement | 90° | 180° |
| Programming Method | Fixed values | Adjustable constants |
| Flexibility | Basic | Higher |

---

# Tinkered AI Simulation

The complete circuit was designed, simulated, and tested using **Tinkered AI**.

The simulation was used to:

- Build the Arduino circuit.
- Verify sensor and servo connections.
- Test the Arduino code.
- Observe the servo response according to distance changes.

## Simulation Link

🔗 https://app.tinkered.ai/p/b1c0b35a-e734-4411-82c9-bbb5635e4397

---

## Simulation Image

The following image shows the complete project simulation created using **Tinkered AI**.

<p align="center">
  <img src="Simulation.png" alt="Tinkered AI Simulation" width="800">
</p>

---

# Circuit Diagram

The following image shows the wiring connections between the Arduino Uno, HC-SR04 ultrasonic sensor, and SG90 servo motor.

<p align="center">
  <img src="Circuit.png" alt="Circuit Diagram" width="700">
</p>

---

# Demonstration Videos

## Configuration 1 (10 cm → 90°)

This video demonstrates the first configuration. When an object approaches within **10 cm**, the servo rotates to **90°**. When the object moves away, it returns to **0°**.

🎥 **Video:** `Configuration1.mp4`

---

## Configuration 2 (15 cm → 180°)

This video demonstrates the second configuration. When an object approaches within **15 cm**, the servo rotates to **180°**. When the object moves away, it returns to **0°**.

🎥 **Video:** `Configuration2.mp4`

---

# Project Structure

```
Ultrasonic-Servo-Control/
│
├── UltrasonicServo_10cm_90deg.ino
├── UltrasonicServo_15cm_180deg.ino
├── README.md
├── Simulation.png
├── Circuit.png
├── Configuration1.mp4
└── Configuration2.mp4
```

---

# Applications

- Automatic Doors
- Smart Trash Bins
- Parking Barrier Systems
- Object Detection Systems
- Robotics Applications
- Contactless Control Systems

---

# Skills Gained

Through this project, I gained practical experience in:

- Arduino Programming
- Embedded Systems
- Ultrasonic Sensor Integration
- Servo Motor Control using PWM
- Distance Measurement
- Circuit Design
- Hardware Simulation using Tinkered AI
- Debugging and Testing
- Parameter Optimization

---

# Future Improvements

- Add an LCD/OLED display to show distance values.
- Add a buzzer for object detection alerts.
- Use ESP32 for wireless monitoring.
- Add multiple sensors for advanced detection.
- Improve measurement stability using filtering techniques.

---

Taif University
