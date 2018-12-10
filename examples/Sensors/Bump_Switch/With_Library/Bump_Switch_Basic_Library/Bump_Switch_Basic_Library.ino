#include "Energia.h"

#include "Romi_Motor_Power.h"
#include <Bump_Switch.h>

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

Bump_Switch      bump_sw[6];
Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

void setup() {
	left_motor.begin(MOTOR_L_SLP_PIN,
					 MOTOR_L_DIR_PIN,
					 MOTOR_L_PWM_PIN);
	right_motor.begin(MOTOR_R_SLP_PIN,
					  MOTOR_R_DIR_PIN,
					  MOTOR_R_PWM_PIN);

	bump_sw[0].begin(BSW_PIN_1);
	bump_sw[1].begin(BSW_PIN_2);
	bump_sw[2].begin(BSW_PIN_3);
	bump_sw[3].begin(BSW_PIN_4);
	bump_sw[4].begin(BSW_PIN_5);
	bump_sw[5].begin(BSW_PIN_6);

	/* Right button on Launchpad */
	pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {
	bool hit_obstacle = false;

	/* Wait until button is pressed to start robot */
	while(digitalRead(PUSH2));

	// Enable both motors
	left_motor.enableMotor();
	right_motor.enableMotor();

	left_motor.directionForward();
	right_motor.directionForward();

	delay(2000);

	// Set motor to 30% of its max speed
	left_motor.setSpeed(30);
	right_motor.setSpeed(30);

	while(!hit_obstacle) {
		// Drive the robot forward until it runs into something
		for(int x = 0;x<6;x++)
		{
			if(bump_sw[x].read() == 0) {
				hit_obstacle = true;
				break;
			}
		}
	}

	left_motor.disableMotor();
	right_motor.disableMotor(); 
}
