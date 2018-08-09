#include "Energia.h"

class RSLK_DistanceSensor 
{
    private:
        uint8_t ir_sensor_pin;
        uint8_t num_pins;
        bool configured;

    public:
        RSLK_DistanceSensor();
        bool begin(uint8_t pin_num);
        bool read();
};