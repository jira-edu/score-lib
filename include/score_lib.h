#include <Arduino.h>

class Scorelib {
    public:
        int q_pin[8] = {0,0,0,0,0,0,0,0};
        int select_pin[3] = {0,0,0};
        Scorelib(int _q1, int _q2, int _q3, int _q4, int _q5, int _q6, int _q7, int _q8, int _a, int _b, int _c) {
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

            for (int i=0; i<8; i++) {
                pinMode(q_pin[i], OUTPUT);
            }
            for (int i=0; i<3; i++) {
                pinMode(select_pin[i], OUTPUT);
            }
        }

        void segA(bool value) {
            u1[7] = value;
            u1[5] = value;
            u1[4] = value;
            u2[6] = value;
            u2[4] = value;
            print();
        }

        void segB(bool value) {
            u2[4] = value;
            u2[7] = value;
            u2[3] = value;
            u2[2] = value;
            print();
        }

        void segC(bool value) {
            u2[2] = value;
            u2[0] = value;
            u3[4] = value;
            u3[5] = value;
            print();
        }

        void segD(bool value) {
            u3[0] = value;
            u3[1] = value;
            u3[2] = value;
            u3[3] = value;
            u3[5] = value;
            print();
        }

        void segE(bool value) {
            u1[1] = value;
            u3[6] = value;
            u3[7] = value;
            u3[0] = value;
            print();
        }

        void segF(bool value) {
            u1[7] = value;
            u1[6] = value;
            u1[0] = value;
            u1[1] = value;
            print();
        }

        void segG(bool value) {
            u1[1] = value;
            u1[2] = value;
            u1[4] = value;
            u2[1] = value;
            u2[2] = value;
            print();
        }

        
    private:
        bool u1[8] = {1,1,1,1,1,1,1,1};
        bool u2[8] = {1,1,1,1,1,1,1,1};
        bool u3[8] = {1,1,1,1,1,1,1,1};
        bool chip_select_C = 0;
        bool chip_select_B = 0;
        bool chip_select_A = 0;

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
            delay(100);
            // control chip select
            digitalWrite(select_pin[1], chip_select_A);
            digitalWrite(select_pin[2], chip_select_B);
            digitalWrite(select_pin[3], chip_select_C);
            delay(100);
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
            delay(100);
            // control chip select
            digitalWrite(select_pin[1], chip_select_A);
            digitalWrite(select_pin[2], chip_select_B);
            digitalWrite(select_pin[3], chip_select_C);
            delay(100);
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
            delay(100);
            // control chip select
            digitalWrite(select_pin[1], chip_select_A);
            digitalWrite(select_pin[2], chip_select_B);
            digitalWrite(select_pin[3], chip_select_C);
            delay(100);
        }      
};
