Uart Serial1(&sercom5, 13, 14, SERCOM_RX_PAD_3, UART_TX_PAD_2);
#include <TFMPlus.h> 
TFMPlus p; 
void setup() {
  Uart.begin(115200);
  Serial.begin(115200);
   p.begin(& Uart);
}
int16_t c;
void loop() {
  p.getData(c);
  Serial.println(c);

}
