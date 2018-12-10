#include "Romi_Motor_Power.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

/*
 * Robot Motor Library Example
 * 
 * created 5 Nov 2018
 * by Franklin S. Cooper Jr.
 */

void setup() {

  pinMode(MOTOR_L_SLP_PIN, OUTPUT);
  pinMode(MOTOR_L_DIR_PIN, OUTPUT);
  pinMode(MOTOR_L_PWM_PIN, OUTPUT);

  pinMode(MOTOR_R_SLP_PIN, OUTPUT);
  pinMode(MOTOR_R_DIR_PIN, OUTPUT);
  pinMode(MOTOR_R_PWM_PIN, OUTPUT);  

  /* Right button on Launchpad */
  pinMode(PUSH2, INPUT_PULLUP);
}

void loop() {

  /* Wait until button is pressed to start robot */
  while(digitalRead(PUSH2));

  while(true)
  {
    // Enable both motors
    digitalWrite(MOTOR_L_SLP_PIN, HIGH);
    digitalWrite(MOTOR_R_SLP_PIN, HIGH);

    // Set motor to 30% of its max speed
    analogWrite(MOTOR_L_PWM_PIN, 76);
    analogWrite(MOTOR_R_PWM_PIN, 76);

    // Make the robot go forward for 2 seconds    
    digitalWrite(MOTOR_L_DIR_PIN, LOW);
    digitalWrite(MOTOR_R_DIR_PIN, LOW);
    delay(2000);

    // Make the robot go backwards for 2 second
    digitalWrite(MOTOR_L_DIR_PIN, HIGH);
    digitalWrite(MOTOR_R_DIR_PIN, HIGH);  
    delay(2000);
  
    digitalWrite(MOTOR_L_DIR_PIN, LOW);
    digitalWrite(MOTOR_R_DIR_PIN, LOW);

    // Have the robot curve to the right for 1 second
    analogWrite(MOTOR_L_PWM_PIN, 102);
    delay(1000);
    analogWrite(MOTOR_L_PWM_PIN, 76);
    delay(2000);

    // Have the robot curve to the left for 1 second
    analogWrite(MOTOR_L_PWM_PIN, 102);
    delay(1000);
    analogWrite(MOTOR_L_PWM_PIN, 76);
    delay(2000);

    // Have the robot stop for 5 seconds
    digitalWrite(MOTOR_L_SLP_PIN, LOW);
    digitalWrite(MOTOR_R_SLP_PIN, LOW);
    delay(5000);
  }
}