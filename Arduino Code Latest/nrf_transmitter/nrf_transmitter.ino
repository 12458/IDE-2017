#include <SPI.h>
#include "RF24.h"
#include "LowPower.h"
//#define button1 4 //Switch w cover !old!
#define interruptpin 2 //Switch with cover
RF24 radio(7, 8);
int dataTransmitted;
const uint8_t pipe = 0x123456789ABC;//address

void wakeUp() {
  //if (digitalRead(button1) == LOW) { //Trigger
  //Serial.println("Button Triggered!");
  radio.powerUp();
  dataTransmitted = 124;
  radio.write( &dataTransmitted, sizeof(dataTransmitted) );
  radio.powerDown();
  //Serial.println(dataTransmitted);// debug
  //}
}

void setup() {
  //Serial.begin(4800); //Debug port
  //pinMode(button1, INPUT_PULLUP);
  pinMode(interruptpin, INPUT_PULLUP);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);//MAX POWER!!!
  radio.setChannel(100);//comms channel
  radio.setDataRate(RF24_250KBPS);//slowest data rate. For NRF24L01+ only!! More range!!
  radio.setAutoAck(1);
  radio.openWritingPipe(pipe);
  radio.powerDown();
  attachInterrupt(digitalPinToInterrupt(interruptpin), wakeUp, FALLING);
}


void loop() {
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

