void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);

}
int i;

void loop() {
  i=analogRead(A2);
  Serial.println(i);
}
