#include <Servo.h> 

Servo servo;
bool buttonLastPressed=false;
const int buttonPin = 2;
int state=0;
int buttonState=0;
void setup() 
{ 
  pinMode(buttonPin, INPUT);
  servo.attach(9);
  servo.write(0);  // set servo to mid-point
} 

void loop() {
  buttonState = digitalRead(buttonPin);
  state = servo.read();
  if(buttonState==HIGH && buttonLastPressed == false){
    servo.attach(9);
    if(state == 180){
      servo.write(0);
      delay(1000);
    }
    else if(state == 0){
      servo.write(180);
      delay(1000);
    }
    buttonLastPressed = true;
  }
  else if(buttonState == LOW && buttonLastPressed == true){
    buttonLastPressed = false;
  }
  else if(buttonState == LOW && buttonLastPressed == false && (servo.read()==180 || servo.read() == 0)){
    servo.detach();
  }
  
  } 

