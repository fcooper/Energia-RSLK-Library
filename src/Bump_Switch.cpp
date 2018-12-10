#include "Bump_Switch.h"

Bump_Switch::Bump_Switch()
{
    configured = false;
    num_pins = 0;
    bump_sw_pin = 0;
}

bool Bump_Switch::begin(uint8_t pin_num, uint8_t state) {
    bump_sw_pin = pin_num;
    pinMode(bump_sw_pin,state);

    return true;
}

bool Bump_Switch::read() {
    return digitalRead(bump_sw_pin);
}

bool Bump_Switch::enableInput() {
    pinMode(bump_sw_pin, INPUT);
    return true;
}

bool Bump_Switch::enableInputPullDown() {
    pinMode(bump_sw_pin, INPUT_PULLDOWN);
    return true;

}

bool Bump_Switch::enableInputPullUp() {
    pinMode(bump_sw_pin, INPUT_PULLUP);
    return true;
}