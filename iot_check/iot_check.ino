#include <SoftwareSerial.h>
SoftwareSerial b(8,9);
int x=0;
void setup() {
  Serial.begin(9600);
  b.begin(9600);
  

}

void loop() {
  if(b.available())
  {
    x=b.read();
  }
  Serial.println(x);

}
