#include "Robot_QTR_Sensor.h"
#include "Romi_Motor_Power.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

/*
 * Robot QTR Sensor Example
 * 
 * This example will demonstrate the various features of the QTR Line Sensor library.
 * The following functions from the line sensor library will be used:
 * o qtr8_sensor_init - Used to initialize the qtr sensor class.
 * o lineLocation - Determines if the line is to the left, center or right of the robot
 * 	  o Can accept two paramters: WHITE_LINE and DARK_LINE
 * 
 * created 5 Nov 2018
 * by Franklin S. Cooper Jr.
 */

#define LS_TIMEOUT 2500

Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

void setup()
{
	/* Initialize both motors */
	left_motor.begin(MOTOR_L_SLP_PIN,
					 MOTOR_L_DIR_PIN,
					 MOTOR_L_PWM_PIN);
	right_motor.begin(MOTOR_R_SLP_PIN,
					  MOTOR_R_DIR_PIN,
					  MOTOR_R_PWM_PIN);
	
	/* Initialize line sensor */
	qtr8_sensor_init(LS_PIN_1,
					 LS_PIN_2,
					 LS_PIN_3,
					 LS_PIN_4,
					 LS_PIN_5,
					 LS_PIN_6,
					 LS_PIN_7,
					 LS_PIN_8,
					 LS_TIMEOUT,
					 LS_PIN_IR);

	/* Right button on Launchpad */
	pinMode(PUSH2, INPUT_PULLUP);
}

void loop()
{
	uint8_t     line_loc, default_motor_speed;
	uint16_t    left_motor_speed, right_motor_speed;

	/* Wait until button is pressed to start robot */

	while(digitalRead(PUSH2));

	default_motor_speed = 30;

	// Be default the motors are disabled so turn them on
	left_motor.enableMotor();
	right_motor.enableMotor();

	while(true) {
		line_loc = lineLocation(WHITE_LINE);

		if(line_loc == LINE_LEFT)
		{
			/* Line is to the right of the sensor.
			   Move robot to the right to center it to the line.
			*/
			left_motor_speed  = 55;
			right_motor_speed = 25;
		}
		else if (line_loc == LINE_RIGHT)
		{    
			/* Line is to the left of the sensor.
			   Move robot to the left to center it to the line.
			*/			
			right_motor_speed = 55;
			left_motor_speed  = 25;          
		}
		else {
			/* Line is center so move robot at the same time */
			right_motor_speed = default_motor_speed;
			left_motor_speed  = default_motor_speed;
		}

		/* Set pwm value of motors directly. Range is (stop) 0-255 (max speed)*/
		left_motor.setSpeedRaw(left_motor_speed);
		right_motor.setSpeedRaw(right_motor_speed);
	}
}