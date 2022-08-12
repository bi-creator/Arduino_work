void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);
  pinMode(3,INPUT);

}
int a;

void loop() {
  a=analogRead(A2);
  if(a>600)
  {
    digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(3,LOW);
  }
  Serial.println(a);

}
