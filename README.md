## Touch-Activated Ultrasonic Distance Measurement System

This project involves creating a **touch-activated system** that triggers an **ultrasonic sensor** to measure distance and display the result on an **I2C LCD screen**. The system is designed to measure the distance of objects in front of the ultrasonic sensor, but only when the user activates the system by touching a designated touch sensor.

## Components Required

- **Arduino Mega 2560**
- **I2C LCD (16x2) Display**
- **TTP223 Touch Sensor**
- **HC-SR04 Ultrasonic Sensor**
- **Jumper wires and Breadboard**

## Connection Details

| **Device**         | **Pin Name**    | **Connection** |
|--------------------|-----------------|----------------|
| **I2C LCD**        | VCC             | 5V             |
|                    | GND             | GND            |
|                    | SDA             | Pin 20         |
|                    | SCL             | Pin 21         |
| **Touch Sensor**   | VCC             | 5V             |
|                    | GND             | GND            |
|                    | OUT             | Pin 24         |
| **Ultrasonic Sensor**| VCC             | 5V             |
|                    | GND             | GND            |
|                    | TRIGGER         | Pin 22         |
|                    | ECHO            | Pin 23         |

## Working Principle

1. **Initialization:**
   - Upon powering up the system, the Arduino initializes the **I2C LCD**, the **Touch Sensor**, and the **Ultrasonic Sensor**. The LCD displays a default message".

2. **Touch Activation:**
   - The system is idle until the user touches the **Touch Sensor** (connected to **Pin 24**). The touch sensor sends a signal to the Arduino, which triggers the ultrasonic sensor to measure the distance.

3. **Ultrasonic Distance Measurement:**
   - Once activated, the Arduino sends a **HIGH** signal to the **TRIGGER** pin (Pin 22) of the ultrasonic sensor. The sensor emits an ultrasonic pulse, which bounces off objects and returns to the **ECHO** pin (Pin 23).
   - The Arduino calculates the distance based on the time difference between sending and receiving the pulse using the formula:

The formula for calculating distance using an ultrasonic sensor is:

	Distance = (Time × Speed of Sound) / 2

4. **Display Distance:**
   - The calculated distance is displayed on the **I2C LCD** in centimeters.

5. **Repeat:**
   - The system waits for another touch event to trigger the measurement again.

## Applications

- **Interactive Distance Measurement**: Use in systems that require user-triggered distance measurements, such as object detection or proximity-based applications.
- **Educational Tool**: A great project for beginners to learn about sensors, I2C communication, and Register Level programming.

## How to Use

1. Connect the components as shown in the **Connections** section.
2. Upload the code to your **Arduino Mega 2560**.
3. Upon powering the system, the LCD will show a default message.
4. Touch the **Touch Sensor** to activate the system, triggering the ultrasonic sensor to measure and display the distance.
5. The distance will be shown on the **I2C LCD** in real-time.

