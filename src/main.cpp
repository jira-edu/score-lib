#include <Arduino.h>
#include "score_lib.h"

volatile uint32_t c = 0;
volatile uint32_t sec_count = 0;

int sec_buff;
int x_digit;
int y_digit;

Scorelib scorelib(3,4,5,10,11,12,13);

bool num[10][23] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},  // 0
  {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},  // 1
  {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1},  // 2
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1},  // 3
  {1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1},  // 4
  {1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1}, // 5
  {1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 6
  {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},  // 8
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1}  // 9
};

void INT_count() {
  if (c < 32768) {
    c++;
  } else {
    c = 0;
    sec_count++;
  }
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), INT_count, RISING);

  scorelib.display_number(1, num[0]);
  scorelib.display_number(2, num[1]);  
  scorelib.display_number(3, num[2]);
  scorelib.display_number(4, num[3]);
  delay(1000);

  for (int i=0; i<5; i++) {
    scorelib.display_number(2, num[i]);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sec_buff = sec_count;
  x_digit = 0;
  y_digit = 0;

  while (sec_buff >= 10) {
    sec_buff = sec_buff-10;
    x_digit++;
  } 
  while (sec_buff >= 1) {
    sec_buff = sec_buff-1;
    y_digit++;
  }
  
  scorelib.display_number(1, num[x_digit]);
  scorelib.display_number(2, num[y_digit]);
  delay(100);
}