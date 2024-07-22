#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

void setup(){
  matrix.begin();
}

uint8_t frame[8][12]= {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};

void loop(){
  frame[0][0]=1;
  frame[7][11]=1;
  matrix.renderBitmap(frame, 8, 12);
  delay(1000);

  frame[0][0]=0;
  frame[7][11]=0;
  matrix.renderBitmap(frame, 8, 12);
  delay(1000);

}
