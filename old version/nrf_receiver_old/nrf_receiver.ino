#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int msg[1];
// Config
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
#define RELAY 2
#define MUTE 4
#define BUZZER 3
// Config

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
    int done;
    bool buz = true;
    digitalWrite(RELAY, LOW);
    while (!done) {
      done = radio.read(msg, 1);
      Serial.println("ACT");
      while (msg[0] == 1) {
        digitalWrite(RELAY, HIGH);
        if (buz == true) {
          digitalWrite(BUZZER, HIGH); //buzzer
        }
        if (digitalRead(MUTE) == LOW) {
          buz = false;
          digitalWrite(BUZZER, LOW); //buzzer off
          while(1==1){
            //run forever until reset
            delay(999999999999999999999999999999999999);
          }
        }
      }
    }
  }
  else {
    Serial.println("No data received!");
  }
}
