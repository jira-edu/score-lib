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
        // int q_pin[8] = {0,0,0,0,0,0,0,0};
        int seg_clk;
        int seg_data;
        int seg_latch;

        int com_clk;
        int com_data;
        int com_latch;

        int select_pin[3] = {0,0,0};
        int oe_pin = 0;
        Scorelib(int _seg_clk, int _seg_data, int _seg_latch, int _com_clk, int _com_data, int _com_latch, int _oe) {
            // q_pin[0] = _q1;
            // q_pin[1] = _q2;
            // q_pin[2] = _q3;
            // q_pin[3] = _q4;
            // q_pin[4] = _q5;
            // q_pin[5] = _q6;
            // q_pin[6] = _q7;
            // q_pin[7] = _q8;

            seg_clk = _seg_clk;
            seg_data = _seg_data;
            seg_latch = _seg_latch;
            pinMode(seg_clk, OUTPUT);
            pinMode(seg_data, OUTPUT);
            pinMode(seg_latch, OUTPUT);

            com_clk = _com_clk;
            com_data = _com_data;
            com_latch = _com_latch;
            pinMode(com_clk, OUTPUT);
            pinMode(com_data, OUTPUT);
            pinMode(com_latch, OUTPUT);

            // select_pin[0] = _a;
            // select_pin[1] = _b;
            // select_pin[2] = _c;
            
            // for (int i=0; i<3; i++) {
            //     pinMode(select_pin[i], OUTPUT);
            //     digitalWrite(select_pin[i], HIGH);
            // }

            oe_pin = _oe;
            pinMode(oe_pin, OUTPUT);
            digitalWrite(oe_pin, HIGH);
        }

        void display_number(int digit, bool n[23]) {
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
            print_display(digit);

        }
        // void display_digit_2(bool n[23]) {
        //     block1.u2[4] = n[0]; 
        //     block1.u2[6] = n[1];
        //     block1.u1[4] = n[2];
        //     block1.u1[5] = n[3];
        //     block1.u1[7] = n[4];
        //     block1.u1[6] = n[5];
        //     block1.u1[0] = n[6];
        //     block1.u1[1] = n[7];
        //     block1.u3[6] = n[8];
        //     block1.u3[7] = n[9];
        //     block1.u3[0] = n[10];
        //     block1.u3[1] = n[11];
        //     block1.u3[2] = n[12];
        //     block1.u3[3] = n[13];
        //     block1.u3[5] = n[14];
        //     block1.u3[4] = n[15];
        //     block1.u2[0] = n[16];
        //     block1.u2[2] = n[17];
        //     block1.u2[3] = n[18];
        //     block1.u2[7] = n[19];
        //     block1.u2[1] = n[20];
        //     block1.u1[3] = n[21];
        //     block1.u1[2] = n[22];
        //     print_board1();
        // }

        // void display_digit_1 (bool n[23]) {
        //     block1.u7[4] = n[0]; 
        //     block1.u7[6] = n[1];
        //     block1.u6[4] = n[2];
        //     block1.u6[5] = n[3];
        //     block1.u6[7] = n[4];
        //     block1.u6[6] = n[5];
        //     block1.u6[0] = n[6];
        //     block1.u6[1] = n[7];
        //     block1.u8[6] = n[8];
        //     block1.u8[7] = n[9];
        //     block1.u8[0] = n[10];
        //     block1.u8[1] = n[11];
        //     block1.u8[2] = n[12];
        //     block1.u8[3] = n[13];
        //     block1.u8[5] = n[14];
        //     block1.u8[4] = n[15];
        //     block1.u7[0] = n[16];
        //     block1.u7[2] = n[17];
        //     block1.u7[3] = n[18];
        //     block1.u7[7] = n[19];
        //     block1.u7[1] = n[20];
        //     block1.u6[3] = n[21];
        //     block1.u6[2] = n[22];
        //     print_board1();
        // }



        
    private:
        bool u1[8] = {0,0,0,0,0,0,0,0};
        bool u2[8] = {0,0,0,0,0,0,0,0};
        bool u3[8] = {0,0,0,0,0,0,0,0};

        void enable_output(void) {
            digitalWrite(oe_pin, LOW);
            delay(10);
            digitalWrite(oe_pin, HIGH);
        }

        void u1_out() {
            byte buff = 0b00000000;
            for (int i=0; i<8; i++) {
                buff = buff | (u1[i] << (7-i));
            }
            Serial.println(buff, BIN);
            digitalWrite(seg_latch, LOW);
            shiftOut(seg_data, seg_clk, LSBFIRST, buff);
            digitalWrite(seg_latch, HIGH);
        }

        void u2_out() {
            byte buff = 0b00000000;
            for (int i=0; i<8; i++) {
                buff = buff | (u2[i] << (7-i));
            }
            Serial.println(buff, BIN);
            digitalWrite(seg_latch, LOW);
            shiftOut(seg_data, seg_clk, LSBFIRST, buff);
            digitalWrite(seg_latch, HIGH);
        }

        void u3_out() {
            byte buff = 0b00000000;
            for (int i=0; i<8; i++) {
                buff = buff | (u3[i] << (7-i));
            }
            Serial.println(buff, BIN);
            digitalWrite(seg_latch, LOW);
            shiftOut(seg_data, seg_clk, LSBFIRST, buff);
            digitalWrite(seg_latch, HIGH);
        }

        void common_out(byte com1) {
            Serial.println(com1);
            digitalWrite(com_latch, LOW);
            shiftOut(com_data, com_clk, LSBFIRST, com1);
            digitalWrite(com_latch, HIGH);
            delay(500);
        }

        void print_display(int digit) {
            
            switch (digit) {
                case 1:
                    u1_out();
                    common_out(0b10000000);
                    // digitalWrite(select_pin[0], 0);
                    // digitalWrite(select_pin[1], 0);
                    // digitalWrite(select_pin[2], 1);
                    enable_output();
                    u2_out();
                    common_out(0b01100000);
                    // digitalWrite(select_pin[0], 1);
                    // digitalWrite(select_pin[1], 1);
                    // digitalWrite(select_pin[2], 0);                    
                    enable_output();
                    u3_out();
                    common_out(0b10100000);
                    // digitalWrite(select_pin[0], 1);
                    // digitalWrite(select_pin[1], 0);
                    // digitalWrite(select_pin[2], 1);                    
                    enable_output();
                    break;
                case 2:
                    u1_out();
                    common_out(0b00100000);
                    // digitalWrite(select_pin[0], 1);
                    // digitalWrite(select_pin[1], 0);
                    // digitalWrite(select_pin[2], 0);
                    enable_output();
                    u2_out();
                    common_out(0b00000000);
                    // digitalWrite(select_pin[0], 0);
                    // digitalWrite(select_pin[1], 0);
                    // digitalWrite(select_pin[2], 0);                    
                    enable_output();
                    u3_out();
                    common_out(0b01000000);
                    // digitalWrite(select_pin[0], 0);
                    // digitalWrite(select_pin[1], 1);
                    // digitalWrite(select_pin[2], 0);                    
                    enable_output();
                    break;
                
                // case 2:
                //     /* code */
                //     break;
                
                default:
                    break;
            }
        }

        // void print_board1(void) {
        //     // conntrol U1
        //     block1.chip_select_C = 0;
        //     block1.chip_select_B = 0;
        //     block1.chip_select_A = 1;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u1[i]);  // control Q U1
        //         Serial.print(block1.u1[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        //     //-----------------------------------------------------------

        //     // conntrol U2
        //     block1.chip_select_C = 0;
        //     block1.chip_select_B = 0;
        //     block1.chip_select_A = 0;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u2[i]);  // control Q U2
        //         Serial.print(block1.u2[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        //     //-----------------------------------------------------------

        //     // conntrol U3
        //     block1.chip_select_C = 0;
        //     block1.chip_select_B = 1;
        //     block1.chip_select_A = 0;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u3[i]);  // control Q U3
        //         Serial.print(block1.u3[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        //     //-----------------------------------------------------------

        //     // conntrol U6
        //     block1.chip_select_C = 1;
        //     block1.chip_select_B = 0;
        //     block1.chip_select_A = 0;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u6[i]);  // control Q U6
        //         Serial.print(block1.u6[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        //     //-----------------------------------------------------------

        //     // conntrol U7
        //     block1.chip_select_C = 0;
        //     block1.chip_select_B = 1;
        //     block1.chip_select_A = 1;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u7[i]);  // control Q U7
        //         Serial.print(block1.u7[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        //     //-----------------------------------------------------------

        //     // conntrol U8
        //     block1.chip_select_C = 1;
        //     block1.chip_select_B = 0;
        //     block1.chip_select_A = 1;

        //     for (int i=0; i<8; i++) {
        //         digitalWrite(q_pin[i], block1.u8[i]);  // control Q U8
        //         Serial.print(block1.u8[i]);
        //     } 
        //     Serial.println("");

        //     // control chip select
        //     digitalWrite(select_pin[0], block1.chip_select_A);
        //     digitalWrite(select_pin[1], block1.chip_select_B);
        //     digitalWrite(select_pin[2], block1.chip_select_C);

        //     enable_output();
        // }      
};
