/*
 * Energia Robot Library for Texas Instruments' Robot System Learning Kit (RSLK)
 * Simplified Bump Switch Example
 *
 * Summary:
 * This example has the TI Robotic System Learning Kit (TI RSLK) driving forward
 * until it hits an object (ie a bump switch is triggered) then it stops.
 *
 * How to run:
 * 1) Push left button on Launchpad to start the demo
 * 2) Robot will drive forward until the bump switches are triggered
 * 3) Once switches are triggered the robot will halt.
 * 4) Push left button again to start demo
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

int motorSpeed = 10;

void setup() {
	Serial.begin(115200);
	setupRSLK();
	/* Left button on Launchpad */
	setupWaitBtn(LP_LEFT_BTN);
	/* Red led in rgb led */
	setupLed(RED_LED);
}

void loop() {
	bool hitObstacle = false;

	String btnMsg = "Push left button on Launchpad to start demo.\n";
	/* Wait until button is pressed to start robot */
	waitBtnPressed(LP_LEFT_BTN,btnMsg,RED_LED);

	/* Wait two seconds before starting */
	delay(2000);

	/* Enable both motors, set their direction and provide a default speed */
	enableMotor(BOTH_MOTORS);
	setMotorDirection(BOTH_MOTORS,MOTOR_DIR_FORWARD);
	setMotorSpeed(BOTH_MOTORS,motorSpeed);

	/* Keep checking if the robot has hit an object */
	while(!hitObstacle) {
		/* Loop through all bump switchees to see if it has been pressed */
		for(int x = 0;x<TOTAL_BP_SW;x++)
		{
			/* Check if bump switch was pressed */
			if(isBumpSwitchPressed(x) == true) {
				hitObstacle = true;
				break;
			}
		}
	}

	Serial.println("Collision detected");
	disableMotor(BOTH_MOTORS);
}