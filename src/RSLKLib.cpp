#include "RSLKLib.h"


RSLKLib::RSLKLib()
{



}

void RSLKLib::begin() {
    bp_sw[RSLK_BP_SW_1].configurePin(58, INPUT_PULLUP);
    bp_sw[RSLK_BP_SW_2].configurePin(57, INPUT_PULLUP);
    bp_sw[RSLK_BP_SW_3].configurePin(41, INPUT_PULLUP);
    bp_sw[RSLK_BP_SW_4].configurePin(43, INPUT_PULLUP);
    bp_sw[RSLK_BP_SW_5].configurePin(60, INPUT_PULLUP);
    bp_sw[RSLK_BP_SW_6].configurePin(51, INPUT_PULLUP);


    dst_sensor[RSLK_DST_LEFT].begin(59);
    dst_sensor[RSLK_DST_CENTER].begin(33);
    dst_sensor[RSLK_DST_RIGHT].begin(42);

    encoder[RSLK_LENCODER].begin(10,INPUT_PULLDOWN,30,INPUT_PULLDOWN,ENCA_COUNT_ENCB_DIR);
    encoder[RSLK_RENCODER].begin(17,INPUT_PULLDOWN,38,INPUT_PULLDOWN,ENCA_COUNT_ENCB_DIR);

    motor[RSLK_LMOTOR].begin(24,25,11);
    motor[RSLK_RMOTOR].begin(26,27,35);

    disableMotors();
}

void RSLKLib::setMotorSpeed(int index,uint8_t speed) {
    if(index != 0 && index != 1)
        return;

    motor[index].setSpeed(speed);
}

void RSLKLib::setMotorsSpeed(uint8_t speed) {
    motor[RSLK_LMOTOR].setSpeed(speed);
    motor[RSLK_RMOTOR].setSpeed(speed);
}

void RSLKLib::disableMotors() {
    motor[RSLK_LMOTOR].disableMotor();
    motor[RSLK_RMOTOR].disableMotor();
}

void RSLKLib::enableMotors() {
    motor[RSLK_LMOTOR].enableMotor();
    motor[RSLK_RMOTOR].enableMotor();
}


void RSLKLib::pauseMotor(uint8_t index) {
    if(index != 0 && index != 1)
        return;

    motor[index].pauseMotor(speed);
}

void RSLKLib::pauseMotors() {
    pauseMotor(RSLK_LMOTOR);
    pauseMotor(RSLK_RMOTOR);
}

void RSLKLib::motorDirectionForward(int index) {
    if(index != 0 && index != 1)
        return;

    motor[index].directionForward();
}

void RSLKLib::motorsDirectionForward() {
    motorDirectionForward(RSLK_LMOTOR);
    motorDirectionForward(RSLK_RMOTOR);
}

void RSLKLib::motorDirectionBackward(int index) {
    if(index != 0 && index != 1)
        return;

    motor[index].directionBackward();
}

void RSLKLib::motorsDirectionBackward() {
    directionBackward(RSLK_LMOTOR);
    directionBackward(RSLK_RMOTOR);
}

void RSLKLib::setMotorSpeedRaw(int index,uint8_t speed) {

    if(index != 0 && index != 1)
        return;

    motor[index].setSpeedRaw(speed);
}

void RSLKLib::setMotorsSpeedRaw(uint8_t speed) {
    motor[RSLK_LMOTOR].setSpeedRaw(speed);
    motor[RSLK_RMOTOR].setSpeedRaw(speed);
}


void RSLKLib::readBumpSwitch(uint8_t index) {
    if(index > 5)
        return;

    return bp_sw[index].read();
}

void RSLKLib::readDistanceSensor(uint8_t index) {
    if(index > 2)
        return ;
    return dst_sensor[index].read();
}