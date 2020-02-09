#include <Arduino.h>
#include "hw_motors.h"

void set_pin(int pin, bool value)
{
    digitalWrite((uint8_t)pin, (uint8_t)value);
}

void init_write_pin(int pin)
{
    pinMode(pin, OUTPUT);
}


