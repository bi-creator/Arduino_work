#include<Wire.h>
int x = 0;
void setup() {
  Serial.begin(9600);
  Wire.begin(); 
}
void loop() {
  Wire.beginTransmission(9);
  Serial.println(x);
  Wire.write(x);              
  Wire.endTransmission();   
  x++; 
  if (x > 5)
  {
   x = 0;
  }
}
