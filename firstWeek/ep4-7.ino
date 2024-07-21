#include "Arduino_LED_Matrix.h"
#include "animation.h"

Arduino_LED_Matrix matrix;

void setup(){
  Serial.begin(115200);
  matrix.loadSequence(animation);
  matrix.begin();
  matrix.play(true);
}

void loop(){
  delay(500);
  Serial.println(millis());
}
