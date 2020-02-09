#include <Arduino.h>
#include "hw_motors.h"

#define PINR1 9
#define PINR2 10
#define PINL1 11
#define PINL2 12
#define DEBUG


Motors_dc2platform wheels(PINR1, PINR2, PINL1, PINL2);

void test(void) {
    // wheels.MoveBackward();
    // delay(300);
    //     wheels.MoveRight();
    // delay(400);
        wheels.MoveBackward();
    delay(2000);
    wheels.Stop();
    delay(300);


    wheels.MoveForward();
    delay(1000);
    wheels.Stop();
    delay(300);
}

void setup() {
    test();
}

void loop() {
}