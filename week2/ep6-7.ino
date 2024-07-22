#include "Arduino_LED_Matrix.h"
#include "animation.h"

ArduinoLEDMatrix matrix;  // Declare the matrix object

void setup() {
  Serial.begin(115200);
  matrix.loadSequence(animation);  // Load the animation sequence
  matrix.begin();  // Initialize the LED matrix
  matrix.play(true);  // Start playing the animation in a loop
}

void loop() {
  delay(500);
  Serial.println(millis());  // Print the millis to serial monitor
}

/*use animation.h
const uint32_t animation[][4] = {
	{
		2147483648,
		4194304,
		1,
		1000
	},
  {
		21,
		43008,
		3840,
		1000
	},
  {
		4026531840,
		251658240,
		15728640,
		1000
	},
	{
		0,
		0,
		0,
		1000
  }
};*/
