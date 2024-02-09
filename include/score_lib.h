#include <Arduino.h>

class Display_block {
    public:
        bool u1[8] = {0,0,0,0,0,0,0,0};
        bool u2[8] = {0,0,0,0,0,0,0,0};
        bool u3[8] = {0,0,0,0,0,0,0,0};
        bool u6[8] = {0,0,0,0,0,0,0,0};
        bool u7[8] = {0,0,0,0,0,0,0,0};
        bool u8[8] = {0,0,0,0,0,0,0,0};

        bool chip_select_C = 0;
        bool chip_select_B = 0;
        bool chip_select_A = 0;
};

Display_block block1;
Display_block block2;
Display_block block3;

class Scorelib {
    public:
        int q_pin[8] = {0,0,0,0,0,0,0,0};
        int select_pin[3] = {0,0,0};
        int oe_pin = 0;
        Scorelib(int _q1, int _q2, int _q3, int _q4, int _q5, int _q6, int _q7, int _q8, int _a, int _b, int _c, int _oe) {
            q_pin[0] = _q1;
            q_pin[1] = _q2;
            q_pin[2] = _q3;
            q_pin[3] = _q4;
            q_pin[4] = _q5;
            q_pin[5] = _q6;
            q_pin[6] = _q7;
            q_pin[7] = _q8;
            select_pin[0] = _a;
            select_pin[1] = _b;
            select_pin[2] = _c;
            oe_pin = _oe;

            for (int i=0; i<8; i++) {
                pinMode(q_pin[i], OUTPUT);
                digitalWrite(q_pin[i], LOW);
            }
            for (int i=0; i<3; i++) {
                pinMode(select_pin[i], OUTPUT);
                digitalWrite(select_pin[i], HIGH);
            }
            pinMode(oe_pin, OUTPUT);
            digitalWrite(oe_pin, HIGH);
        }

        void display_digit_2(bool n[23]) {
            block1.u2[4] = n[0]; 
            block1.u2[6] = n[1];
            block1.u1[4] = n[2];
            block1.u1[5] = n[3];
            block1.u1[7] = n[4];
            block1.u1[6] = n[5];
            block1.u1[0] = n[6];
            block1.u1[1] = n[7];
            block1.u3[6] = n[8];
            block1.u3[7] = n[9];
            block1.u3[0] = n[10];
            block1.u3[1] = n[11];
            block1.u3[2] = n[12];
            block1.u3[3] = n[13];
            block1.u3[5] = n[14];
            block1.u3[4] = n[15];
            block1.u2[0] = n[16];
            block1.u2[2] = n[17];
            block1.u2[3] = n[18];
            block1.u2[7] = n[19];
            block1.u2[1] = n[20];
            block1.u1[3] = n[21];
            block1.u1[2] = n[22];
            print_board1();
        }

        void display_digit_1 (bool n[23]) {
            block1.u7[4] = n[0]; 
            block1.u7[6] = n[1];
            block1.u6[4] = n[2];
            block1.u6[5] = n[3];
            block1.u6[7] = n[4];
            block1.u6[6] = n[5];
            block1.u6[0] = n[6];
            block1.u6[1] = n[7];
            block1.u8[6] = n[8];
            block1.u8[7] = n[9];
            block1.u8[0] = n[10];
            block1.u8[1] = n[11];
            block1.u8[2] = n[12];
            block1.u8[3] = n[13];
            block1.u8[5] = n[14];
            block1.u8[4] = n[15];
            block1.u7[0] = n[16];
            block1.u7[2] = n[17];
            block1.u7[3] = n[18];
            block1.u7[7] = n[19];
            block1.u7[1] = n[20];
            block1.u6[3] = n[21];
            block1.u6[2] = n[22];
            print_board1();
        }



        
    private:
        void enable_output(void) {
            digitalWrite(oe_pin, LOW);
            delay(10);
            digitalWrite(oe_pin, HIGH);
        }

        void print_board1(void) {
            // conntrol U1
            block1.chip_select_C = 0;
            block1.chip_select_B = 0;
            block1.chip_select_A = 1;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u1[i]);  // control Q U1
                Serial.print(block1.u1[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U2
            block1.chip_select_C = 0;
            block1.chip_select_B = 0;
            block1.chip_select_A = 0;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u2[i]);  // control Q U2
                Serial.print(block1.u2[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U3
            block1.chip_select_C = 0;
            block1.chip_select_B = 1;
            block1.chip_select_A = 0;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u3[i]);  // control Q U3
                Serial.print(block1.u3[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U6
            block1.chip_select_C = 1;
            block1.chip_select_B = 0;
            block1.chip_select_A = 0;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u6[i]);  // control Q U6
                Serial.print(block1.u6[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U7
            block1.chip_select_C = 0;
            block1.chip_select_B = 1;
            block1.chip_select_A = 1;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u7[i]);  // control Q U7
                Serial.print(block1.u7[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U8
            block1.chip_select_C = 1;
            block1.chip_select_B = 0;
            block1.chip_select_A = 1;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], block1.u8[i]);  // control Q U8
                Serial.print(block1.u8[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], block1.chip_select_A);
            digitalWrite(select_pin[1], block1.chip_select_B);
            digitalWrite(select_pin[2], block1.chip_select_C);

            enable_output();
        }      
};
