#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
int16_t a,b,c,d,e;
int o;
void setup() {
  Serial.begin(9600);
  //Serial1.begin(9600);
   pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Wire.begin();

}
void forward()
{
   
         
    t.getData(a,0x11);
    Serial.println(a);     
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
  if(a<50||b<50||c<50)
  {
   
    halt();
    
    
  }
  else
  {
        analogWrite(3,0);
        // digitalWrite(2,HIGH);
         analogWrite(5,155);
         digitalWrite(4,HIGH);
         analogWrite(7,155);
         digitalWrite(6,LOW);
         delay(100);
  
  }
}
void halt()
{
   analogWrite(3,0);
   analogWrite(5,0);
   analogWrite(7,0);
}
void left()
{
      analogWrite(3,50);
      digitalWrite(2,LOW);
      analogWrite(5,50);
      digitalWrite(4,LOW);
      analogWrite(7,50);
      digitalWrite(6,LOW);
      delay(100);
}
void right()
{
      analogWrite(3,50);
      digitalWrite(2,HIGH);
      analogWrite(5,50);
      digitalWrite(4,HIGH);
      analogWrite(7,50);
      digitalWrite(6,HIGH);
      delay(100);
}
void loop() {
 o= Serial.read();
 Serial.println(o);
 if (o==1)
 {
  forward();
 }
 else if(o==2)
 {
  halt();
 }
  

}
