#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,2,3,4,5);
#define uvp A0  
#define Smokepin A2
#define Buzer 13
int A,B,C;
int x,y,z;
int s;
void setup() {
  Serial.begin(9600);
  
  mlx.begin();
  tsl.begin();
  tsl.enableAutoRange(true);  
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS); 
  pinMode(Smokepin,INPUT);
  pinMode(Buzer,OUTPUT);
  pinMode(uvp,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  dis();
 
  
}
void dis()
{
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tempurature-");
  lcd.setCursor(0,1);
  lcd.print("light-");
  lcd.setCursor(10,1);
  lcd.print("uv-");
}
void temp()
{
  x=mlx.readObjectTempC();
  Serial.println(x);
}
void lumni()
{
  sensors_event_t event;
  tsl.getEvent(&event);
  y=event.light;
  
}
void uv()
{
  z=analogRead(uvp);
  Serial.println(z);
}
void smoke()
{
  s=analogRead(Smokepin);
  Serial.println(s);
}
void buzer()
{
  digitalWrite(Buzer,HIGH);
  delay(10);
  //digitalWrite(Buzer,LOW);
  
}

void loop() {
  temp();
  lumni();
  uv();
  
  if(x>30&&y>100&&z>50)
  {
    smoke();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smoke-");
    lcd.setCursor(6, 0);
    lcd.print(s);
    delay(500);
    if(s>100)
    {
      buzer();
    }
    else
    {
      dis();
    }
    
  }
  else
  {
    lcd.setCursor(12,0);
  lcd.print(x);
  lcd.setCursor(6,1);
  lcd.print(y); 
  lcd.setCursor(13,1);
  lcd.print(z);
  }
  
  delay(500);
  
  
  

}
