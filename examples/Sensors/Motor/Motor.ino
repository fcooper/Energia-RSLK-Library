#include "Energia.h"
#include "Romi_Motor_Power.h"

Romi_Motor_Power motor[2];

void setup() {
  Serial.begin(9600);

  motor[0].begin(24,25,11);
  motor[1].begin(26,27,35);
  
  motor[0].enableMotor();
  motor[1].enableMotor();


  Serial.println("Push left button to start"); 
  pinMode(74, INPUT_PULLUP);
  while(digitalRead(74) == 1);

  Serial.println("Start Motor Demo");  
}

void loop() {
  Serial.println("Turn both wheels forward");
  motor[0].directionForward();
  motor[1].directionForward();
  motor[0].setSpeed(30);
  motor[1].setSpeed(30);
  delay(4000);

  Serial.println("Turn both wheels backwards");  
  motor[0].directionBackward();
  motor[1].directionBackward();  
  delay(4000);

  Serial.println("Set left wheel faster");    
  motor[0].setSpeed(50);
  delay(4000);

  Serial.println("Set right wheel faster");   
  motor[0].setSpeed(30);  
  motor[1].setSpeed(50);  
  delay(4000);

  motor[1].setSpeed(30); 
  Serial.println("Pause motors");     
  motor[0].pauseMotor();
  motor[1].pauseMotor();
  delay(4000);

  Serial.println("Resume motors");  
  motor[0].resumeMotor();
  motor[1].resumeMotor();
  delay(4000);
}
