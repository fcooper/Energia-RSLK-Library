#include "RSLKLib.h"


RSLK_Encoder::RSLK_Encoder()
{
    configured = false;
    num_pins = 0;
    encoder_pin[0] = encoder_pin[1] = 0;
    encoder_count[0] = encoder_count[1] = 0;
    direction = 0;
    option = ENCA_COUNT_ENCB_DIR;
}

/*  OPTION
    ENCA_ONLY
    ENCA_COUNT_ENCB_COUNT
    ENCA_COUNT_ENCB_DIR

*/
bool RSLK_Encoder::begin(uint8_t enc_a_pin, uint8_t enc_a_state,uint8_t enc_b_pin,uint8_t enc_b_state,uint8_t enc_option) {
    uint8_t  x;

    // This function shouldn't be called more than once or if the total amount
    // of pins were already allocated. Also validate parameter.

    if(configured || option > 2 || enc_a_pin == 0 || enc_b_pin == 0 || enc_a_state > 3 || enc_b_state > 3)
        return false;

    option = enc_option;
    encoder_pin[0] = enc_a_pin;
    encoder_pin[1] = enc_b_pin;

    if(option == ENCA_ONLY) {
        encoder_pin[1] = 0;
    }

    pinMode(encoder_pin[0], enc_a_state);

    if(option != ENCA_ONLY) {
        pinMode(encoder_pin[1], enc_b_state);
    }

    configured = true;

    attachInterrupt(encoder_pin[0], encAIsr, FALLING);

    if(option == ENCA_COUNT_ENCB_COUNT) {
        attachInterrupt(encoder_pin[1], encBIsr, FALLING);
    }
    
    return true;

}

uint32_t RSLK_Encoder::getCount(uint8_t index) {

    if(index == 0 && option == ENCB_COUNT_ENCA_DIR)
        return 0;

    if(index > 1 || (index == 1 && ENCA_COUNT_ENCB_DIR))
        return 0;

    return encoder_count[index];
}

void RSLK_Encoder::clearCount() {
    encoder_count[0] = encoder_count[1] = 0;
}

uint32_t RSLK_Encoder::getCountClear(uint8_t index) {

    uint32_t temp;

    if(!configured)
        return 0;

    if(index == 0 && option == ENCB_COUNT_ENCA_DIR)
        return 0;

    if(index > 1 || (index == 1 && ENCA_COUNT_ENCB_DIR))
        return 0;

    temp = encoder_count[index];

    encoder_count[index] = 0;

    return temp;
}

uint8_t RSLK_Encoder::getDirection() {

    if(!configured || option != ENCB_COUNT_ENCA_DIR)
        return false;

    if( digitalRead(encoder_pin[1]) == 0)
        return MOTOR_DIR_FW;
    else
        return MOTOR_DIR_BW;
}

void RSLK_Encoder::encAIsr()
{
    if(!configured)
        return;

    encoder_count[0]++;

    if(option == ENCB_COUNT_ENCA_DIR) {
        if( digitalRead(encoder_pin[1]) == 0)
            direction =  MOTOR_DIR_FW;
        else
            direction =  MOTOR_DIR_BW;
    }
}

void RSLK_Encoder::encBIsr()
{
    if(!configured)
        return;
    encoder_count[1]++;
}