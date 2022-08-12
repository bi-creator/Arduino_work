#include <TFMPlus.h>
#include <SoftwareSerial.h> 
//SoftwareSerial ab(12,13);
TFMPlus s1;
TFMPlus s2;
TFMPlus s3;
TFMPlus s4;
TFMPlus s5;
int16_t a=0;
void setup() {
  Serial.begin(115200);
  delay(20);
  //Serial1.begin(115200);
  delay(20);
   s4.begin( &Serial);

}

void loop() {
   s4.getData(a);
   Serial.println((a));  

}
