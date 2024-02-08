#include <Arduino.h>
#include "score_lib.h"

Scorelib scorelib(2,3,4,5,6,7,8,9,10,11,12,13);
bool test0[23] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};
bool test1[23] = {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0};
bool test2[23] = {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1};
bool test3[23] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1};
bool test4[23] = {1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1};
void setup() {
  Serial.begin(9600);

  scorelib.display(test0);
  delay(1000);
  scorelib.display(test1);
  delay(1000);
  scorelib.display(test2);
  delay(1000);
  scorelib.display(test3);
  delay(1000);
  scorelib.display(test4);


  // for (int i=0; i<8; i++) {
  //   digitalWrite(scorelib.q_pin[i], test_arr[i]);
  // }

  // digitalWrite(scorelib.select_pin[0], 0);
  // digitalWrite(scorelib.select_pin[1], 1);
  // digitalWrite(scorelib.select_pin[2], 0);

  // scorelib.enable_output();
}

void loop() {
  // put your main code here, to run repeatedly:
}