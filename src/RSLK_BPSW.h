#include "Energia.h"

class RSLK_BPSW 
{
    private:
        uint8_t bump_sw_pin;
        uint8_t num_pins;
        bool configured;

    public:
        RSLK_BPSW();
        bool begin();
        bool configurePin(uint8_t pin_num, uint8_t state);
        bool read();
        bool enableInput();
        bool enableInputPullDown();
        bool enableInputPullUp();
};