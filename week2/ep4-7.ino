/*
  Play Animation

  Sketch shows animation defined in animation.h

  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix
*/



#include "Arduino_LED_Matrix.h"   //Include the LED_Matrix library
#include "animation.h"            //Include animation.h header file

// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;  

void setup() {
  Serial.begin(115200);
  // you can also load frames at runtime, without stopping the refresh
  matrix.loadSequence(animation);
  matrix.begin();
  // turn on autoscroll to avoid calling next() to show the next frame; the paramenter is in milliseconds
  // matrix.autoscroll(300);
  matrix.play(true);
}

void loop() {
  delay(500);
  Serial.println(millis());
}


/*use annimation.h
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
