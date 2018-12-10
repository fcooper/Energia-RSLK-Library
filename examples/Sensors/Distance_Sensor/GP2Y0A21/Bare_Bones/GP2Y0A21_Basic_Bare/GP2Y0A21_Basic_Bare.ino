#include "Energia.h"
#include "Romi_Motor_Power.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

void setup() {
	left_motor.begin(MOTOR_L_SLP_PIN,
					 MOTOR_L_DIR_PIN,
					 MOTOR_L_PWM_PIN);
	right_motor.begin(MOTOR_R_SLP_PIN,
					  MOTOR_R_DIR_PIN,
					  MOTOR_R_PWM_PIN);

	pinMode(DIST_L_PIN, INPUT_PULLDOWN);
	pinMode(DIST_C_PIN, INPUT_PULLDOWN);
	pinMode(DIST_R_PIN, INPUT_PULLDOWN);

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
		uint8_t temp = 0;

		temp = analogRead(DIST_L_PIN);
		if(temp > 200){
			hit_obstacle = true;
			break;
		}

		temp = analogRead(DIST_C_PIN);
		if(temp > 200){
			hit_obstacle = true;
			break;
		}

		temp = analogRead(DIST_R_PIN);
		if(temp > 200){
			hit_obstacle = true;
			break;
		}						
	}

	left_motor.disableMotor();
	right_motor.disableMotor(); 		
}
