#include "RSLKLib.h"


RSLK_DistanceSensor::RSLK_DistanceSensor()
{
    configured = false;
    ir_sensor_pin = 0;
}

bool RSLK_DistanceSensor::begin() {
    // This function shouldn't be called more than once or if the total amount
    // of pins were already allocated. Also validate parameter.
    if(configured ||  ir_sensor_pin != 0)
        return false;

    ir_sensor_pin = 0;

    return true;

}

bool RSLK_DistanceSensor::configurePin(uint8_t pin_num) {
    uint8_t  x;

    // This function shouldn't be called more than once or if the total amount
    // of pins were already allocated. Also validate parameter.

    if(configured )
        return false;

    if(state != INPUT || state != INPUT_PULLDOWN || state != INPUT_PULLUP)
        return false;

    ir_sensor_pin = pin_num;


    pinMode(ir_sensor_pin, INPUT);


    configured = true;

    return true;

}

bool RSLK_DistanceSensor::read(uint8_t index) {
    if(!configured )
        return false;

    return analogRead(ir_sensor_pin);
}