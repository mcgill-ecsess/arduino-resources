unsigned int pressCount;
bool onPress = false;
void setup() {
  pinMode(8,INPUT);
  Serial.begin(9600);
}
void loop() {
  if(digitalRead(8)==HIGH && onPress==false){
    pressCount++;
    onPress = true;
}
onPress = false;
delay(100); // small delay
Serial.println("You have pressed the button "+String(pressCount)+" times");
}