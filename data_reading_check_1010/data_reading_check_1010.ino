#include <SPI.h>
#include <WiFiNINA.h>
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;
 WiFiClient client;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
String i;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
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
String checkClient ()
{
  while(!client.available())delay(1);
  i = client.readString();
  i.remove(0, 5);
  i.remove(1, 2000);
  return i;


}

void loop() {
   client = server.available();
    if(client.connected()) {
   i=checkClient();
    }
   Serial.println(i);
   if(i=="f")
   {
    Serial1.write(1);
   }
   else if(i=="s")
   {
    Serial1.write(2);
   }
   else 
   {
    Serial1.write(3);
   }
    

}
