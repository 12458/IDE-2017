#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int msg[1];
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
#define SW1 7

void setup(void) {
  pinMode(SW1, INPUT_PULLUP);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setPALevel(RF24_PA_MAX);//max power
  radio.setChannel(124);//set comms channel
  radio.setDataRate(RF24_250KBPS);//slowest data rate. For NRF24L01+ only!! More range!!
  radio.setAutoAck(1);
}

void loop(void) {
  if (digitalRead(SW1) == LOW) {
    Serial.println("1");
    msg[0] = 1;
    radio.write(msg, 1);
    delay(1000);
  }
}
