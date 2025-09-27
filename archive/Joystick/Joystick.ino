/*
To use the joystick, you need to connect the X and Y pins to 2 analog pins.
The SW (switch) pin can go to any digital pin.

In this demo code: (Joystick --> Arduino)
- VR-X --> A0 (analogRead would return value 0-1023)
- VR-Y --> A1
- SW  --> 2
- VCC --> 5V
- GND --> GND


Resource: https://arduinogetstarted.com/tutorials/arduino-joystick
Made by Antoine Phan (@notkaramel) as ECSESS VP Technical Development
*/

#define VRx A0
#define VRy A1
#define SW 2 

void setup() {
  pinMode(SW, INPUT_PULLUP);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  int swValue = digitalRead(SW);

  Serial.print("X = ");
  Serial.print(xValue);
  Serial.print("\tY = ");
  Serial.print(yValue);
  Serial.print("\tSW = ");
  Serial.println(swValue);

  delay(200); // Delay for 100ms
}