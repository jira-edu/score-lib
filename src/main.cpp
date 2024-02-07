#include <Arduino.h>
#include "score_lib.h"

Scorelib scorelib(2,3,4,5,6,7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  scorelib.segA(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // scorelib.segB(0);
  // scorelib.segC(1);
  // scorelib.segD(1);
  // scorelib.segE(1);
  // scorelib.segF(1);
  // scorelib.segG(1);
}