#include <SoftwareSerial.h>
SoftwareSerial blue(10,11);
String data;
int t;
void setup() {
  Serial.begin(9600);
  blue.begin(9600);
}

void loop() {
 if(blue.available())
   {
    data=blue.readStringUntil('\n');
   }
   //Serial.println(data);
   t=(data.toInt());
   Serial.println(t);

}
