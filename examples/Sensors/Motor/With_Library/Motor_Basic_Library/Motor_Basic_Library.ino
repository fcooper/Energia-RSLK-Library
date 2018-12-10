#include "Romi_Motor_Power.h"

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

  /* Right button on Launchpad */
  pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {

  /* Wait until button is pressed to start robot */
  while(digitalRead(PUSH2));

  while(true)
  {
    // Enable both motors
    left_motor.enableMotor();
    right_motor.enableMotor();

    // Set motor to 30% of its max speed
    left_motor.setSpeed(30);
    right_motor.setSpeed(30);

    // Make the robot go forward for 2 seconds    
    left_motor.directionForward();
    right_motor.directionForward();
    delay(2000);

    // Make the robot go backwards for 2 second
    left_motor.directionBackward();
    right_motor.directionBackward();  
    delay(2000);
  
    left_motor.directionForward();
    right_motor.directionForward();

    // Have the robot curve to the right for 1 second
    left_motor.setSpeed(40);
    delay(1000);
    left_motor.setSpeed(30);
    delay(2000);

    // Have the robot curve to the left for 1 second
    right_motor.setSpeed(40); 
    delay(1000);
    right_motor.setSpeed(30); 
    delay(2000);

    // Have the robot stop for 5 seconds
    left_motor.disableMotor();
    right_motor.disableMotor();
    delay(5000);
  }
}