#include "Romi_Motor_Power.h"
#include "Encoder.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

/*
 * Robot Encoder Library Example
 * 
 * Summary:
 * This example will demonstrate the various features of the Encoder library.
 * The robot will go forward by a specified amount in inches. A robot natually
 * will not go straight due to factors such as wheel whooble or differences in
 * behavior of the left and right motor. Incorporting PID with the encoder count
 * could be used to improve this but in reality a compass should be used to help
 * the robot know exactly when its divating and how to correct itself.
 *
 * Parts Info:
 * o Romi Encoder Pair Kit, 12 CPR, 3.5-18V - https://www.pololu.com/product/3542
 * o Pololu Wheel 70×8mm Pair - https://www.pololu.com/product/1429
 *
 * The following Encoder specific functions will be used:
 * o setupEncoder - Used to initialize the encoder pins and enable encoder pulse counting
 * o countForDistance - Determine how many pulses required to travel a certain distance (in inches)
 * o resetLeftEncoderCnt - Reset encoder count to zero for the left wheel
 * o resetRightEncoderCnt - Reset encoder count to zero for the right wheel
 * o getEncoderRightCnt - Get the current encoder count for the right wheel
 *
 * created 5 Nov 2018
 * by Franklin S. Cooper Jr.
 */
 
Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

/* Diameter of Romi wheels in inches */
#define WHEEL_DIAMETER 2.7559055

/* Number of encoder (rising) pulses every time the wheel turns completely */
#define CNT_PER_REVOLUTION 360

/* How far in inches for the robot to travel */
#define INCHES_TO_TRAVEL 24

void setup() {
	left_motor.begin(MOTOR_L_SLP_PIN,
				   MOTOR_L_DIR_PIN,
				   MOTOR_L_PWM_PIN);
	right_motor.begin(MOTOR_R_SLP_PIN,
					MOTOR_R_DIR_PIN,
					MOTOR_R_PWM_PIN);

	/* Enable Encoders */
	setupEncoder(ENCODER_ELA_PIN,
		   		 ENCODER_ELB_PIN,
				 ENCODER_ERA_PIN,
				 ENCODER_ERB_PIN);

	/* Right button on Launchpad */
	pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {
	uint16_t slow_down  = 0; // How many encoder pulses before starting to slow down
	uint16_t total_count = 0; // Total amount of encoder pulses received
	uint8_t default_speed = 100; // Default raw pwm speed for motor.

	uint8_t left_wheel_speed = default_speed;
	uint8_t right_wheel_speed = default_speed;

	/* Amount of encoder pulses needed to achieve distance */
	uint16_t x = countForDistance(WHEEL_DIAMETER, CNT_PER_REVOLUTION, INCHES_TO_TRAVEL);

	/* There are no brakes on this motor. Therefore, momentum will cause the
	 * motor to rotate more then necessary. To combat this reduce the speed
	 * of the wheels significantly once its close to its destination.
	 */
	if(left_wheel_speed > 50)
			slow_down = x-CNT_PER_REVOLUTION*.20;
	else
		slow_down = x;

	/* Wait until button is pressed to start robot */
	while(digitalRead(PUSH2));

	delay(2000);

	/* Set the encoder pulses count back to zero */
	resetLeftEncoderCnt();
	resetRightEncoderCnt();

	/* Cause the robot to drive forward */
	left_motor.directionForward();
	right_motor.directionForward();

	/* "Turn on" the motor */
	left_motor.enableMotor();
	right_motor.enableMotor();

	/* Set motor speed */
	left_motor.setSpeedRaw(left_wheel_speed);
	right_motor.setSpeedRaw(right_wheel_speed);

	/* Drive motor until it has received x pulses */
	while(total_count < x)
	{
		total_count = getEncoderRightCnt();

		/* Getting close to the end. Slow down */
		if(total_count >= slow_down) {
			left_motor.setSpeedRaw(10);
			right_motor.setSpeedRaw(10);
		}
	}

	/* Halt motors */
	left_motor.disableMotor();
	right_motor.disableMotor();
}
