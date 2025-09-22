#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

byte fram[8][12]={
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};

void setup() {
  // put your setup code here, to run once:
 matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix.renderBitmap(fram,8,12);
  delay(10000);
}

