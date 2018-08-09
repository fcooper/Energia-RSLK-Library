#include "RSLKLib.h"


RSLKLib::RSLKLib()
{



}

void RSLKLib::configure() {
    bump_sw_pin[0] = 58;
    bump_sw_pin[1] = 57;
    bump_sw_pin[2] = 41;
    bump_sw_pin[3] = 43;
    bump_sw_pin[4] = 60;
    bump_sw_pin[5] = 51;

    ir_sensor_pin[0] = 59;
    ir_sensor_pin[1] = 33;
    ir_sensor_pin[2] = 42;

    left_slp_pin = 24;  // P4.0
    left_dir_pin = 25;  // P4.2
    left_pwm_pin = 11;  // P5.2

    right_slp_pin = 26;  // P4.4
    right_dir_pin = 27;  // P4.5
    right_pwm_pin = 35;  // P6.7

    line_sensor_ir_pin = 61; // P5.3
    line_sensor_pin[0] = 65; // P7.0
    line_sensor_pin[1] = 48; // P7.1
    line_sensor_pin[2] = 64; // P7.2
    line_sensor_pin[3] = 47; // P7.3
    line_sensor_pin[4] = 52; // P7.4
    line_sensor_pin[5] = 68; // P7.5
    line_sensor_pin[6] = 53; // P7.6
    line_sensor_pin[7] = 69; // P7.7

    era_pin = 10; // P6.4
    erb_pin = 30; // P5.5
    ela_pin = 17; // P5.7
    elb_pin = 38; // P2.4

    configurePins();

    turnOffMotor();
}
void RSLKLib::setLeftMotorSpeed(uint8_t speed) {
   int val = map(speed, 0, 100, 0, 255);
   cur_lmotor_speed = val;
   analogWrite(left_pwm_pin, val);
}

void RSLKLib::setRightMotorSpeed(uint8_t speed) {
    int val = map(speed, 0, 100, 0, 255);
    cur_rmotor_speed = val;
    analogWrite(right_pwm_pin, val);
}

void RSLKLib::enableMotor() {
    digitalWrite(left_slp_pin, HIGH);
    digitalWrite(right_slp_pin, HIGH);
}

void RSLKLib::disableMotor() {
    digitalWrite(left_slp_pin, LOW);
    digitalWrite(right_slp_pin, LOW);
}

void RSLKLib::turnOnMotor() {
    setLeftMotorSpeed(0);
    setRightMotorSpeed(0);
    enableMotor();
}


void RSLKLib::turnOffMotor() {
    setLeftMotorSpeed(0);
    setRightMotorSpeed(0);
    disableMotor();
}


void RSLKLib::setMotorDirectionBackward() {
    setLeftMotorDirectionBackward();
    setRightMotorDirectionBackward();
}

void RSLKLib::setMotorDirectionForward() {
    setLeftMotorDirectionForward();
    setRightMotorDirectionForward();
}

void RSLKLib::setLeftMotorDirectionBackward() {
    digitalWrite(left_dir_pin, HIGH);
}

void RSLKLib::setLeftMotorDirectionForward() {
    digitalWrite(left_dir_pin, LOW);
}

void RSLKLib::setRightMotorDirectionBackward() {
    digitalWrite(right_dir_pin, HIGH);
}

void RSLKLib::setRightMotorDirectionForward() {
    digitalWrite(right_dir_pin, LOW);
}

bool RSLKLib::readBumpSW(uint8_t index) {
    return digitalRead(bump_sw_pin[index]);
}

uint8_t RSLKLib::readDistanceSensorValue(uint8_t index) {
    return analogRead(ir_sensor_pin[index]);
}

void RSLKLib::configurePins()
{
    uint8_t x;

    pinMode(left_slp_pin, OUTPUT);      // sets the digital pin as output
    pinMode(left_dir_pin, OUTPUT);      // sets the digital pin as output
    pinMode(left_pwm_pin, OUTPUT);      // sets the digital pin as output
    
    pinMode(right_slp_pin, OUTPUT);      // sets the digital pin as output
    pinMode(right_dir_pin, OUTPUT);      // sets the digital pin as output
    pinMode(right_pwm_pin, OUTPUT);      // sets the digital pin as output

    turnOffMotor();

    for(x = 0;x<6;x++)
        pinMode(bump_sw_pin[x], INPUT_PULLUP); 

    for(x = 0;x<3;x++)
        pinMode(ir_sensor_pin[x], INPUT_PULLUP);    
}