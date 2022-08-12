#include <Arduino.h>     // every sketch needs this
#include <Wire.h>        // instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.2.0
TFLI2C t;
int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = 0x12;  // use this default I2C address or
 int16_t a,b,c,d,e;                               // set variable to your own value
void setup()
{
    Serial.begin( 115200);  // initialize serial port
    Wire.begin();           // initialize Wire library
    Serial.println( "TFLI2C example code simplified"); // say "Hello!"
    Serial.println( "4 NOV 2021");                     // and add date
}
void loop()
{
   t.getData(a,0x11);
  if(a==0)
  {
    a=800;
  }
  t.getData(b,0x12);
    if(b==0)
    {
      b=800;
    }
  t.getData(c,0x13);
  if(c==0)
  {
    c=800;
  }
    t.getData(d,0x15);
    if(d==0)
    {
      d=800;
    }
    t.getData(e,0x14);
    if(e==0)
    {
      e=800;
    }
    //Serial.print("a=");
    //Serial.println(a);
    //Serial.print("b=");
    //Serial.println(b);
    //Serial.print("c=");
    //Serial.println(c);
    //Serial.print("d=");
    //Serial.println(d);
    Serial.print("e=");
    Serial.println(e);
    
}
