#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h> 
TFLI2C tr;

void setup() {
  Serial.begin( 115200);  // Initialize Serial port
    Wire.begin();           // Initialize Wire library

    Serial.println( "TFLI2C example code: 10 JUL 2021");
    tr.Set_I2C_Addr(0x15,0x10);
    delay(1000);
    tr.Save_Settings(0x15);
}

void loop() {
  // put your main code here, to run repeatedly:

}
