#define md1 2
#define mP1 3
#define md2 4
#define mP2 5
#define md3 6
#define mP3 7
#define md4 8
#define mP4 9
void setup() {
  pinMode(md1, OUTPUT);
  pinMode(mP1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(mP2, OUTPUT);
  pinMode(mP3, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(mP4, OUTPUT);
  pinMode(md4, OUTPUT);
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3,HIGH);
  digitalWrite(md4, HIGH);

}

void loop() {
 
  
  digitalWrite(mP1, HIGH);
  digitalWrite(mP2, HIGH);
  digitalWrite(mP3, HIGH);
  digitalWrite(mP4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(mP1, LOW);
  digitalWrite(mP2, LOW);
  digitalWrite(mP3, LOW);
  digitalWrite(mP4, LOW);
  

}
