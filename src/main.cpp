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

  scorelib.display_number(1, num[4]);
  scorelib.display_number(2, num[8]);
  // scorelib.display_digit_1(num[0]);
  // scorelib.display_digit_2(num[0]);
  // delay(1000);
  // scorelib.display_digit_2(num[0]);
  // delay(1000);
  // scorelib.display_digit_2(num[1]);
  // delay(1000);
  // scorelib.display_digit_2(num[2]);
  // delay(1000);
  // scorelib.display_digit_2(num[3]);
  // delay(1000);
  // scorelib.display_digit_2(num[4]);
  // delay(1000);
  // scorelib.display_digit_1(num[1]);
  // delay(1000);
  // scorelib.display_digit_1(num[2]);
  // delay(1000);
  // scorelib.display_digit_1(num[3]);
  // delay(1000);
  // scorelib.display_digit_1(num[4]);
  // delay(1000);
  


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