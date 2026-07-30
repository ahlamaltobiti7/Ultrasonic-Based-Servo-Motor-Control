# Ultrasonic Sensor Controlled Servo Motor using Arduino Uno

## Project Overview

This project demonstrates how to control an **SG90 Servo Motor** using an **HC-SR04 Ultrasonic Sensor** and an **Arduino Uno**.

The ultrasonic sensor continuously measures the distance between the sensor and an object. Based on the measured distance, the Arduino controls the servo motor rotation angle.

The project was designed, simulated, and tested using **Tinkered AI** to verify the circuit connections and observe the system behavior before implementation.

During testing, the **same Arduino program** was used for both experiments. The only changes made were the **distance threshold** and **servo rotation angle values** to evaluate different operating conditions.

Two configurations were tested:

- **Configuration 1:** Object detection within **10 cm** → Servo rotates to **90°**.
- **Configuration 2:** Object detection within **15 cm** → Servo rotates to **180°**.

---

# Project Objectives

- Understand the working principle of ultrasonic distance measurement.
- Interface the HC-SR04 sensor with Arduino Uno.
- Control an SG90 servo motor using PWM signals.
- Calculate distance using the speed of sound equation.
- Test different distance thresholds and servo angles using the same code.
- Gain practical experience in embedded systems and circuit simulation.

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

Arduino Uno is the main controller of the system. It reads the distance data from the ultrasonic sensor, processes the measurements, and generates the PWM signal required to control the servo motor.

---

## HC-SR04 Ultrasonic Sensor

The HC-SR04 sensor measures distance by transmitting ultrasonic waves at **40 kHz**.

When the waves hit an object, they are reflected back to the sensor. The Arduino calculates the distance based on the time taken by the reflected signal to return.

---

## SG90 Servo Motor

The SG90 Micro Servo is controlled by a PWM signal from the Arduino and can rotate from **0° to 180°** depending on the received control signal.

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

The sensor emits ultrasonic waves and receives the reflected signal through the Echo pin.

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
- **0.0343 cm/μs** represents the speed of sound in air.
- Division by **2** is required because the wave travels to the object and back.

---

# Software Configurations and Testing

The same Arduino code was used for both experiments.

The program structure remained unchanged, while only the following values were modified:

- Detection distance threshold.
- Servo rotation angle.

These changes were used to test how different parameters affect the system response.

---

# Configuration 1

## Parameters

| Parameter | Value |
|-----------|------:|
| Distance Threshold | 10 cm |
| Servo Angle | 90° |

## Description

In the first experiment, the system was configured to detect objects within **10 cm**.

When the measured distance is **10 cm or less**, the servo rotates to **90°**.

When the object moves away from the detection range, the servo returns to its initial position at **0°**.

---

# Configuration 2

## Parameters

| Parameter | Value |
|-----------|------:|
| Distance Threshold | 15 cm |
| Servo Angle | 180° |

## Description

For the second experiment, the same Arduino program was used with modified parameter values:

```cpp
const int DISTANCE_THRESHOLD = 15;
const int SERVO_ANGLE = 180;
```

Only the distance threshold and servo angle were changed.

When the measured distance is **15 cm or less**, the servo rotates to **180°**.

When the object moves beyond the threshold, the servo returns to **0°**.

---

# Testing Comparison

| Feature | Configuration 1 | Configuration 2 |
|---------|-----------------|-----------------|
| Arduino Code | Same Program | Same Program |
| Distance Threshold | 10 cm | 15 cm |
| Servo Rotation | 90° | 180° |
| Modified Values | Distance and Angle | Distance and Angle |

---

# Tinkered AI Simulation

The complete circuit was designed, simulated, and tested using **Tinkered AI**.

The simulation was used to:

- Build the Arduino circuit.
- Verify the wiring connections.
- Test the ultrasonic sensor response.
- Observe the servo motor movement.
- Validate the program before implementation.

## Simulation Link

🔗 https://app.tinkered.ai/p/b1c0b35a-e734-4411-82c9-bbb5635e4397

---

## Simulation Image

The following image shows the complete simulation created using **Tinkered AI**.

<p align="center">
  <img src="Tinkered AI Simulation.png" alt="Tinkered AI Simulation" width="800">
</p>

---

# Circuit Diagram

The following image shows the complete wiring connection between Arduino Uno, HC-SR04 ultrasonic sensor, and SG90 servo motor.

<p align="center">
  <img src="Circuit Diagram1.jpg" alt="Circuit Diagram" width="700">
</p>

<p align="center">
  <img src="Circuit Diagram2.jpg" alt="Circuit Diagram" width="700">
</p>

---

# Demonstration Videos

## Configuration 1 (10 cm → 90°)

This video demonstrates the first test configuration. The servo rotates to **90°** when an object is detected within **10 cm**, then returns to **0°** when the object moves away.

🎥 **Video:** `Configuration1.mp4`

---

## Configuration 2 (15 cm → 180°)

This video demonstrates the second test configuration. The servo rotates to **180°** when an object is detected within **15 cm**, then returns to **0°** when the object moves away.

🎥 **Video:** `Configuration2.mp4`

---

# Project Structure

```
Ultrasonic-Servo-Control/
│
├── UltrasonicServo_Control.ino
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
- Embedded Systems Development
- HC-SR04 Ultrasonic Sensor Integration
- Servo Motor Control using PWM
- Distance Measurement Techniques
- Circuit Design and Wiring
- Simulation and Testing using Tinkered AI
- Hardware Debugging
- Parameter Adjustment and System Testing

---

# Future Improvements

- Add an LCD/OLED display to show real-time distance.
- Add a buzzer for object detection alerts.
- Use ESP32 for wireless monitoring.
- Add multiple sensors for advanced applications.
- Improve distance stability using filtering techniques.

---
