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
#define LEFT_A 5
#define LEFT_B 6

#define RIGHT_A 9
#define RIGHT_B 10


void setup() {
    // Set all pins as output
    pinMode(LEFT_A, OUTPUT);
    pinMode(LEFT_B, OUTPUT);
    pinMode(RIGHT_A, OUTPUT);
    pinMode(RIGHT_B, OUTPUT);
}

void loop() {
  
}

/**
 * Go forward at a certain speed
 * @param speed The speed to go forward at (0 to 255)
 */
void goForward(int speed) {

}


void rightForward()     // Right wheel go forward
{
    analogWrite(B_1A, speed);
    analogWrite(B_1B, stop);
}

void rightBackward()    // Right wheel go backward
{
    analogWrite(B_1A, stop);
    analogWrite(B_1B, speed);
}

void leftForward()      // Left wheel go forward
{
    analogWrite(A_1A, stop);
    analogWrite(A_1B, speed);
}

void leftBackward()     // Left wheel go backward
{
    analogWrite(A_1A, speed);
    analogWrite(A_1B, stop);
}

void forward()         // Both wheels go forward
{
    leftForward();
    rightForward();
}

void turnLeft(int delayTime)    // Turn left for a certain amount of time
{

    leftBackward();
    rightForward();

    delay(delayTime);
}

void turnRight(int delayTime)   // Turn right for a certain amount of time
{
    leftForward();
    rightBackward();

    delay(delayTime);
}
