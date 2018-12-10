#include <stdint.h>

#ifndef Encoder_h
#define Encoder_h

/* Enable the encoder by specifying the pins used by the encoder */
void setupEncoder(uint8_t ela_pin, uint8_t elb_pin, uint8_t era_pin, uint8_t erb_pin);

/* Get the encoder count for the left and right wheel */
uint32_t getEncoderLeftCnt();
uint32_t getEncoderRightCnt();

/* Reset the encoder count for the left and right wheel to zero */
void resetLeftEncoderCnt();
void resetRightEncoderCnt();

/* Determine the direction the wheel is turning
 * Use:
 *     WHEEL_DIR_FORWARD to see if its going forward
 *     WHEEL_DIR_BACKWARD to see if its going backwards
 */
#define WHEEL_DIR_FORWARD	1
#define WHEEL_DIR_BACKWARD	0

uint8_t getLeftWheelDir();
uint8_t getRightWheelDir();

/* Determine how far (in inches) the wheel has turned based on encoder count. */
float distanceTraveled(float wheel_diam, uint16_t cnt_per_rev, uint8_t current_cnt);

/* How many encoder pulses required to travel a certain amount of distance (in inches)*/
uint32_t countForDistance(float wheel_diam, uint16_t cnt_per_rev, uint32_t distance);

#endif
