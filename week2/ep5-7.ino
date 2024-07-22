#include "Arduino_LED_Matrix.h"   
#include "animation.h"            
ArduinoLEDMatrix matrix; 
void setup() {
  pinMode(13, OUTPUT);
  matrix.loadSequence(animation);
  matrix.begin();
  matrix.play(true);
}

void loop() {
  int d_time = 1000;
  digitalWrite(13, 1);
  delay(d_time);
  digitalWrite(13, 0);
  delay(d_time);

}

/*use animation.h
const uint32_t animation[][4] = {
	{
		0xae0aa0ae,
		0xe800000,
		0x0,
		66
	},
	{
		0x57055,
		0x5707400,
		0x0,
		66
	},
	{
		0x2b,
		0x82a82b83,
		0xa0000000,
		66
	},
	{
		0x0,
		0x15c1541,
		0x5c1d0000,
		66
	},
	{
		0x0,
		0xae0,
		0xaa0ae0e8,
		66
	},
	{
		0x2b,
		0x82a82b83,
		0xa0000000,
		66
	},
	{
		0x57055,
		0x5707400,
		0x0,
		66
	},
	{
		0xae0aa0ae,
		0xe800000,
		0x0,
		66
	}
};*/
