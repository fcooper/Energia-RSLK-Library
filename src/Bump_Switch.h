#ifndef Bump_Switch_h
#define Bump_Switch_h

#include "Energia.h"

class Bump_Switch 
{
    private:
        uint8_t bump_sw_pin;
        uint8_t num_pins;
        bool configured;

    public:
        Bump_Switch();
        bool begin(uint8_t pin_num, uint8_t state = INPUT_PULLUP);
        bool read();
        bool enableInput();
        bool enableInputPullDown();
        bool enableInputPullUp();
};
#endif