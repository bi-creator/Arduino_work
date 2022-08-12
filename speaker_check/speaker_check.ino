#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini m;
void setup() {
  Serial.begin(9600);
  m.begin( Serial);
   m.volume(20);
  m.play(3);

}

void loop() {
  // put your main code here, to run repeatedly:

}
