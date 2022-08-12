#include <Keypad.h>
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns
#include <LiquidCrystal.h>
LiquidCrystal lcd(35, 36, 37, 38, 39, 40); 
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345); 
#include <Servo.h>
Servo myservo; 
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
#define force A0  
#define vibr A2
#define magnet 10
#define lpin 12

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 4);
  pinMode(force,INPUT);
  pinMode(vibr,INPUT);
  pinMode(magnet,OUTPUT);
  pinMode(lpin,OUTPUT);
  mag.begin();
  myservo.attach(lpin); 
  

}
 char key;
 int i;
 int j;
 int s;
 int f;
 float e;
void strength()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("load the spring");
  lcd.setCursor(0, 1);
  lcd.print("and press * to");
  lcd.setCursor(0, 2);
  lcd.print("lock it");
  delay(500);
  do{
  key = keypad.getKey();
  }
  while(key!='*');
   myservo.write(0); 
   disp0();
   myservo.write(90); 
  for(j=0;j<=500;j++)
  {
    s=s+analogRead(vibr);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("strength ");
  lcd.print(s);
  lcd.setCursor(0, 1);
  lcd.print("--press 0 to --");
   lcd.setCursor(0, 2);
  lcd.print("--continue--");
  delay(500);
  do{
  key = keypad.getKey();
  }
  while(key!='0');
  
  
 
}
void elastacity()
{
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("load the spring");
  lcd.setCursor(0, 1);
  lcd.print("and press * to");
  lcd.setCursor(0, 2);
  lcd.print("lock it");
  delay(500);
  do{
  key = keypad.getKey();
  }
  while(key!='*');
  myservo.write(0); 
  disp0();
  myservo.write(90); 
  delay(1000);
  for(j=0;j<500;j++)
  {
    f=f+analogRead(force);
  }
  e=f/10000;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Elasticity ");
  lcd.setCursor(11, 0);
  lcd.print(e);
  lcd.setCursor(0, 1);
  lcd.print("--press 0 to --");
   lcd.setCursor(0, 2);
  lcd.print("--continue--");
  delay(500);
  do{
  key = keypad.getKey();
  }
  while(key!='0');
  
}
void cracks()
{
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("This test is not");
  lcd.setCursor(0, 1);
  lcd.print("installed");
  delay(3000);
}
void rebar()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1.Deflections");
  lcd.setCursor(0, 1);
  lcd.print("2.Quality");
  do{
  key = keypad.getKey();
  }
  while(!key);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(key);
  i=key-48;
 switch(i)
   {
    case 1:
    deflection();
    break;
    case 2:
     quality();
    break;
    default:
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid option");
    delay(2000);
    }
   }
}
void deflection()
{
  
disp0();
lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slide the module");
    lcd.setCursor(0, 1);
    lcd.print("along the pillar");
    lcd.setCursor(0, 2);
    lcd.print("odd change impy");
    lcd.setCursor(0, 3);
    lcd.print("deflection");
    delay(5000);
  digitalWrite(magnet,HIGH);
  lcd.clear();
  lcd.setCursor(0, 2);
  lcd.print("Enter 0 to STOP");
  do
  {
  sensors_event_t event; 
  mag.getEvent(&event);
  lcd.setCursor(0, 0);
  lcd.print(event.magnetic.x);
  lcd.setCursor(0, 1);
  lcd.print(event.magnetic.y); 
  delay(500);
  key = keypad.getKey();
  }while(key!='0');
  digitalWrite(magnet,LOW);
}
void quality()
{
  disp0();
  digitalWrite(magnet,HIGH);
  lcd.clear();
  lcd.setCursor(0, 2);
  lcd.print("Enter 0 to STOP");
  do
  {
  sensors_event_t event; 
  mag.getEvent(&event);
  lcd.setCursor(0, 0);
  lcd.print(event.magnetic.x);
  lcd.setCursor(0, 1);
  lcd.print(event.magnetic.y); 
  delay(500);
  key = keypad.getKey();
  }while(key!='0');
  digitalWrite(magnet,LOW);
}
void disp()
{
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Chose type of ");
  lcd.setCursor(0, 1);
  lcd.print("Test");
  delay(3000);
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1.Strength test");
  lcd.setCursor(0, 1);
  lcd.print("2.Elasticity ");
  lcd.setCursor(0, 2);
  lcd.print("3.Voids & Cracks");
  lcd.setCursor(0, 3);
  lcd.print("4.Rebar test");
  delay(500);
  do{
  key = keypad.getKey();
  }
  while(!key);
      Serial.println(key);
    lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print(key);
     delay(2000);
  
}
void disp0()
{
   lcd.clear();
   lcd.setCursor(0, 0);
     lcd.print("Place the module");
      lcd.setCursor(0, 1);
     lcd.print("in contact with");
      lcd.setCursor(0, 2);
     lcd.print("wall and press #");
      lcd.setCursor(0, 3);
     lcd.print("to begin");
     
      do{
  key = keypad.getKey();
  }
  while(key!='#');
     
}

void loop() {
 
  myservo.write(90); 
disp();
i=key-48;
Serial.println(i);
 switch(i)
   {
    case 1:
    strength();
    break;
    case 2:
     elastacity();
    break;
    case 3:
    cracks();
    break;
    case 4:
    rebar();
    break;
    default:
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid option");
    delay(2000);
    }
   }
}
