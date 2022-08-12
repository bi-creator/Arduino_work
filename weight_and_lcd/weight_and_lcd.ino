#include <LiquidCrystal.h>
LiquidCrystal lcd(35, 36, 37, 38, 39, 40);  
 void setup()
 {
     lcd.begin(16, 4);
     pinMode(A4,INPUT);
     Serial.begin(9600);
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("today waste ");
     lcd.setCursor(0, 1);
     lcd.print("Your waste ");
     
  } 
  float f,w;
  float tw=0;
  int c;
  
 void loop()
 { 
   w=0;
   f=analogRead(A4);
   while(f!=0)
   {
    f=analogRead(A4);
    delay(1000);
    w=w+f;
    
    c=1;
    
   }
   w=w/100;
   if(c==1){
   tw=tw+w/1000;
   c=0;
   }
   lcd.setCursor(12, 0);
   lcd.print(tw);
   lcd.setCursor(11, 1);
   lcd.print(w);
   lcd.setCursor(15, 1);
   lcd.print("g");
   if(w>80)
   {
    lcd.setCursor(0, 3);
    lcd.print("You could have ");
    lcd.setCursor(0, 4);
    lcd.print("fed an animal");
    delay(5000);
    
   }
   Serial.println(tw);
   Serial.println(w);
   delay(2000);
   
   
   
   
  }
