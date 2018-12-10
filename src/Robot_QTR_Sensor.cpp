#include "Robot_QTR_Sensor.h"
#include "QTRSensors.h"

QTRSensorsRC qtrrc;

#define TOTAL_LS_SENSORS    8 // number of sensors used
#define LS_TIMEOUT          2500  // waits for 2500 microseconds for sensor outputs to go low

void qtr8_sensor_init(uint8_t pin_1,
                      uint8_t pin_2,
                      uint8_t pin_3,
                      uint8_t pin_4,
                      uint8_t pin_5,
                      uint8_t pin_6,
                      uint8_t pin_7,
                      uint8_t pin_8,
                      uint16_t timeout,
                      uint8_t ir_pin)
{
    unsigned char pins[TOTAL_LS_SENSORS];
    
    pins[0] = pin_1;
    pins[1] = pin_2;
    pins[2] = pin_3;
    pins[3] = pin_4;
    pins[4] = pin_5;
    pins[5] = pin_6;
    pins[6] = pin_7;
    pins[7] = pin_8;
    
    qtrrc.init(pins, TOTAL_LS_SENSORS, LS_TIMEOUT, ir_pin);
}

uint8_t lineLocation(bool lineType) {

    unsigned int sensorValues[TOTAL_LS_SENSORS];
    qtrrc.read(sensorValues);

    
    float left = sensorValues[0] + sensorValues[1] + sensorValues[2];
    left /= 3.0;
    
    float center = sensorValues[3] + sensorValues[4];
    center /= 2.0;
    
    float right = sensorValues[5] + sensorValues[6] + sensorValues[7];
    right /= 3.0;
    
    
    if(lineType == WHITE_LINE) {
        if(right < center)
        {
          return LINE_RIGHT;
        }
        else if (left < center)
        {
          return LINE_LEFT;
        }
        else {
          return LINE_CENTER;
        }
    }
    else {
        if(right > center)
        {
          return LINE_RIGHT;
        }
        else if (left > center)
        {
          return LINE_LEFT;
        }
        else {
          return LINE_CENTER;
        }
    }
}
