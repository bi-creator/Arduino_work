#include <SPI.h>
#include <WiFiNINA.h> 
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0; 
int status = WL_IDLE_STATUS;
IPAddress server(192,168,0,170); 
WiFiClient client;
void setup() {
  Serial.begin(9600);
 while(!Serial){delay(1);}
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
    //client.println("getting tf luna data");
    delay(1000);
  }
  pinMode(1,INPUT);
  
}
  int a,b,s;
  
void loop() {
    
 
  while(client.connected()) {
  s=digitalRead(1);
    a=analogRead(A4);
  b=analogRead(A5);
    if (a>0&&a<700&&b>750&&b<810){
     if(s==0){
      client.write(100);
      delay(1000);
     }
     else
     {
      client.write(700);
      delay(1000);
     }
    }
    
    else if(a==1023&&b>700&&b<800)
    {
      if(s==0){
      client.write(200);
      delay(1000);
     }
     else
      {
    client.write(701);
    delay(1000);
      } 
    }
    else if(a>700&&a<800&&b==1023){
      if(s==0){
      client.write(300);
      delay(1000);
     }
     else
     {
    client.write(702);
     delay(1000);
     }
    }
    else if(a>700&&a<810&&b>=0&&b<700){
     if(s==0){
      client.write(400);
      delay(1000);
     }
     else
     {
    client.write(703);
     delay(1000);
     }
    }
    else if(a<500&&a>=0&&b==1023)
    {
      
      client.write(500);
      delay(1000);
     
    }
     else if(a<600&&a>=0&&b>=0&&b<=600)
    {
      client.write(600);
     delay(1000);
    }
    else {
     client.write(768);
    }
    Serial.print(a);
Serial.print(" ");
Serial.println(b);
Serial.println(  s);
      
  }
 }
