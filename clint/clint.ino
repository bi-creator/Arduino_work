#include <SPI.h>
#include <WiFiNINA.h> 
char ssid[] = "Realme 7";        // your network SSID (name)
char pass[] = "SRV#$2021";  
int keyIndex = 0;           

int status = WL_IDLE_STATUS;
IPAddress server(192,168,137,68); 
WiFiClient client;
void setup() {
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
int16_t a;
void loop() {
  while (client.available()) {
    a = client.read();
    Serial.println(a);

}
}
