#include <SPI.h>
#include <WiFiNINA.h>
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
//#include "DFRobotDFPlayerMini.h"
//DFRobotDFPlayerMini m;
#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
int o;
int16_t a,b,c,d,e;
#define md1 2
#define mP1 3
#define md2 4
#define mP2 5
#define md3 6
#define mP3 7
#define md4 8
#define mP4 9
void setup() {
  //Serial.begin(115200);
  pinMode(md1, OUTPUT);
  pinMode(mP1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(mP2, OUTPUT);
  pinMode(mP3, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(mP4, OUTPUT);
  pinMode(md4, OUTPUT);
  Wire.begin();  
  //Serial1.begin(9600);
  //m.begin( Serial1);
  //pinMode(12, INPUT);
  //m.volume(30);
  //m.play(1);
   while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    delay(1000);
  }
   delay(2000);
   
   IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  server.begin();
  

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
  if(a<20||b<20||c<20)
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
  void back()
 {
  
  digitalWrite(md1, HIGH);
  digitalWrite(md2, LOW);
  digitalWrite(md3,LOW);
  digitalWrite(md4, HIGH);
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
  
  if(d<20||e<20)
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
  delayMicroseconds(100);
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
  }
 }
   void roundclo()
 {
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
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
  if(a<20||b<20||c<20||d<20||e<20)
  {
     //m.play(2);
     halt();
     //delay(4000);
   
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
   void roundant()
 {
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
  digitalWrite(md4, LOW);
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
  if(a<20||b<20||c<20||d<20||e<20)
  {
    // m.play(2);
     halt();
     //delay(4000);
   
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
  t.getData(a,0x11);
  if(a==0)
  {
    a=800;
  }
  t.getData(d,0x14);
  if(d==0)
    {
      d=800;
    }
  if(a<20||d<20)
  {
    // m.play(2);
     halt();
     //delay(4000);
   
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
  t.getData(c,0x13);
  if(c==0)
  {
    c=800;
  }
  t.getData(e,0x15);
    if(e==0)
    {
      e=800;
    }
  
  if(c<20||e<20)
  {
     //m.play(2);
     halt();
     //delay(4000);
   
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
   void back1()
 {
  
   digitalWrite(md1, HIGH);
  digitalWrite(md2, LOW);
  digitalWrite(md3,LOW);
  digitalWrite(md4, HIGH);
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
   void roundclo1()
 {
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
 
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
   void roundant1()
 {
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
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
  void right1()
{
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, LOW);
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
void left1()
{
 
  
   digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
  
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

 void loop()  {
   WiFiClient client = server.available();
 
   while(client.available()) {
    delayMicroseconds(10000);
        o=client.read();
        Serial.println(o);
   
  
  switch(o)
    {
    case 1:
    forward();
    break;
    case 2:
    back();
    break;
    case 3:
    right();
    break;
    case 4:
    left();
    break;
    case 5:
    roundclo();
    break;
    case 6:
    roundant();
    break;
    case 7:
    forward1();
    break;
    case 8:
    back1();
    break;
    case 9:
    right1();
    break;
    case 10:
    left1();
    break;
    case 11:
    roundclo1();
    break;
    case 12:
    roundant1();
    break;
    case 13:
    halt();
    break;
    case 0:
    halt();
    break;
    default:
    halt();
    break;
 }
   }
}
