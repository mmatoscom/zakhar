#include <Arduino.h>

void setup() {
	Serial.begin(115200);
	Serial.print("Hello\n");
//	rot_sensors0.init();
}

void loop() {
	Serial.print("Loop\n");
}
