RotaryEncoder encoderA(8, 9);
RotaryEncoder encoderB(11, 28);

void setup(){
  encoderA.begin();
  encoderB.begin();
}

void loop(){
  encoderA.update();
  encoderB.update();
  
  encoder0Pos = encoderA.getPosition();
  encoder1Pos = encoderB.getPosition();
  
  SerialPrintln(encoder0Pos);  
  SerialPrintln(encoder1Pos);
}
