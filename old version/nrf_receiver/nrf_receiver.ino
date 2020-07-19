#include <LowPower.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int dataReceived;
// Config
RF24 radio(9, 10);
const uint64_t pipe = 0x124581234ABC;
#define RELAY 2
#define MUTE 4
#define BUZZER 3
// Config
bool messagereceived = false;

void setup(void) {
  Serial.begin(9600); //Debug line
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  radio.setPALevel(RF24_PA_MAX);//max power
  radio.setChannel(124);//set comms channel
  radio.setDataRate(RF24_250KBPS);//slowest data rate. For NRF24L01+ only!! More range!!
  radio.setAutoAck(1); //ACK Packet
  pinMode(RELAY, OUTPUT);
  pinMode(MUTE, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop(void) {
  if (radio.available()) {
    while (radio.available())
    {
      if (messagereceived) {
        radio.read( &dataReceived, sizeof(dataReceived) );
      }
    }
    //Serial.print("Data received = ");//debug
    //Serial.println(dataReceived);//debug
    bool buz = true;
    digitalWrite(RELAY, LOW);
    while (dataReceived == 1) {
      //once received, never exit
      messagereceived = true;
      digitalWrite(RELAY, HIGH);//activate relay
      if (buz == true) {
        digitalWrite(BUZZER, HIGH); //buzzer
      }
      if (digitalRead(MUTE) == LOW) {
        buz = false;
        digitalWrite(BUZZER, LOW); //buzzer off
        while (1 == 1) {
          //1==1 always returns true =)
          //run forever until reset
          //delay(999999999999999999999999999999999999);
          LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
        }
      }
    }
  }
  else {
    Serial.println("No data received!");
  }
}
