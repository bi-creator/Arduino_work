
void setup() {
   pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
   analogWrite(3,100);
         digitalWrite(2,HIGH);
         analogWrite(5,50);
         digitalWrite(4,LOW);
         analogWrite(7,50);
         digitalWrite(6,LOW);
         delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:

}
