//// this code is testing on this hardware
////https://shop.controleverything.com/collections/4-20-ma-current-loop-output/products/1-channel-12-bit-4-20ma-current-loop-transmitter


#include <Wire.h>
void setup()
{
   Serial.begin (9600);
  Wire.begin();
 
}
void loop()
{
/// at DAC vlaue 290 the current output will be around 4mA and 
///at DAC vlaue 1500 the current output will be around 20mA 
/// you can change these values to tune the 4-20mA output
 for (int i=290; i <= 1500; i++)
  {
  Wire.beginTransmission(0x60 );
  Wire.write(64); 
 // Wire.write(64); 
  Wire.write(i >> 4);        // 8 MSB
  Wire.write((i & 15) << 4); //4 LSB
  delay(100);
  Serial.print (i, DEC);
  Serial.print("\n");
  Wire.endTransmission();
  }
}
