#include <Arduino.h>
#include "score_lib.h"

Scorelib scorelib(2,3,4,5,6,7,8,9,10,11,12);

void setup() {
  scorelib.segA(1);
  scorelib.segB(1);
  scorelib.segC(0);
  scorelib.segD(0);
  scorelib.segE(0);
  scorelib.segF(0);
  scorelib.segG(0);
}

void loop() {
  // put your main code here, to run repeatedly:
}