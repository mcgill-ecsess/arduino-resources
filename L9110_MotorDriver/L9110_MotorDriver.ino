/*
- You need to connect PWM pins to the L9110 motor driver. These pins are denoted by ~ on the Arduino.

In this demo code: (L9110 Motor Driver --> Arduino)
- IN1 --> 5~
- IN2 --> 6~
- IN3 --> 9~
- IN4 --> 10~
- VCC --> External 6V to 9V power source (usually red wire)
- GND --> External ground and Arduino GND (usually black wire)

NOTE!: Output value range of analogWrite() is 0 to 255.

Reference: https://electropeak.com/learn/interfacing-l9110s-dual-channel-h-bridge-motor-driver-module-with-arduino/
Code reference: https://github.com/notkaramel/Pepperoni/blob/main/Pepperoni.ino

Created by Antoine Phan (@notkaramel) as ECSESS VP Technical Development
*/

// Define the PWM pins locations
#define MOTOR_1A 10
#define MOTOR_1B 11


void setup() {
    // Set all pins as output
    pinMode(MOTOR_1A, OUTPUT);
    pinMode(MOTOR_1B, OUTPUT);
}

void loop() {
    analogWrite(MOTOR_1A, 255);
    analogWrite(MOTOR_1B, 0);

    delay(2000);

    analogWrite(MOTOR_1A, 0);
    analogWrite(MOTOR_1B, 0);

    delay(2000);

    analogWrite(MOTOR_1A, 0);
    analogWrite(MOTOR_1B, 255);

    delay(2000);
}
