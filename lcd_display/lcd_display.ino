#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,2,3,4,5);  
 void setup()
 {
     lcd.begin(16, 2);
  } 
     void loop()
 { 
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Hello Somnath");
   delay(5000);
   lcd.clear();
   lcd.setCursor(0, 1);
   lcd.print("Good Morning");
   delay(1000);
   lcd.setCursor(0, 2);
   lcd.print("Enjoy the Day");
   delay(1000);
   lcd.setCursor(3, 3);
   lcd.print("Thank you");
   delay(1000);
 }
