//Client running an ESP8266 and arduino nano to run a serial light strip
//Designed by: Jackson Walker
//May 2018

#include <SoftwareSerial.h>

#define rxPin 9
#define txPin 8
#define inverted 0



void setup() {
  SoftwareSerial softSerial =  SoftwareSerial(rxPin, txPin, inverted);
  softSerial.begin(115200);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
