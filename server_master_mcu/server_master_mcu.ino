/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Starts WiFi server with fix IP and listens
 *  Receives and sends messages to the client
 *  Communicates: wifi_client_01.ino
 */
#include <SPI.h>
#include <ESP8266WiFi.h>
#include "SoftwareSerial.h"
#include "FPS_GT511C3.h"
FPS_GT511C3 fps(4, 5);
//byte ledPin = 2;
char ssid[] = "Realme 7";               // SSID of your home WiFi
char pass[] = "SRV#$2021";               // password of your home WiFi
WiFiServer server(80);                    

IPAddress ip(192, 168, 0, 80);            // IP address of the server
IPAddress gateway(192,168,0,1);           // gateway of your network
IPAddress subnet(255,255,255,0);          // subnet mask of your network

void setup() {
  Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());*/
  //pinMode(ledPin, OUTPUT);
  fps.Open();       
  fps.SetLED(true); 
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      // Identify fingerprint test
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    
       /*Note:  GT-521F52 can hold 3000 fingerprint templates
                GT-521F32 can hold 200 fingerprint templates
                 GT-511C3 can hold 200 fingerprint templates. 
                GT-511C1R can hold 20 fingerprint templates.
       Make sure to change the id depending on what
       model you are using */
    if (id <200) //<- change id value depending model you are using
    {//if the fingerprint matches, provide the matching template ID
      Serial.print("Verified ID:");
      Serial.println(id);
      if(id==0){
      client.println("s");
      }
      else if(id==2)
      {
        client.println("r");
      }
    }
    else
    {//if unable to recognize
      Serial.println("Finger not found");
    }
  }
  else
  {
    Serial.println("Please press finger");
  }
      
      
    }
    //client.stop();                // tarminates the connection with the client
  }
}
