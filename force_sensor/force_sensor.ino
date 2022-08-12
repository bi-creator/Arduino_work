void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);

}
int f;

void loop() {
 f=analogRead(A1);
 Serial.println(f);
 //Serial.write(f);
 delay(1000);
}
