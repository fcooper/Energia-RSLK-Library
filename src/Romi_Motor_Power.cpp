#include "Romi_Motor_Power.h"


Romi_Motor_Power::Romi_Motor_Power()
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
bool Romi_Motor_Power::begin(uint8_t islp_pin, uint8_t idir_pin,uint8_t ipwm_pin) {

 

    slp_pin = islp_pin;
    dir_pin = idir_pin;
    pwm_pin = ipwm_pin;

    pinMode(slp_pin, OUTPUT);
    pinMode(dir_pin, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
}

void Romi_Motor_Power::disableMotor() {
	// Workaround (Sleep pin isn't working for now)
	setSpeedRaw(0);
    digitalWrite(slp_pin, LOW);
}

void Romi_Motor_Power::enableMotor() {
    digitalWrite(slp_pin, HIGH);
}

void Romi_Motor_Power::pauseMotor() {
    sleep_speed = preserve_speed;
    setSpeedRaw(0);
    disableMotor();
}

void Romi_Motor_Power::resumeMotor() {
    preserve_speed = sleep_speed;
    setSpeedRaw(preserve_speed);
    enableMotor();
}

void Romi_Motor_Power::directionForward() {
    digitalWrite(dir_pin, LOW);
}

void Romi_Motor_Power::directionBackward() {
    digitalWrite(dir_pin, HIGH);
}

bool Romi_Motor_Power::setSpeed(uint8_t speed) {
    speed = map(speed, 0, 100, 0, 255);
    preserve_speed = speed;
    analogWrite(pwm_pin, speed);
    return true;
}

bool Romi_Motor_Power::setSpeedRaw(uint8_t speed) {
    preserve_speed = speed;
    analogWrite(pwm_pin, speed);

    return true;
}