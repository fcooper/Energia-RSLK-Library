#include "Energia.h"

class RSLKLib 
{
    private:
        uint8_t bump_sw_pin[6];
        uint8_t ir_sensor_pin[3];
        uint8_t left_slp_pin;
        uint8_t left_dir_pin;
        uint8_t left_pwm_pin;
        uint8_t right_slp_pin;
        uint8_t right_dir_pin;
        uint8_t right_pwm_pin;
        uint8_t line_sensor_pin[8];
        uint8_t line_sensor_ir_pin;

        uint8_t era_pin;
        uint8_t erb_pin;
        uint8_t ela_pin;
        uint8_t elb_pin;

        uint8_t cur_lmotor_speed;
        uint8_t cur_rmotor_speed;

        void configurePins();

public:
    RSLKLib();
    void configure();
    void setLeftMotorSpeed(uint8_t speed);
    void setRightMotorSpeed(uint8_t speed);
    void enableMotor();
    void disableMotor();
    void turnOnMotor();
    void turnOffMotor();
    void setMotorDirectionBackward();
    void setMotorDirectionForward();
    void setLeftMotorDirectionBackward();
    void setLeftMotorDirectionForward();
    void setRightMotorDirectionBackward();
    void setRightMotorDirectionForward();
    bool readBumpSW(uint8_t index);
    uint8_t readDistanceSensorValue(uint8_t index);
};
