
#define f 2
int a;
void setup() {
  Serial.begin(9600);
  pinMode(f,INPUT);
}

void loop() {
 
a=digitalRead(f);
Serial.println(a);
}
