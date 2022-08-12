#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>  // TFLuna-I2C Library v.0.1.1
TFLI2C t1;

int a,b;
void setup() {
   Serial.begin( 115200);  // Initialize Serial port
    Wire.begin();           // Initialize Wire library

}

void loop() {
 t1.getData(a,0x14);
 t1.getData(b,0x10);
 //Serial.println(a);
 //Serial.println(b);
 if(a<30)
 {
  Serial.println("object at 1");
 }
 else if(b<30)
 {
  Serial.println("object at 2");
 }
 else
 {
  Serial.println("object not found ");
 }

}
