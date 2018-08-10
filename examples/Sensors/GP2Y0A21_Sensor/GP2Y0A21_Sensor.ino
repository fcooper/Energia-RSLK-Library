#include "Energia.h"
#include "GP2Y0A21_Sensor.h"

GP2Y0A21_Sensor dst_sensor[3];

void setup() {
  Serial.begin(9600);

  dst_sensor[0].begin(59,INPUT_PULLDOWN);
  dst_sensor[1].begin(33,INPUT_PULLDOWN);
  dst_sensor[2].begin(42,INPUT_PULLDOWN);  

  Serial.println("Distance Sensor Demo");  
}

void loop() {
  Serial.print("Left Distance Sensor Value: ")
  Serial.println(dst_sensor[0].read());
  Serial.print("Center Distance Sensor Value: ")
  Serial.println(dst_sensor[1].read());
  Serial.print("Right Distance Sensor Value: ")
  Serial.println(dst_sensor[2].read());
}
