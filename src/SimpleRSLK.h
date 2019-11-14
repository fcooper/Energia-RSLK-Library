/** @file */
#include "RSLK_Pins.h"
#include "QTRSensors.h"
#include "GP2Y0A21_Sensor.h"
#include "Encoder.h"
#include "Romi_Motor_Power.h"
#include "Bump_Switch.h"

#ifndef SimpleRSLK_h
#define SimpleRSLK_h

/**
 * @brief   Total number of sensors on QTR line sensor.
 */
#define LS_NUM_SENSORS   8     // number of sensors used

/**
 * @brief   Represent the left push button on the launchpad
 */
#define LP_LEFT_BTN  PUSH2

/**
 * @brief   Represent the right push button on the launchpad
 */
#define LP_RIGHT_BTN  PUSH1

/**
 * @brief   Total number of bump switches.
 */
#define TOTAL_BP_SW 6

/**
 * @brief   Can be used to reference the left motor in the below functions.
 */
#define LEFT_MOTOR 0

/**
 * @brief   Can be used to reference the right motor in the below functions.
 */
#define RIGHT_MOTOR 1

/**
 * @brief   Can be used to reference  both motors in the below functions.
 */
#define BOTH_MOTORS 2

/**
 * @brief   Can be used to reference setting the motor function to forward.
 */
#define MOTOR_DIR_FORWARD 0

/**
 * @brief   Can be used to reference setting the motor function to backward.
 */
#define MOTOR_DIR_BACKWARD 1

/**
 * @brief   Used to specify that the robot is running on a floor lighter than the line
 */
#define DARK_LINE 0

/**
 * @brief   Used to specify that the robot is running on a floor darker than the line
 */
#define LIGHT_LINE 1

/// \brief Performs a variety of initialization needed for the RSLK.
///
/// This function must be called before calling any other functions listed on this page.
///
void setupRSLK();

/// \brief Read distance sensor value.
///
/// \param[in] num of the distance sensor to read. Valid values are 0 - 2. Representing the 3 RSLK's sensors that can be
/// mounted on the RSLK (on top of the bump switch assembly).
/// - 0 for the left sensor.
/// - 1 for the center sensor.
/// - 5 for the right sensor.
/// \return A value from 0 - 4065.
/// - 0 represents object right infront of sensor
/// - ....
/// - 4065 represents no object detected
///
uint16_t readSharpDist(uint8_t num);

/// \brief Return bump switch status
///
/// \param[in] num bump switch number. Valid values are 0 - 5 representing the RSLK's 6 bump switches.
/// - 0 for left most switch.
/// - ...
/// - 5 for right most switch.
/// \return
/// - true if switch is pressed
/// - false if switch isn't pressed.
///
///
bool isBumpSwitchPressed(uint8_t num);

/// \brief Enable motor (take it out of sleep)
///
/// \param[in] motorNum that designates the the motor. Valid values are 0 - 2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors
///
/// Takes the motor out of sleep. The motor will not move unless you also call setMotorSpeed.
void enableMotor(uint8_t motorNum);

/// \brief Disable motor (puts the motor to sleep)
///
/// \param[in] motorNum that designates the the motor. Valid values are 0 - 2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors
///
/// Disabling the motor sets its speed to 0 and puts it to sleep.
void disableMotor(uint8_t motorNum);

/// \brief Pause motor (put the motor to sleep while saving its speed)
///
/// \param[in] motorNum that designates the the motor. Valid values are 0-2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors
///
/// Puts the motor to sleep while also preserving the previously set motor speed.
void pauseMotor(uint8_t motorNum);

/// \brief Resume motor (take the motor out of sleep and resumes its prior speed)
///
/// \param[in] motorNum that designates the the motor. Valid values are 0-2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors
///
/// Take the motor out of sleep and sets its speed to its prior value.
void resumeMotor(uint8_t motorNum);

/// \brief Set direction the motor will turn
///
/// \param[in] motorNum that designates the the motor. Valid values are 0-2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors

/// \param[in] direction that specifies the motor's direction @n
/// - 0 for forward
/// - 1 for for backward
///
/// Specifies the motor's direction. Can control an indivdual motor or both motors.
void setMotorDirection(uint8_t motorNum,uint8_t direction);

/// \brief Set the motor speed
///
/// \param[in] motorNum that designates the the motor. Valid values are 0-2. @n
/// - 0 for left motor
/// - 1 for right motor
/// - 2 for both motors
///
/// \param[in] speed that specifies the motor speed. Valid values are 0 - 100.
/// - 0 for 0% of motor speed.
/// - ...
/// - 100 for 100% of motor speed.
///
/// Sets the speed of the motor. A value of 0 means no movement. 100 will set the motor to its fastest
/// speed.
void setMotorSpeed(uint8_t motorNum, uint8_t speed);

/// \brief Read line sensor values
///
/// \param[out] sensor array that stores values read from line sensor. Must pass an array with 8 elements.
/// Array index 0 represents the left most sensor. Array index 7 represents the right most sensor. @n
/// Each index will contain a value from 0 - 2500.
/// - 0 max reflection (light line)
/// - ....
/// - 2500 no reflection (dark line)
///
///
/// Read and store sensor values in the passed in array.
void readLineSensor(uint16_t *sensor);

/// \brief Configure pin as a wait to release button
///
/// \param[in] btn the Launchpad pin number you want to use.
///
/// Configure pin to be used as a wait until pushed and released button. Useful if you want to halt the robot's
/// operation until the uses pushes and then releases the button.
void setupWaitBtn(uint8_t btn);

/// \brief Configure pin that is connected to an led
///
/// \param[in] ledPin the Launchpad pin number you want to use.
///
/// Configure pin to be used for as an led.
void setupLed(uint8_t ledPin);

/// \brief Busy wait until user pushes and releases button
///
/// \param[in] btnPin the Launchpad pin number you want to use.
/// \param[in] msg contains the string to output while waiting for btn to be pressed.
/// \param[in] ledPin represents the pin to toggle high and low while waiting for btn to be pressed.
///
/// Prevent additional code from executing until use has pushed and released
/// specified button.
void waitBtnPressed(uint8_t btnPin,String msg = "",int8_t ledPin = 0);

/// \brief Provide default values for the sensor's Min and Max arrays.
///
/// \param[out] sensorMin stores sensor's min values. Must pass an array with 8 elements.
///  All elements will by default be given a large value.
///
/// \param[out] sensorMax stores sensor's max values. Must pass an array with 8 elements.
///  All elements will by default be given a value of 0.
///
///  Initializes arrays to be used to store line sensor's min and max values.
void clearMinMax(uint16_t *sensorMin,uint16_t *sensorMax);

/// \brief Update line sensor's min and max values array based on current data.
///
/// \param[in] sensor is an array filled with line sensor values previously filled by readLineSensor.
///
/// \param[out] sensorMin stores sensor's min values.
///
/// \param[out] sensorMax stores sensor's max values.
///
///  Take the current line sensor values and update min and max values. This function along with the
///  min and max arrays are useful when performing calibration.
void setSensorMinMax(uint16_t *sensor,uint16_t *sensorMin,uint16_t *sensorMax);


/// \brief Update sensor's min and max values array based on current data.
///
/// \param[out] sensor is an array to be filled with line sensor values.
///
/// \param[out] calVal is an array that will be filled with the calibrated values based on the sensor,
/// sensorMin and sensorMax array. @n
/// Elements will be filled with values of 0 - 1000
/// - 0 means no line detected
/// - ...
/// - 1000 means line is detected right under sensor.
///
/// \param[in] sensorMin stores sensor's min values.
///
/// \param[in] sensorMax stores sensor's max values.
///
/// \param[in] mode determines if the line is dark or light.
/// - 0 is used when the line is darker than the floor
/// - 1 is used when the line is lighter than the floor.
///
/// Takes the current line sensor values and sets calVal to the calibrated values. Uses
/// sensorMin and sensorMax array along with mode to calibrate value. @n @n
///
/// Calibration:
/// - When the line is dark then calibration subtracts sensorMax values from the sensor value read.
/// - When the line is light then calibration subtracts sensorMin values from the sensor value read.
/// Then the value is subtracted from 1000 to provide a consistent scale.
void readCalLineSensor(uint16_t* sensor,
					   uint16_t* calVal,
					   uint16_t *sensorMin,
					   uint16_t *sensorMax,
					   uint8_t mode);

/// \brief Get line position
/// \param[in] calVal is an array that is filled with the line sensor calibrated values.
///
/// \param[in] mode determines if the line is dark or light.
/// - 0 is used when the line is darker than the floor
/// - 1 is used when the line is lighter than the floor.
///
/// \return value between 0 - 7000.
///  - 0 no line detected
///  - ...
///  - 1000 line is directly on the left most sensor
///  - ...
///  - 3500 line directly over two middle sensors.
///  - ...
///  - 7000 is under right most line sensor
///
///  Using calibrated line sensor value this function provides a numerical value indicating
///  where the robot is detecting the line. This function can be overridden.
uint32_t getLinePosition(uint16_t* calVal, uint8_t mode);
#endif