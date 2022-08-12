#include <TFMPlus.h>
#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini m;
int x =0;
SoftwareSerial blue(10,11);
TFMPlus s1;
TFMPlus s2;
TFMPlus s3;
#define md1 2
#define mP1 3
#define md2 4
#define mP2 5
#define md3 6
#define mP3 7
#define md4 8
#define mP4 9
int a,b,c,e,g;
int d=0;
int f=0;  
//String data; for bluetooth
int t;
int state;
void setup() 
{
  Serial.begin(9600);
  blue.begin(9600);
  m.begin( Serial);
  pinMode(md1, OUTPUT);
  pinMode(mP1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(mP2, OUTPUT);
  pinMode(mP3, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(mP4, OUTPUT);
  pinMode(md4, OUTPUT);
 
  delay(20);
  Serial1.begin(115200);
  delay(20);
  Serial2.begin( 115200);
  delay(20);
  Serial3.begin( 115200);
  delay(20);
  s1.begin( &Serial1);
  delay(20);
  s2.begin( &Serial2);
  delay(20);
  s3.begin( &Serial3);
  delay(20);
  pinMode(12, INPUT);
  m.volume(30);
  m.play(1);
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
  
   digitalWrite(md1, LOW);
  digitalWrite(md2, HIGH);
  digitalWrite(md3,HIGH);
  digitalWrite(md4, LOW);
   if(d==0)
  {
  s1.getData(a);
  d=1;
  if(a==0)
  {
    a=800;
  } 
  }
  if(d==1)
  {
    s1.getData(b);
    d=0;
    if(b==0)
    {
      b=800;
    }
  }
  s2.getData(c);
  if(c==0)
  {
    c=800;
  }
  if(a<150||b<150||c<150)
  {
    m.play(2);
    halt();
    delay(5000);
  }
  else
  {
  
  digitalWrite(mP1, HIGH);
  digitalWrite(mP2, HIGH);
  digitalWrite(mP3, HIGH);
  digitalWrite(mP4, HIGH);
  delayMicroseconds(100);
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
  }
  }
  void roundro()
 {
  
  
  
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
   if(d==0)
  {
  s1.getData(a);
  d=1;
  if(a==0)
  {
    a=800;
  }
  }
  if(d==1)
  {
    s1.getData(b);
    d=0;
    if(b==0)
    {
      b=800;
    }
  }
  s2.getData(c);
  if(c==0)
  {
    c=800;
  }
   if(f==0)
  {
    s3.getData(e);
    f=1;
    if(e==0)
    {
      e=800;
    }
  }
  if(f==1)
  {
    s3.getData(g);
    f=0;
    if(g==0)
    {
      g=800;
    }
  }
  if(a<100||b<100||c<100||e<100||g<100)
  {
     m.play(2);
     halt();
     delay(4000);
   
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
void right()
{

  
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, LOW);
  digitalWrite(md4, LOW);
   if(d==0)
  {
  s1.getData(a);
  d=1;
  if(a==0)
  {
    a=800;
  }
  }
  if(d==1)
  {
    s1.getData(b);
    d=0;
    if(b==0)
    {
      b=800;
    }
  }
   if(f==0)
  {
    s3.getData(e);
    f=1;
    if(e==0)
    {
      e=800;
    }
  }
  if(f==1)
  {
    s3.getData(g);
    f=0;
    if(g==0)
    {
      g=800;
    }
  }
 
  if(a<150||g<50)
  {
     m.play(2);
     halt();
     delay(4000);
   
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
void left()
{
 
  
   digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
   if(d==0)
  {
  s1.getData(a);
  d=1;
  if(a==0)
  {
    a=800;
  }
  }
  if(d==1)
  {
    s1.getData(b);
    d=0;
    if(b==0)
    {
      b=800;
    }
  }
 if(f==0)
  {
    s3.getData(e);
    f=1;
    if(e==0)
    {
      e=800;
    }
  }
  if(f==1)
  {
    s3.getData(g);
    f=0;
    if(g==0)
    {
      g=800;
    }
  }
  if(b<150||e<150)
  {
     m.play(2);
     halt();
     delay(4000);
   
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

void loop() {
  
   
   if(blue.available())
   {
    t=blue.read();
   }
   state = digitalRead(12);
   if(state==1)
   {
    t=6;
   }
   switch(t)
   {
    case 1:
    forward();
    break;
    case 2:
    roundro();
    break;
    case 3:
    left();
    break;
    case 4:
    right();
    break;
    case 5:
    halt();
    break;
    case 6:
    halt();
    default:
    halt();
   }
}
