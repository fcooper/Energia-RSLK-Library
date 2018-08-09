#include "Energia.h"
#include "RSLK_Encoder.h"
#include "RSLK_Motor.h"
#include "RSLK_BPSW.h"
#include "RSLK_DistanceSensor.h"

#define RSLK_LMOTOR = 0
#define RSLK_RMOTOR = 1;

#define RSLK_LENCODER = 0;
#define RSLK_RENCODER = 1;

#define RSLK_BP_SW_1 = 0;
#define RSLK_BP_SW_2 = 1;
#define RSLK_BP_SW_3 = 2;
#define RSLK_BP_SW_4 = 3;
#define RSLK_BP_SW_5 = 4;
#define RSLK_BP_SW_6 = 5;

#define RSLK_DST_LEFT = 0;
#define RSLK_DST_CENTER = 1;
#define RSLK_DST_RIGHT = 2;


class RSLKLib 
{
    private:
        RSLK_Motor lmotor;
        RSLK_Motor rmotor;
        RSLK_Encoder encoder[2];
        RSLK_BPSW bp_sw[6];
        RSLK_DistanceSensor dst_sensor[3];



public:
    RSLKLib();
    void begin();
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
