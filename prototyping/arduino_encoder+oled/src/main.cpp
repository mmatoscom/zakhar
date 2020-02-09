#include "RotSensor.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
int getChar (FILE *fp)
{
    while (!(Serial.available()));
    return (Serial.read());
}

int putChar (char c, FILE *fp)
{
    if (c == '\n') {
        putChar ((char) '\r', fp);
    }
    Serial.write (c);
    return 0;
}


#define OLED_RESET 4
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
Adafruit_SSD1306 display(-1);

void left_encoder_int();
void right_encoder_int();
// void PrintState(void)

int left_encoder_pin = 2;  // pulse output from the module
int right_encoder_pin = 3; // pulse output from the module



int RotSensor_Print(const char *msg) {
    return Serial.print(msg);
}

void RotSensor_Init(RotSensor *rs) {
    // attachInterrupt(digitalPinToInterrupt(rs->rs_pin), rs->RotSensor_InterruptionHandler, FALLING);
}

void left_encoder_int() {
    printf("none");
    // RotSensor::PlaceMeToYourIntHandler(&rs_left);
    }

// void RotSensor_InterruptionHandler();
//

uint8_t rc = 0;
// uint8_t lc=0;
bool r_direction = true;
uint32_t debounce_filter_ms = 10;

unsigned int rpm;     // rpm reading
volatile byte pulses; // number of pulses
unsigned long timeold;
// number of pulses per revolution
// based on your encoder disc
unsigned int pulsesperturn = 12;

void right_encoder_int() {
    static unsigned long old_r_intrtime = 0;
    unsigned long r_intrtime = millis();
    // If interrupts come faster than debounce_filter_ms, assume it's a bounce and ignore
    if (r_intrtime - old_r_intrtime > debounce_filter_ms) {
        r_direction ? rc++ : rc--;
        Serial.print("R");
        Serial.println(rc);
    }
    old_r_intrtime = r_intrtime;
}

void setup() {
    Serial.begin(9600);
    fdevopen (putChar, getChar);
    // encoders
    RotSensor rs_left(left_encoder_pin, "Left", millis, RotSensor_Print);
    pinMode(right_encoder_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(right_encoder_pin), right_encoder_int, FALLING);
    attachInterrupt(digitalPinToInterrupt(rs_left.rs_pin), left_encoder_int, FALLING);
    printf("Hello %s!", "there");
    // display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Hello!");
    display.display();
    delay(500);
    display.clearDisplay();
}

void loop() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Left: ");
    // display.println(rs_left.counter);
    display.print("Right: ");
    display.println(rc);
    display.display();
    // if (millis() - timeold >= 1000)
    // {
    //     //Don't process interrupts during calculations
    //     detachInterrupt(0);
    //     rpm = (int)(60 * 1000 / pulsesperturn) / (millis() - timeold) * pulses;
    //     timeold = millis();
    //     Serial.print("RPM = ");
    //     Serial.print(rpm, DEC);
    //     Serial.print("counter = ");
    //     Serial.println(pulses, DEC);
    //     pulses = 0;
    //     //Restart the interrupt processing
    //     attachInterrupt(0, counter, FALLING);
    // }
}
