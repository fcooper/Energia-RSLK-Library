#include "Romi_Motor_Power.h"
#include "Encoder.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

/*
 * Robot Motor Library Example
 * 
 * This example will demonstrate the various features of the Motor library.
 * The following functions will be used:
 * o begin(sleep_pin,direction_pin_pwm_pin) - Used to initialize the motor class.
 * o enableMotor() - Turn on the motor (take it out of sleep)
 * o setSpeed(speed) - specify the speed of the motor using a value from 0 - 100
 * o directionForward() - make motor go forward
 * o directionBackward() - make motor go backwards
 * 
 * created 5 Nov 2018
 * by Franklin S. Cooper Jr.
 */
 
Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

void setup() {

  left_motor.begin(MOTOR_L_SLP_PIN,
                   MOTOR_L_DIR_PIN,
                   MOTOR_L_PWM_PIN);
  right_motor.begin(MOTOR_R_SLP_PIN,
                    MOTOR_R_DIR_PIN,
                    MOTOR_R_PWM_PIN);

 /* setupEncoder(ENCODER_ERA_PIN,
  			   ENCODER_ERB_PIN,
  			   ENCODER_ELA_PIN,
  			   ENCODER_ELB_PIN);
   */        
  /* Right button on Launchpad */
  pinMode(PUSH2, INPUT_PULLUP);
  Serial.begin(9600);
  delay(1000);

  Serial.println("frankie");
}

void loop() {

	int default_speed = 30;

	int left_wheel_speed = default_speed;
	int right_wheel_speed = default_speed;

	/* Wait until button is pressed to start robot */
	while(digitalRead(PUSH2));

	left_motor.directionForward();
	right_motor.directionForward();

	left_motor.enableMotor();
	right_motor.enableMotor();

	left_motor.setSpeed(30);
	right_motor.setSpeed(30);
	

  while(true)
  {
    int count = getEncoderLeftCnt() - getEncoderRightCnt();
    Serial.println(count);
    if(count == 0 || (count < 3 && count > -3))
      break;

    if(count > 0)
      right_wheel_speed += 2;
    else
      left_wheel_speed += 2;

    left_motor.setSpeedRaw(left_wheel_speed); 
    right_motor.setSpeedRaw(right_wheel_speed);
    resetLeftEncoderCnt();
    resetRightEncoderCnt();
    delay(2000);  
    
  }

	delay(4000);

}