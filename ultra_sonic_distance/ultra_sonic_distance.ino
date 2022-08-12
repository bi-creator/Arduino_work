
#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int d; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(2,OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
 
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  d = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println(" cm");
  if (d<50)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
        digitalWrite(2,LOW);
  }
}
