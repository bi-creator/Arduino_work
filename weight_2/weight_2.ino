#include <LiquidCrystal.h>
LiquidCrystal lcd(35, 36, 37, 38, 39, 40);  
#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int d; // variable for the distance measurement

float f;
  float a[2];
  float w;
 void setup()
 {
     lcd.begin(16, 4);
     pinMode(A4,INPUT);
     Serial.begin(9600);
    
     a[1]=0;
     pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(2,OUTPUT);
     
  } 
  
  
 void loop()
 { 
   lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("today waste ");
     lcd.setCursor(0, 1);
     lcd.print("Your waste ");
   f=analogRead(A4);
   a[0]=f/100;
   if(a[0]>a[1])
   {
    w=a[0]-a[1];
    a[1]=a[0];
   }
   a[0]=a[0]/1000;
   lcd.setCursor(12, 0);
   lcd.print(a[0]);
   lcd.setCursor(11, 1);
   lcd.print(w);
   lcd.setCursor(15, 1);
   lcd.print("g");
   delay(1000);
   if(w>2)
   {
    lcd.setCursor(0, 2);
    lcd.print("You could have ");
    lcd.setCursor(0, 3);
    lcd.print("fed an puppy");
    delay(3000);
    
   }
   Serial.println(a[0]);
   Serial.println(w);
   w=0;
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
  if (d<12)
  {
    digitalWrite(2,HIGH);
    lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("bin is full");
     delay(1000);
  }
  else
  {
        digitalWrite(2,LOW);
  }
   
   
   
   
   
  }
