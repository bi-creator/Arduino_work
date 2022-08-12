#include <SPI.h>
#include <WiFiNINA.h>
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;
 WiFiClient client;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
#include <Arduino.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C t;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Wire.begin();
  Serial.begin(115200);
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
String i;
String o="stop";
int16_t a,b,c,d,e;
String checkClient ()
{
  while(!client.available())delay(1);
  String request = client.readString();
  request.remove(0, 5);
  request.remove(request.length() - 9, 9);
  return request;


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
 
  
   
 
}
void back()
{
   analogWrite(3,50);
   digitalWrite(2,LOW);
   delay(100);
}
void clo()
{
      analogWrite(3,50);
      digitalWrite(2,HIGH);
      analogWrite(5,50);
      digitalWrite(4,HIGH);
      analogWrite(7,50);
      digitalWrite(6,HIGH);
      delay(100);
}
void anti()
{
      analogWrite(3,50);
      digitalWrite(2,LOW);
      analogWrite(5,50);
      digitalWrite(4,LOW);
      analogWrite(7,50);
      digitalWrite(6,LOW);
      delay(100);
}
void halt()
{
   analogWrite(3,0);
   analogWrite(5,0);
   analogWrite(7,0);
}
void loop() {
  client = server.available();
   if(client.connected()) {
        i=checkClient ();
        Serial.println(i);
        if(i=="stop")
        {
          halt();
        }
        else if(i=="forward")
        {
          
         analogWrite(3,0);
         digitalWrite(2,HIGH);
         analogWrite(5,50);
         digitalWrite(4,HIGH);
         analogWrite(7,50);
         digitalWrite(6,LOW);
         delay(100);
  
          forward();
        }
        else if(i=="backward")
        {
         
        }
        else if(i=="left")
        {
          anti();
        }
        else if(i=="right")
        {
          clo();
        }
        
   


}

}
