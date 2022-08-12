#include <Wire.h>

void setup() {
Wire.begin(); // join i2c bus (address optional for master)
Serial.begin(115200); // start serial for output print
Serial.print("Ready to Send command to TF-Luna\r\n");
//pinMode(LED_BUILTIN, OUTPUT);//LED
// Change the address
Wire.beginTransmission(0x10);
Wire.write(0x5A);
Wire.write(0x05);
Wire.write(0x0B);
Wire.write(0x13);// Change this line to change the address. (Hexadecimal , Example: 17 = 0X11, 18= 0X12, …)
delay(1000);
Wire.write(0x00);
Wire.endTransmission(0);
delay(1000);
// Save the address
Wire.beginTransmission(0x10);
Wire.write(0x5A);
Wire.write(0x04);
Wire.write(0x11);
Wire.write(0x6F);
Wire.endTransmission(0);

}

void loop() {
}
