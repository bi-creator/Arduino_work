#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup() {
  Serial.begin(9600);
  mlx.begin();
  tsl.begin();
  tsl.enableAutoRange(true);  
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS); 

}

void loop() {
  Serial.print("temp=");
  Serial.print(mlx.readObjectTempC());
  Serial.print("light=");
  sensors_event_t event;
  tsl.getEvent(&event);
  Serial.println(event.light);
  
  

}
