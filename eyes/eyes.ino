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
  // put your setup code here, to run once:
tft.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  tft.fillScreen(BLACK);
  tft.fillCircle(64,64, 54, BLUE);
  delay(2000);
   tft.fillScreen(BLACK);
  tft.drawCircle(64,64, 54, BLUE);
  delay(2000);
   tft.fillScreen(BLACK);
  tft.fillCircle(64,64, 54, BLUE);
  tft.fillCircle(64,84, 54, BLACK);
  delay(2000);
   tft.fillScreen(BLACK);
    tft.fillCircle(64,64, 54, BLUE);
  delay(2000);
   tft.fillScreen(BLACK);
  tft.fillCircle(64,64, 54, BLUE);
  tft.fillCircle(64,54, 54, BLACK);
  delay(2000);

}
