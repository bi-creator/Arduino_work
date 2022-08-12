#include <Wire.h>

int x = 0;
void setup() {
  Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin(9); 
}
void receiveEvent(int bytes) {
  x = Wire.read();
}
void loop() {
  Wire.onReceive(receiveEvent);
  Serial.println(x);
  if (x > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    
}
}
