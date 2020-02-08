#include <Arduino.h>

#define PINR1 4
#define PINR2 5
#define PINL1 6
#define PINL2 7
#define DEBUG

void setup()
{
	pinMode(PINR1, OUTPUT);
	pinMode(PINR2, OUTPUT);
	pinMode(PINL1, OUTPUT);
	pinMode(PINL2, OUTPUT);
	Serial.begin(115200);
	Serial.print("Hello, I'm Zakhar's legs");
}

void loop()
{
	// put your main code here, to run repeatedly:
}