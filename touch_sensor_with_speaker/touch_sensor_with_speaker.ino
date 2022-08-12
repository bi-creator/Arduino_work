#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini sp;
void setup() {
   Serial2.begin(9600);
  Serial.begin(115200);
  if (!sp.begin(Serial2)) 
  {  
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  sp.volume(20);  //Set volume value. From 0 to 30
  sp.play(1);  //Play the first mp3

  pinMode(8,INPUT);

}
int x;

void loop() {
  x=digitalRead(8);
  Serial.println(x);
  if(x==1){
  sp.play(2);
  delay(5000);
  }
  
  
  

}
