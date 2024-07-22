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
  int i, j;
  for (i=0; i<12; i++){
    for (j=0; j<8; j++){
      frame[j][i]=1;
      matrix.renderBitmap(frame, 8 ,12);
      delay(250);frame[j][i]=0;
      matrix.renderBitmap(frame, 8 ,12);
      delay(250);
    }
  }
}
