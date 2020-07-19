/*
  IDE 2017
*/


#include<Servo.h>

//Caliabrate
#define lightlevel 1023
#define darklevel 0
//End of Caliabrate

int pos = 0;

//Pin Definition
#define LdrOn1 0
#define LdrOn2 1
#define LdrOn3 2
#define LdrOff1 3
#define LdrOff2 4
#define LdrOff3 5
#define button1 12
#define LED 6
#define lockButton 7
//End of Pin Definition

Servo servo1;

void setup() {
  servo1.attach(6);//Setup Servo
  // initialize the digital pin as an output.
  pinMode(LdrOn1, INPUT_PULLUP);
  pinMode(LdrOn2, INPUT_PULLUP);
  pinMode(LdrOn3, INPUT_PULLUP);
  pinMode(LdrOff1, INPUT_PULLUP);
  pinMode(LdrOff2, INPUT_PULLUP);
  pinMode(LdrOff3, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(lockButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}
void loop() {
  if (digitalRead(button1) == LOW); {
    //Turn on LEDs
    digitalWrite(LED, HIGH);
  }
  int LdrOff1state = analogRead(LdrOff1);
  int LdrOff2state = analogRead(LdrOff2);
  int LdrOff3state = analogRead(LdrOff3);
  int LdrOn1state = analogRead(LdrOn1);
  int LdrOn2state = analogRead(LdrOn2);
  int LdrOn3state = analogRead(LdrOn3);
  if ((LdrOn1state <= lightlevel && LdrOn2state <= lightlevel && LdrOn3state <= lightlevel) && (LdrOff1state >= darklevel && LdrOff2state >= darklevel && LdrOff3state >= darklevel));
  {
    servo1.write(90);//unlock
  }
  if (digitalRead(lockButton) == LOW) {
    servo1.write(0);//lock
    delay(1);//debounce
  }
  /*
    if ((LdrOn1state <= lightlevel && LdrOn2state <= lightlevel && LdrOn3state <= lightlevel) && (LdrOff1state <= lightlevel && LdrOff2state <= lightlevel && LdrOff3state <= lightlevel));
    {
    for (pos = 0; pos <= 90; pos -= 1)
    {
      servo1.write(pos);
      delay(7.5);
    }*/
}

