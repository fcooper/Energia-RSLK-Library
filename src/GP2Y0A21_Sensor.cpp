#include "GP2Y0A21_Sensor.h"


GP2Y0A21_Sensor::GP2Y0A21_Sensor()
{
    ir_sensor_pin = 0;
}

bool GP2Y0A21_Sensor::begin(uint8_t pin_num,uint8_t state) {
    ir_sensor_pin = pin_num;
    pinMode(ir_sensor_pin, state);
    return true;

}

uint16_t GP2Y0A21_Sensor::read() {
    return analogRead(ir_sensor_pin);
}