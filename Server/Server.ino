#include <SPI.h>
#include <WiFiNINA.h>
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;
WiFiServer server(80);
int status = WL_IDLE_STATUS;
void setup() {
  Serial.begin(9600);
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(1000);
  }
   delay(2000);
   IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  server.begin();
}
int a;
void loop() {
  
  WiFiClient client = server.available();
 
   if(client.available()) {
        a=client.read();
        Serial.println(a);
  

}
}
