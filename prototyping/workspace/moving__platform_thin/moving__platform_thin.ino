#include "Arduino.h"

// settings
//#define LOOP_FREQ_HZ 100
#define PINAA 18
#define PINAB 19
#define PINBA 20
#define PINBB 21
#define PIN_PWML 2
#define PIN_PWMR 3
#define DEBUG


// code

uint32_t pwml_counter = 0;
uint32_t pwmr_counter = 0;
uint32_t us_counter = 0;
#ifdef DEBUG
uint32_t big_loop_cnt = 0;
#endif

//#define LOOP_DELAY_MS (1000/LOOP_FREQ_HZ)
#define LOOP_DELAY_MS (1)
void left_incr()
{
	pwml_counter++;
}
void right_incr()
{
	pwmr_counter++;
}

void setup()
{
	pinMode(PINAA, OUTPUT);
	pinMode(PINAB, OUTPUT);
	pinMode(PINBA, OUTPUT);
	pinMode(PINBB, OUTPUT);
	pinMode(PIN_PWML, INPUT);
	pinMode(PIN_PWMR, INPUT);
	Serial.begin(115200);
	Serial.print("Hello, I'm Zakhar's legs");
	attachInterrupt(digitalPinToInterrupt(2), left_incr, LOW);
	attachInterrupt(digitalPinToInterrupt(3), right_incr, LOW);

}

// The loop function is called in an endless loop
void loop()
{

	delayMicroseconds(1);
	us_counter++;
	if (us_counter > (LOOP_DELAY_MS*100000))
	{
		us_counter = 0;
		Serial.print("LoopFreq!");
		Serial.print(pwml_counter);
		Serial.print(" ");
		Serial.print(pwmr_counter);
		Serial.print("\n");
#ifdef DEBUG

	Serial.print("Loop ");
	Serial.println(big_loop_cnt++);
#endif
	}
//Add your repeated code here
}
