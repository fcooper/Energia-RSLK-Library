#include "Energia.h"
#include <Bump_Switch.h>


Bump_Switch      bump_sw[6];

void setup() {
  Serial.begin(9600);

  bump_sw[0].begin(58, INPUT_PULLUP);
  bump_sw[1].begin(57, INPUT_PULLUP);
  bump_sw[2].begin(41, INPUT_PULLUP);
  bump_sw[3].begin(43, INPUT_PULLUP);
  bump_sw[4].begin(60, INPUT_PULLUP);
  bump_sw[5].begin(51, INPUT_PULLUP);

  Serial.println("Testing Bump Switch");
}

void loop() {
  for(int x = 0;x<6;x++)
  {
    // Push one or more bump switch to see an output.

    // When switch is closed the switch goes to ground.
    // By default the pins are se
    if(bump_sw[x].read() == 0) {
      Serial.print("Bump switch ");
      Serial.print(x);
      Serial.println(" was pressed");
    }
  }
}
