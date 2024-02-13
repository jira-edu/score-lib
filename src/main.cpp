#include <Arduino.h>
#include "score_lib.h"

Scorelib scorelib(2,3,4,10,11,12,13);

bool num[10][23] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},  // 0
  {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},  // 1
  {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1},  // 2
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1},  // 3
  {1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1},  // 4
  {}, // 5
  {}, // 6
  {}, // 7
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},  // 8
  {}  // 9
};

void setup() {
  Serial.begin(9600);

  scorelib.display_number(1, num[0]);
  scorelib.display_number(2, num[3]);  

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