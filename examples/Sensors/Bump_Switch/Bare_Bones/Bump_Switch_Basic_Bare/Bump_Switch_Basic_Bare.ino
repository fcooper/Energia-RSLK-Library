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

	pinMode(BSW_PIN_1,INPUT_PULLUP);
	pinMode(BSW_PIN_2,INPUT_PULLUP);
	pinMode(BSW_PIN_3,INPUT_PULLUP);
	pinMode(BSW_PIN_4,INPUT_PULLUP);
	pinMode(BSW_PIN_5,INPUT_PULLUP);
	pinMode(BSW_PIN_6,INPUT_PULLUP);

	/* Right button on Launchpad */
	pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {

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

	// Drive the robot forward until it runs into something
	while(true) {
		if(digitalRead(BSW_PIN_1) == 0)
			break;

		if(digitalRead(BSW_PIN_2) == 0)
			break;      

		if(digitalRead(BSW_PIN_3) == 0)
			break;

		if(digitalRead(BSW_PIN_4) == 0)
			break;

		if(digitalRead(BSW_PIN_5) == 0)
			break;

		if(digitalRead(BSW_PIN_6) == 0)
			break;
	}

    left_motor.disableMotor();
    right_motor.disableMotor();	
}
