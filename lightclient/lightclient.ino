//Client running an ESP8266 and arduino nano to run a serial light strip
//Designed by: Jackson Walker
//May 2018

#include <SoftwareSerial.h>

#define rxPin 9
#define txPin 8
SoftwareSerial softSerial =  SoftwareSerial(rxPin, txPin);
String AP = "COMCAST_SUCKS";
String PW = "sodoesverizon";
int ssLed = 6;
int countTrueCommand;
int countTimeCommand;
boolean found = false; 
int valSensor = 1;

void setup() {
 
  Serial.begin(9600);
  while (!Serial) {
    ;} // wait for serial port to connect. Needed for native USB port only}
  softSerial.begin(115200);

  if(Serial){
    Serial.print("Serial successful!");
    if(softSerial)
    {
      Serial.print("softSerial successful!");
    }
  }
  pinMode(ssLed, OUTPUT);  

}

void loop() {
  softSerial.write("AT+GMR");
  digitalWrite(ssLed, HIGH);
  delay(150);
  digitalWrite(ssLed, LOW);
  delay(150);

  if (softSerial.available()) {      // If anything comes in Serial (USB),
    Serial.println(char(softSerial.read()));   // read it and send it out Seria1 (pins 0 & 1)
    Serial.println("we got something");
  }
  if (Serial.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    softSerial.write(Serial.read());   // read it and send it out Serial (USB)
  }

}


void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    softSerial.println(command); //at+cipsend
    if(softSerial.find(readReplay)) //ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }

