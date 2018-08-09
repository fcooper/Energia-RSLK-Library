#include "RSLKLib.h"


RSLK_BPSW::RSLK_BPSW()
{
    configured = false;
    num_pins = 0;
    bump_sw_pin = 0;
}

bool RSLK_BPSW::begin(uint8_t pin_num, uint8_t state) {
    uint8_t  x;

    // This function shouldn't be called more than once or if the total amount
    // of pins were already allocated. Also validate parameter.

    if(configured || num_pins == 0 )
        return false;

    if(state != INPUT || state != INPUT_PULLDOWN || state != INPUT_PULLUP)
        return false;

    bump_sw_pin = pin_num;

    pinMode(bump_sw_pin,state);


    configured = true;

    return true;

}

bool RSLK_BPSW::read() {

    if(!configured)
        return false;

    return digitalRead(bump_sw_pin);
}

bool RSLK_BPSW::enableInput() {


    pinMode(bump_sw_pin, INPUT);

    return true;
}

bool RSLK_BPSW::enableInputPullDown() {

    pinMode(bump_sw_pin, INPUT_PULLDOWN);

    return true;
}

bool RSLK_BPSW::enableInputPullUp() {
    pinMode(bump_sw_pin, INPUT_PULLUP);

    return true;
}