#include "Energia.h"
#include <Bump_Switch.h>

/* Defines pin configuration of robot */
#include "Robot_Pins_v1.h"

Bump_Switch      bump_sw[6];

void setup() {
  Serial.begin(9600);

  bump_sw[0].begin(BSW_PIN_1);
  bump_sw[1].begin(BSW_PIN_2);
  bump_sw[2].begin(BSW_PIN_3);
  bump_sw[3].begin(BSW_PIN_4);
  bump_sw[4].begin(BSW_PIN_5);
  bump_sw[5].begin(BSW_PIN_6);

  Serial.println("Testing Bump Switch");
}

void loop() {
  for(int x = 0;x<6;x++)
  {
    if(bump_sw[x].read() == 0) {
      Serial.print("Bump switch ");
      Serial.print(x+1);
      Serial.println(" was pressed");
    }
  }
}
