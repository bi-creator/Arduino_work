#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
int16_t a,b,c;
void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(115200);
   while(!Serial){
    delay(10);
  }

}
void forward()
{  Serial.println("o");
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
  if(a<200||b<200||c<200)
  {
 
    halt();
    
  }
  else
  {
  
      analogWrite(5,50);
      digitalWrite(4,HIGH);
     
      delay(100);
  }
}
void halt()
{
    analogWrite(5,0);
 
}

void loop() {
  forward();

}
