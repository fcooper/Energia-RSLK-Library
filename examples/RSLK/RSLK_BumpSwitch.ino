#include <RSLKLib.h>

RSLKLib rslk;

void setup() {
	Serial.begin(9600);
	rslk.configure();
}

void loop() {
	for(int x = 0;x<6;x++)
	{
		if(rslk.readBumpSW(x) == 0) {
			Serial.print("Bump switch ");
			Serial.print(x);
			Serial.println(" was pressed");
		}
	}
}
