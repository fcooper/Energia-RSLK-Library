/*
 * Energia Robot Library for Texas Instruments' Robot System Learning Kit (RSLK)
 * Line Following Example
 *
 * Summary:
 * This example has the TI Robotic System Learning Kit (TI RSLK) follow a line
 * using a basic line following algorithm. This example works on a dark floor with
 * a white line or a light floor with a dark line. The robot first needs to be calibrated
 * Then place the robot on the hit the left button again to begin the line following.
 *
 * How to run:
 * 1) Push left button on Launchpad to have the robot perform calibration.
 * 2) Robot will drive forwards and backwards by a predefined distance.
 * 3) Place the robot center on the line you want it to follow.
 * 4) Push left button again to have the robot begin to follow the line.
 *
 * Parts Info:
 * o Black eletrical tape or white electrical tape. Masking tape does not work well
 *   with IR sensors.
 *
 * Learn more about the classes, variables and functions used in this library by going to:
 * https://fcooper.github.io/Robot-Library/
 *
 * Learn more about the TI RSLK by going to http://www.ti.com/rslk
 *
 * created by Franklin Cooper Jr.
 *
 * This example code is in the public domain.
 */

#include "SimpleRSLK.h"

uint16_t sensorMaxVal[LS_NUM_SENSORS];
uint16_t sensorMinVal[LS_NUM_SENSORS];


void setup()
{
	Serial.begin(115200);

	setupRSLK();
	/* Left button on Launchpad */
	setupWaitBtn(LP_LEFT_BTN);
	/* Red led in rgb led */
	setupLed(RED_LED);

	clearMinMax(sensorMinVal,sensorMaxVal);

	String btnMsg = "Push left button on Launchpad to begin calibration.\n";
	btnMsg += "Make sure the robot is on the floor away from the line.\n";
	/* Wait until button is pressed to start robot */
	waitBtnPressed(LP_LEFT_BTN,btnMsg,RED_LED);

	delay(1000);

	Serial.println("Running calibration on floor");
	simpleCalibrate();

	btnMsg = "Push left button on Launchpad to begin line following.\n";
	btnMsg += "Make sure the robot is on the line.\n";
	/* Wait until button is pressed to start robot */
	waitBtnPressed(LP_LEFT_BTN,btnMsg,RED_LED);
	delay(1000);

	enableMotor(BOTH_MOTORS);
}

void simpleCalibrate() {
	int16_t count;
	uint16_t sensorVal[LS_NUM_SENSORS];

	setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD);
	setMotorSpeed(BOTH_MOTORS,20);
	enableMotor(BOTH_MOTORS);

	count = getEncoderLeftCnt();
	while(getEncoderLeftCnt() < count + 200) {
		readLineSensor(sensorVal);
		setSensorMinMax(sensorVal,sensorMinVal,sensorMaxVal);
	}

	pauseMotor(BOTH_MOTORS);
	delay(1000);
	setMotorDirection(BOTH_MOTORS,MOTOR_DIR_BACKWARD);

	resumeMotor(BOTH_MOTORS);
	enableMotor(BOTH_MOTORS);
	setMotorSpeed(BOTH_MOTORS,20);
	count = getEncoderLeftCnt();
	while(getEncoderLeftCnt() < count + 200) {
		readLineSensor(sensorVal);
		setSensorMinMax(sensorVal,sensorMinVal,sensorMaxVal);
	}

	pauseMotor(BOTH_MOTORS);
	setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD);
}


void loop()
{
	uint16_t  calVal[LS_NUM_SENSORS];
	uint16_t sensorVal[LS_NUM_SENSORS];

	readLineSensor(sensorVal);
	readCalLineSensor(sensorVal,
					  calVal,
					  sensorMinVal,
					  sensorMaxVal,
					  DARK_LINE);

	uint32_t linePos = getLinePosition(calVal,1);

	setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD);
	if(linePos <= 3000) {
		/* Spin the robot counter clock wise */
		setMotorSpeed(LEFT_MOTOR,10);
		setMotorSpeed(RIGHT_MOTOR,15);

	} else if(linePos >= 3500) {
		/* Spin the robot clock wise */
		setMotorSpeed(LEFT_MOTOR,15);
		setMotorSpeed(RIGHT_MOTOR,10);
	} else {
		/* Drive forward */
		setMotorSpeed(BOTH_MOTORS,10);
	}
}