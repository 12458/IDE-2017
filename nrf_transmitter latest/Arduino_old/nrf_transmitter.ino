#include <SPI.h>
#include "RF24.h"
#include "LowPower.h"
#define button1 7 //Switch w cover
#define interruptpin 2
#define timertimeout 3000 //ms
#define radiodelay 400 //ms
RF24 radio(9, 10);
int timer;
int dataTransmitted;
const uint64_t pipe = 0x124581234ABC;//address

void wakeUp() {
  timer = 0;
}

void setup() {
  Serial.begin(115200);
  pinMode(button1, INPUT_PULLUP);
  pinMode(interruptpin, INPUT_PULLUP);
  timer = 0;
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);//MAX POWER!!!
  radio.setChannel(124);//comms channel
  radio.setDataRate(RF24_250KBPS);//slowest data rate. For NRF24L01+ only!! More range!!
  radio.setAutoAck(1);
  radio.openWritingPipe(pipe);
}


void loop() {
  attachInterrupt(digitalPinToInterrupt(interruptpin), wakeUp, LOW);
  while (timer < timertimeout) {
    if (digitalRead(button1) == LOW) { //POWER
      radio.powerUp();
      timer = 0;
      dataTransmitted = 1;
      radio.write( &dataTransmitted, sizeof(dataTransmitted) );
      radio.powerDown();
      delay(radiodelay);
      //Serial.println(dataTransmitted);// debug
    }
    delay(1);
    timer = timer + 1;
  }
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  radio.powerDown();
}

