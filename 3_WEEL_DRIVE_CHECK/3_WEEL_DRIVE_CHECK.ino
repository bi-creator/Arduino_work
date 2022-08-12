#define md1 2
#define mP1 3
#define md2 4
#define mP2 5
#define md3 6
#define mP3 7
void setup() {
   pinMode(md1, OUTPUT);
  pinMode(mP1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(mP2, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(mP3, OUTPUT);

}

void loop() {
  digitalWrite(md1,HIGH);
   digitalWrite(md2,HIGH);
   digitalWrite(md3,HIGH);
   for(int i=0;i<1600;i++)
   {
     digitalWrite(mP1,HIGH);
   digitalWrite(mP2,HIGH);
   digitalWrite(mP3,HIGH);
   delayMicroseconds(2000);
   digitalWrite(mP1,LOW);
   digitalWrite(mP2,LOW);
   digitalWrite(mP3,LOW);
   delayMicroseconds(500);
   
   }
   delay(3000);
   digitalWrite(md1,LOW);
   digitalWrite(md2,LOW);
   digitalWrite(md3,LOW);
  for(int i=0;i<1600;i++)
   {
    digitalWrite(mP1,HIGH);
   digitalWrite(mP2,HIGH);
   digitalWrite(mP3,HIGH);
   delayMicroseconds(2000);
   digitalWrite(mP1,LOW);
   digitalWrite(mP2,LOW);
   digitalWrite(mP3,LOW);
   delayMicroseconds(500);
   }
  
  

}
