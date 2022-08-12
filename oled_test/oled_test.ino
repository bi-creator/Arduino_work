// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128

#define SCLK_PIN 2
#define MOSI_PIN 3
#define DC_PIN   4
#define CS_PIN   5
#define RST_PIN  6

// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN); 

void setup() {
  tft.begin();
  

}

void loop() {
 tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-10; x+=4) {
     tft.drawLine(10, 10, x+10, tft.width()-10, RED);
     delay(100);
   }
  
   delay(1000);
    for (uint16_t x=0; x < tft.width()-10; x+=4) {
     tft.drawLine(tft.width(), tft.height()-10, x+10, 10, RED);
     delay(100);
   }
   delay(100);
   tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-20; x+=3) {
     tft.drawLine(10, x+10, tft.width()-10,x+10 ,BLUE);
     delay(10);
   }
   delay(1000);
    tft.fillScreen(BLACK);
   for (uint16_t y=0; y < tft.height()-1; y+=5) {
     tft.drawFastHLine(0, y, tft.width()-1, YELLOW);
     delay(100);
   }
   for (uint16_t x=0; x < tft.width()-1; x+=5) {
     tft.drawFastVLine(x, 0, tft.height()-1, GREEN);
     delay(100);
   }
   delay(1000);
   
 

}
