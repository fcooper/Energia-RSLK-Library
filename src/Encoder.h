#include <stdint.h>

#ifndef Encoder_h
#define Encoder_h

void setupEncoder(uint8_t,uint8_t,uint8_t,uint8_t);
void triggerLeftEncoder();
void triggerRightEncoder();

uint32_t getEncoderLeftCnt();
uint32_t getEncoderRightCnt();
uint8_t getLeftWheelDir();
uint8_t getRightWheelDir();
void resetLeftEncoderCnt();
void resetRightEncoderCnt();
#define WHEEL_DIR_FORWARD 1
#define WHEEL_DIR_BACKWARD 0
#endif