/*
 * Energia Robot Library for Texas Instruments' Robot System Learning Kit (RSLK)
 * Bare Bump Switch Example
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

#include "Romi_Motor_Power.h"
/* Defines pin configuration of robot */
#include "RSLK_Pins.h"
#include "SimpleRSLK.h"

Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;
int motorSpeed = 10;

void setup() {
	Serial.begin(115200);

	left_motor.begin(MOTOR_L_SLP_PIN,
					 MOTOR_L_DIR_PIN,
					 MOTOR_L_PWM_PIN);

	right_motor.begin(MOTOR_R_SLP_PIN,
					  MOTOR_R_DIR_PIN,
					  MOTOR_R_PWM_PIN);

	pinMode(BP_SW_PIN_0,INPUT_PULLUP);
	pinMode(BP_SW_PIN_1,INPUT_PULLUP);
	pinMode(BP_SW_PIN_2,INPUT_PULLUP);
	pinMode(BP_SW_PIN_3,INPUT_PULLUP);
	pinMode(BP_SW_PIN_4,INPUT_PULLUP);
	pinMode(BP_SW_PIN_5,INPUT_PULLUP);

	/* Left button on Launchpad */
	pinMode(LP_LEFT_BTN, INPUT_PULLUP);
	/* Red led in rgb led */
	pinMode(RED_LED,OUTPUT);
}

void loop() {
	String btnMsg = "Push left button on Launchpad to start demo.\n";
	/* Wait until button is pressed to start robot */
	waitBtnPressed(LP_LEFT_BTN,btnMsg,RED_LED);

	/* Enable both motors */
	left_motor.enableMotor();
	right_motor.enableMotor();

	/* Set both motors direction to forward */
	left_motor.directionForward();
	right_motor.directionForward();

	delay(2000);

	/* Set motors speed to 10% of max value */
	left_motor.setSpeed(10);
	right_motor.setSpeed(10);

	// Drive the robot forward until it runs into something
	while(true) {
		if(digitalRead(BP_SW_PIN_0) == 0)
			break;

		if(digitalRead(BP_SW_PIN_1) == 0)
			break;

		if(digitalRead(BP_SW_PIN_2) == 0)
			break;

		if(digitalRead(BP_SW_PIN_3) == 0)
			break;

		if(digitalRead(BP_SW_PIN_4) == 0)
			break;

		if(digitalRead(BP_SW_PIN_5) == 0)
			break;
	}

	Serial.println("Collision detected");
	left_motor.disableMotor();
	right_motor.disableMotor();
}