#include <Arduino.h>

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

        void display(bool n[23]) {
            u2[4] = n[0]; 
            u2[6] = n[1];
            u1[4] = n[2];
            u1[5] = n[3];
            u1[7] = n[4];
            u1[6] = n[5];
            u1[0] = n[6];
            u1[1] = n[7];
            u3[6] = n[8];
            u3[7] = n[9];
            u3[0] = n[10];
            u3[1] = n[11];
            u3[2] = n[12];
            u3[3] = n[13];
            u3[5] = n[14];
            u3[4] = n[15];
            u2[0] = n[16];
            u2[2] = n[17];
            u2[3] = n[18];
            u2[7] = n[19];
            u2[1] = n[20];
            u1[3] = n[21];
            u1[2] = n[22];
            print();
        }



        
    private:
        bool u1[8] = {0,0,0,0,0,0,0,0};
        bool u2[8] = {0,0,0,0,0,0,0,0};
        bool u3[8] = {0,0,0,0,0,0,0,0};
        bool chip_select_C = 0;
        bool chip_select_B = 0;
        bool chip_select_A = 0;

        void enable_output(void) {
            digitalWrite(oe_pin, LOW);
            delay(10);
            digitalWrite(oe_pin, HIGH);
        }

        void print(void) {
            // conntrol U1
            chip_select_C = 0;
            chip_select_B = 0;
            chip_select_A = 1;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], u1[i]);  // control Q U1
                Serial.print(u1[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], chip_select_A);
            digitalWrite(select_pin[1], chip_select_B);
            digitalWrite(select_pin[2], chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U2
            chip_select_C = 0;
            chip_select_B = 0;
            chip_select_A = 0;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], u2[i]);  // control Q U2
                Serial.print(u2[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], chip_select_A);
            digitalWrite(select_pin[1], chip_select_B);
            digitalWrite(select_pin[2], chip_select_C);

            enable_output();
            //-----------------------------------------------------------

            // conntrol U3
            chip_select_C = 0;
            chip_select_B = 1;
            chip_select_A = 0;

            for (int i=0; i<8; i++) {
                digitalWrite(q_pin[i], u3[i]);  // control Q U3
                Serial.print(u3[i]);
            } 
            Serial.println("");

            // control chip select
            digitalWrite(select_pin[0], chip_select_A);
            digitalWrite(select_pin[1], chip_select_B);
            digitalWrite(select_pin[2], chip_select_C);

            enable_output();
            //-----------------------------------------------------------
        }      
};
