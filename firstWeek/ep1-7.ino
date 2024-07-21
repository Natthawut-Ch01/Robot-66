#include "Arduino_LED_Matrix.h"
Arduino_LED_Matrix matrix;

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
    frame[0] [0]=1;
    frame[7] [11]=1;
    matrix.randerBitmap(frame,8,12);
    delay(500);
    frame[0] [0]=1;
    frame[1] [1]=1;
    matrix.randerBitmap(frame,8,12);
    delay(500);
}
