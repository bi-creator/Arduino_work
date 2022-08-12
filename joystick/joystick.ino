
void setup() {
  Serial.begin(9600);

}

void loop() {
  int s1 = analogRead(A4);
  int s2 = analogRead(A5);
  Serial.println(s1);
  Serial.println(s2);
  

}
