#include <SPI.h>
#include <WiFiNINA.h> 
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0; 
#define sw 2  

int status = WL_IDLE_STATUS;
IPAddress server(192,168,0,192); 
WiFiClient client;
void setup() {
  pinMode(sw,INPUT);
  Serial.begin(115200);
   while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(1000);
  }
    Serial.println("Connected to WiFi");
     if (client.connect(server, 80)) {
    Serial.println("connected to server");
    client.println("getting tf luna data");
    delay(3000);
  }
}
  int a,b,s;
  
void loop() {

  
  while(client.connected()) {
  s=digitalRead(sw);
  a=analogRead(A4);
  b=analogRead(A5);
    if (b<400&&b>130){
      if(s==1){
    client.write(100);
    //delayMicroseconds(10000);
    }
    else
    {
      client.write(7);
      delayMicroseconds(10000);
    }
    }
    
    else if(b<900&&b>600&&a<600&&a>500)
    {
       if(s==1){
    client.write(200);
    //delayMicroseconds(10000);
    }
    else
    {
      client.write(8);
      delayMicroseconds(10000);
    }
    }
    else if(a>600&&a<920&&b<600){
      if(s==1){
    client.write(300);
    delayMicroseconds(10000);
    }
    else
    {
      client.write(9);
      delayMicroseconds(10000);
    }
    }
    else if(a>150&&a<460&&b<600){
      if(s==1){
    client.write(400);
    delayMicroseconds(10000);
    }
    else
    {
      client.write(10);
      delayMicroseconds(10000);
    }
    }
    else if(b<900&&b>600&&a>600&&a<910)
    {
     if(s==1){
    client.write(500);
    delayMicroseconds(10000);
    }
    else
    {
      client.write(11);
      delayMicroseconds(10000);
    }
    }
    else if(b<900&&b>600&&a>150&&a<460)
    {
     if(s==1){
    client.write(600);
    delayMicroseconds(10000);
    }
    else
    {
      client.write(12);
      delayMicroseconds(10000);
    }
    }
    else {
     client.write(768);
     delayMicroseconds(10000);
    }
    
    
  }
  
Serial.print(a);
Serial.print(" ");
Serial.println(b);
}
