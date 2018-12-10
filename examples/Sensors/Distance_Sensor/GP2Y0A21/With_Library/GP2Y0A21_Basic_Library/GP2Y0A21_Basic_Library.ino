#include "Energia.h"
#include "Romi_Motor_Power.h"

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"
#include "GP2Y0A21_Sensor.h"

Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

GP2Y0A21_Sensor dst_sensor[3];

void setup() {
  left_motor.begin(MOTOR_L_SLP_PIN,
           MOTOR_L_DIR_PIN,
           MOTOR_L_PWM_PIN);
  right_motor.begin(MOTOR_R_SLP_PIN,
            MOTOR_R_DIR_PIN,
            MOTOR_R_PWM_PIN);

  dst_sensor[0].begin(DIST_L_PIN);
  dst_sensor[1].begin(DIST_C_PIN);
  dst_sensor[2].begin(DIST_R_PIN); 

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
    // Drive the robot forward until it is about to run into something.
    for(int x = 0;x<3;x++) {
      if(dst_sensor[x].read() > 200){
        hit_obstacle = true;
        break;
      }    
    }
  }

  left_motor.disableMotor();
  right_motor.disableMotor();     
}
