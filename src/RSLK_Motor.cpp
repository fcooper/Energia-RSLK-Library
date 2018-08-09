#include "RSLKLib.h"


RSLK_Motor::RSLK_Encoder()
{
    slp_pin = 0;
    dir_pin = 0;
    pwm_pin = 0;
    preserve_speed = 0;

    motor_dir = 0;
}

/*  OPTION
    ENCA_ONLY
    ENCA_COUNT_ENCB_COUNT
    ENCA_COUNT_ENCB_DIR

*/
bool RSLK_Motor::begin(uint8_t islp_pin, uint8_t idir_pin,uint8_t ipwm_pin) {

    if(slp_pin == 0 || dir_pin == 0 || pwm_pin == 0)
        return false;

    slp_pin = islp_pin;
    dir_pin = idir_pin;
    pwm_pin = ipwm_pin;

    pinMode(slp_pin, OUTPUT);
    pinMode(dir_pin, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
}

void RSLK_Motor::disableMotor() {
    digitalWrite(slp_pin, LOW);
}

void RSLK_Motor::enableMotor() {
    digitalWrite(slp_pin, HIGH);
}

void RSLK_Motor::pauseMotor() {
    sleep_speed = preserve_speed;
    setSpeedRaw(0);
    disableMotor();
}

void RSLK_Motor::resumeMotor() {
    preserve_speed = sleep_speed;
    setSpeedRaw(preserve_speed);
    enableMotor();
}

void RSLK_Motor::directionForward() {
    digitalWrite(dir_pin, LOW);
}

void RSLK_Motor::directionBackward() {
    digitalWrite(dir_pin, HIGH);
}

bool RSLKLib::setSpeed(uint8_t speed) {

    if(speed > 100)
        return false;

    speed = map(speed, 0, 100, 0, 255);
    preserve_speed = speed;
    analogWrite(pwm_pin, speed);
    return true;
}

bool RSLKLib::setSpeedRaw(uint8_t speed) {

    if(speed > 255)
        return false;

    preserve_speed = speed;
    analogWrite(pwm_pin, speed);

    return true;
}