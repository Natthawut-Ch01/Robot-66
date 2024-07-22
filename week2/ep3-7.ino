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
  le();
  re();
  mnt();
  ns();
  matrix.renderBitmap(frame, 8, 12);
  delay(500);

  w_le();
  w_re();
  matrix.renderBitmap(frame, 8, 12);
  delay(500);
  
}
void le(){
  frame[1][3]=1;
  frame[1][4]=1;
  frame[2][3]=1;
  frame[2][4]=1;
}
void re(){
  frame[1][8]=1;
  frame[1][9]=1;
  frame[2][8]=1;
  frame[2][9]=1;
}
void mnt(){
  frame[5][3]=1;
  frame[5][9]=1;
  frame[6][3]=1;
  frame[6][4]=1;
  frame[6][5]=1;
  frame[6][6]=1;
  frame[6][7]=1;
  frame[6][8]=1;
  frame[6][9]=1;
}
void ns(){
  frame[3][5]=1;
  frame[3][6]=1;
}

void w_le(){
  frame[1][3]=1;
  frame[1][4]=1;
  frame[2][3]=1;
  frame[2][4]=1;
}

void w_re(){
  frame[1][8]=1;
  frame[1][9]=1;
  frame[2][8]=1;
  frame[2][9]=1;
}

























