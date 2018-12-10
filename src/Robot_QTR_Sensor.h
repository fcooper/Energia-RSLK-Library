#include <stdint.h>

#ifndef RobotQTRSensor_h
#define RobotQTRSensor_h

#define WHITE_LINE  0
#define DARK_LINE   1

#define LINE_CENTER 0
#define LINE_LEFT   1
#define LINE_RIGHT  2

void qtr8_sensor_init(uint8_t pin_1,
                      uint8_t pin_2,
                      uint8_t pin_3,
                      uint8_t pin_4,
                      uint8_t pin_5,
                      uint8_t pin_6,
                      uint8_t pin_7,
                      uint8_t pin_8,
                      uint16_t timeout,
                      uint8_t ir_pin);
                      
uint8_t lineLocation(bool lineType);
#endif