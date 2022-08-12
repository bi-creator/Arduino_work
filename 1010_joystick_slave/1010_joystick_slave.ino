#include <SPI.h>
#include <WiFiNINA.h>
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini m;
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;
 WiFiClient client;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
int i;
#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
int16_t a,b,c,d,e;
void setup() {
   Serial1.begin(9600);
   m.begin( Serial1);
   m.volume(30);
  m.play(1);
  
   pinMode(2,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
   while (status != WL_CONNECTED) {
    //Serial.print("Attempting to connect to SSID: ");
    //Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    delay(1000);
   }
   IPAddress ip = WiFi.localIP();
  //Serial.print("IP Address: ");
  //Serial.println(ip);
  server.begin();
    Wire.begin();
    
}
void forward()
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
  if(a<50||b<50||c<50)
  {
   
    halt();
     m.play(2);
     delay(4000);
    
    
  }
  else
  {
   analogWrite(6,0);
         analogWrite(5,50);
         digitalWrite(4,LOW);
         analogWrite(7,50);
         digitalWrite(8,HIGH);
       delay(100);
  }
}
void back()
{
    t.getData(d,0x14);     
  if(d==0)
  {
    d=800;
  }
  t.getData(e,0x15);
    if(e==0)
    {
      e=800;
    }
  if(d<50||e<50)
  {
   
    halt();
    m.play(2);
    delay(4000);
    
    
  }
  else
  {
         analogWrite(6,0);
         analogWrite(5,50);
         digitalWrite(4,HIGH);
         analogWrite(7,50);
         digitalWrite(8,LOW);
         delay(100);
  }
}
void left()
{
  t.getData(a,0x11);     
  if(a==0)
  {
    a=800;
  }
  t.getData(d,0x15);
  if(d==0)
  {
      d=800;
  }
  if(a<50||d<50)
  {
   
    halt();
    m.play(2);
    delay(4000);
    
    
  }
  else
  {
         analogWrite(6,100);
         digitalWrite(2,HIGH);
         analogWrite(5,50);
         digitalWrite(4,LOW);
         analogWrite(7,50);
         digitalWrite(8,LOW);
         delay(100);
  }
}
void right()
{
  t.getData(c,0x13);     
  if(c==0)
  {
    c=800;
  }
  t.getData(e,0x14);
  if(e==0)
  {
      e=800;
  }
  if(c<50||e<50)
  {
   
    halt();
    m.play(2);
    delay(4000);
   }
  else
  {
          analogWrite(6,100);
         digitalWrite(2,LOW);
         analogWrite(5,50);
         digitalWrite(4,HIGH);
         analogWrite(7,50);
         digitalWrite(8,HIGH);
         delay(100);
  }
}
void clo()
{
      analogWrite(6,50);
      digitalWrite(2,HIGH);
      analogWrite(5,50);
      digitalWrite(4,HIGH);
      analogWrite(7,50);
      digitalWrite(8,HIGH);
      delay(100);
}
void anti()
{
      analogWrite(6,50);
      digitalWrite(2,LOW);
      analogWrite(5,50);
      digitalWrite(4,LOW);
      analogWrite(7,50);
      digitalWrite(8,LOW);
      delay(100);
}
void halt()
{
   analogWrite(6,0);
   analogWrite(5,0);
   analogWrite(7,0);
}
void f1()
{
        analogWrite(6,0);
         analogWrite(5,100);
         digitalWrite(4,HIGH);
         analogWrite(7,100);
         digitalWrite(8,LOW);
       delay(100);
}
void b1()
{
   analogWrite(6,0);
         analogWrite(5,100);
         digitalWrite(4,LOW);
         analogWrite(7,100);
         digitalWrite(8,HIGH);
         delay(100);
}
void r1()
{
         analogWrite(6,150);
         digitalWrite(2,LOW);
         analogWrite(5,75);
         digitalWrite(4,HIGH);
         analogWrite(7,75);
         digitalWrite(8,HIGH);
         delay(100);
}
void L1()
{
      analogWrite(6,150);
         digitalWrite(2,HIGH);
         analogWrite(5,75);
         digitalWrite(4,LOW);
         analogWrite(7,75);
         digitalWrite(8,LOW);
         delay(100);
}
 
void loop() {
   client = server.available();
    if(client.available()) {
   i=client.read();
   if(i==100)
   {
    forward();
   }
   else if(i==200)
   {
    back();
   }
   else if(i==44)
   {
    left();
   }
   else if(i==144)
   {
    right();
   }
   else if(i==244)
   {
    anti();
   }
   else if(i==88)
   {
    clo();
   }
   else if(i==188)
   {
    b1();
   }
   else if(i==189)
   {
    f1();
   }
   else if(i==190)
   {
    L1();
   }
   else if(i==191)
   {
    r1();
   }
   
   else if(i==0)
   {
    halt();
   }
   client.flush();
   
    
    }
}
