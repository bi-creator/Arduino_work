void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);

}

void loop() {
int x=  analogRead(A2);
Serial.println(x);

}
