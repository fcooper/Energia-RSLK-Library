#include <stdlib.h>
#include "Energia.h"
#include "Encoder.h"

uint32_t enc_left_cnt = -1;
uint32_t enc_right_cnt = -1;
uint8_t enc_left_wheel_dir = -1;
uint8_t enc_right_wheel_dir = -1;

uint8_t _era_pin;
uint8_t _erb_pin;
uint8_t _ela_pin;
uint8_t _elb_pin;

void setupEncoder(uint8_t era_pin, uint8_t erb_pin, uint8_t ela_pin, uint8_t _elb_pin) {

    pinMode(_era_pin, INPUT_PULLDOWN );      // sets the digital pin as output
    pinMode(_erb_pin, INPUT_PULLDOWN );      // sets the digital pin as output
    pinMode(_ela_pin, INPUT_PULLDOWN );      // sets the digital pin as output
    pinMode(_elb_pin, INPUT_PULLDOWN );      // sets the digital pin as output   

    attachInterrupt(digitalPinToInterrupt(era_pin),triggerRightEncoder,RISING);
    attachInterrupt(digitalPinToInterrupt(ela_pin),triggerLeftEncoder,RISING);  
}

uint32_t getEncoderLeftCnt() {
    return enc_left_cnt;
}

void resetLeftEncoderCnt() {
    enc_left_cnt = 0;
}

void resetRightEncoderCnt() {
    enc_right_cnt = 0;
}

uint32_t getEncoderRightCnt() {
    return enc_right_cnt;
}
uint8_t getLeftWheelDir() {
    return enc_left_wheel_dir;
}
uint8_t getRightWheelDir() {
    return enc_right_wheel_dir;   
}


void triggerLeftEncoder() {
    if(enc_left_cnt == -1) {
        enc_left_cnt = 0;
        enc_left_wheel_dir = 0;
    }
    
    enc_left_cnt++;
    enc_left_wheel_dir = digitalRead(_elb_pin); 
}

void triggerRightEncoder() {
    if(enc_right_cnt == -1) {
        enc_right_cnt = 0;
        enc_right_wheel_dir = 0;
    }    
    
    enc_right_cnt++;
    enc_right_wheel_dir = digitalRead(_erb_pin);   
}