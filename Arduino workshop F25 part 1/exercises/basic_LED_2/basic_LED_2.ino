void setup(){
    pinMode(6,OUTPUT);
}
void loop(){
    for(unsigned char i = 0;i<255;i++){
       analogWrite(6,i);
       delay(10);
    }
    for(unsigned char i = 255;i>0;i--){
       analogWrite(6,i);
       delay(10);
    }
}