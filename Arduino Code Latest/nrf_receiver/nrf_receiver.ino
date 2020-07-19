
//(C) 2017 Sim Shang En

#include <LowPower.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int dataReceived;
// Config
RF24 radio(7, 8); //ce and cs
const uint64_t pipe = 0x123456789ABC; //address
#define RELAY 2
#define MUTE 4
#define BUZZER 3
// Config
bool messagenotreceived = true;
#define DEBUG 1 //DEBUG=1 enable debug, DEBUG=0 disbale debug

void setup(void) {
  #if DEBUG == 1
  Serial.begin(115200); //Debug line
  #endif
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  radio.setPALevel(RF24_PA_MAX);//max power
  radio.setChannel(100);//set comms channel
  radio.setDataRate(RF24_250KBPS);//slowest data rate. For NRF24L01+ only!! More range!!
  radio.setAutoAck(1); //ACK Packet
  pinMode(RELAY, OUTPUT);
  pinMode(MUTE, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop(void) {
  if (radio.available()) {
    if (messagenotreceived) {
      radio.read( &dataReceived, sizeof(dataReceived) );
    }
    #if DEBUG == 1
    Serial.print("Data received = ");//debug
    Serial.println(dataReceived);//debug
    #endif
    bool buz = true;
    digitalWrite(RELAY, LOW);
    while (dataReceived == 124) {
      #if DEBUG == 1
      Serial.println("ACCEPTED");
      #endif
      //once received, never exit
      messagenotreceived = false;
      digitalWrite(RELAY, HIGH);//activate relay
      if (buz == true) {
        digitalWrite(BUZZER, HIGH); //buzzer
      }
      if (digitalRead(MUTE) == LOW) {
        buz = false;
        digitalWrite(BUZZER, LOW); //buzzer off
        while (1) {
          //non exiting loop
          LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
          //sleep
        }
      }
    }
  }
  else {
    #if DEBUG == 1
    Serial.println("No data received!");
    #endif
  }
}
