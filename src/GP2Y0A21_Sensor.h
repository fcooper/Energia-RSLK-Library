#ifndef GP2Y0A21_Sensor_h
#define GP2Y0A21_Sensor_h

#include "Energia.h"

class GP2Y0A21_Sensor 
{
    private:
        uint8_t ir_sensor_pin;
        uint8_t num_pins;
        bool configured;

    public:
        GP2Y0A21_Sensor();
        bool begin(uint8_t pin_num,uint8_t state = INPUT_PULLDOWN);
        uint16_t read();
};

#endif