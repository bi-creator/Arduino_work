/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Sends and receives message from the server in every 2 seconds
 *  Communicates: wifi_server_01.ino
 */ 
#include <SPI.h>
#include <ESP8266WiFi.h>
#include "SoftwareSerial.h"
#include "FPS_GT511C3.h"
FPS_GT511C3 fps(4, 5);
char ssid[] = "Realme 7";           // SSID of your home WiFi
char pass[] = "SRV#$2021";            // password of your home WiFi

unsigned long askTimer = 0;

IPAddress server(192,168,0,80);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(9600);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());*/
  pinMode(10, OUTPUT);
   fps.Open();       
  fps.SetLED(true); 
}
int a;

void loop () {
  
  a=Serial.read();
  if(a==1)
  {
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
      //Serial.print("Verified ID:");
      //Serial.println(id);
    digitalWrite(10,HIGH); 
    delay(10000);
    digitalWrite(10,LOW);
      
    }
    else
    {//if unable to recognize
      //Serial.println("Finger not found");
    }
  }
   else
  {
    //Serial.println("Please press finger");
  }
  }
  else if(a==2)
  {
    int d=enrl();
  }
  client.connect(server, 80);   // Connection to the server
  //client.println("Hello server! Are you sleeping?\r"); 
  String answer = client.readStringUntil('\r');
  if(answer=="s")
  {
    digitalWrite(10,HIGH); 
    delay(10000);
    digitalWrite(10,LOW);
    
  }
  else if(answer=="r")
  {
    Serial.write(1);
  }
  //Serial.println(answer);
  client.flush();
}


int enrl()
{
  int q=0;
  // Add your code here to act upon Enroll change
   // Enroll test

  // find open enroll id
  int enrollid = 0;
  bool usedid = true;
  while (usedid == true)
  {
    usedid = fps.CheckEnrolled(enrollid);
    if (usedid==true) enrollid++;
  }
  fps.EnrollStart(enrollid);

  // enroll
  Serial.print("Press finger to Enroll #");
  Serial.println(enrollid);
  while(fps.IsPressFinger() == false) 
  {delay(100);
  q++;
  if(q==100)
  {
    return(0);
  }
  }
  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    Serial.println("Remove finger");
    fps.Enroll1(); 
    while(fps.IsPressFinger() == true) delay(100);
    Serial.println("Press same finger again");
    while(fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
      Serial.println("Remove finger");
      fps.Enroll2();
      while(fps.IsPressFinger() == true) delay(100);
      Serial.println("Press same finger yet again");
      while(fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
        Serial.println("Remove finger");
        iret = fps.Enroll3();
        if (iret == 0)
        {
          Serial.println("Enrolling Successful");
        }
        else
        {
          Serial.print("Enrolling Failed with error code:");
          Serial.println(iret);
        }
      }
      else Serial.println("Failed to capture third finger");
    }
    else Serial.println("Failed to capture second finger");
  }
  else Serial.println("Failed to capture first finger");
  return(0);
}
