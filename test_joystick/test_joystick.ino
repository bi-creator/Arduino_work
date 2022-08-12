
#define sw 1
#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
int16_t a,b,c,d,e;
int f,g;
#define md1 2
#define mP1 3
#define md2 4
#define mP2 5
#define md3 6
#define mP3 7
#define md4 8
#define mP4 9
void setup() {
   Serial.begin(115200);
  pinMode(md1, OUTPUT);
  pinMode(mP1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(mP2, OUTPUT);
  pinMode(mP3, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(mP4, OUTPUT);
  pinMode(md4, OUTPUT);
  pinMode(sw,  INPUT);
  Wire.begin();  
  delay(1000);

}
void halt()
{
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
}
void forward()
 {
  //Serial.println(10000);
   digitalWrite(md1, LOW);
  digitalWrite(md2, HIGH);
  digitalWrite(md3,HIGH);
  digitalWrite(md4, LOW);
  t.getData(a,0x11);
  if(a==0)
  {
    a=800;
  }
 Serial.println(a);
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
  if(a<10||b<10||c<10)
  {
    //m.play(2);
    halt();
    //delay(5000);
  }
  else
  {
  
  digitalWrite(mP1, HIGH);
  digitalWrite(mP2, HIGH);
  digitalWrite(mP3, HIGH);
  digitalWrite(mP4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
  }
  }
  void forward1()
 {
  
   digitalWrite(md1, LOW);
  digitalWrite(md2, HIGH);
  digitalWrite(md3,HIGH);
  digitalWrite(md4, LOW);
 
  {
  
  digitalWrite(mP1, HIGH);
  digitalWrite(mP2, HIGH);
  digitalWrite(mP3, HIGH);
  digitalWrite(mP4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
  }
  }
  int s;
void loop() {
   s=digitalRead(sw);
  
  f=analogRead(A4);
  g=analogRead(A5);
  if (g<400&&g>130){
      if(s==0)
      {
    forward();
    }
    else 
    {
      forward1();
    }
    }
    
    Serial.print(f);
    Serial.print(" ");
    Serial.println(g);
    Serial.println(s);
    

}
