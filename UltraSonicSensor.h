#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "ServoContoller.h"

#define US_TRIG_PIN 12
#define US_ECHO_PIN 13

class UltraSonicSensor {
public:
	UltraSonicSensor();
    void init(ServoController *servo);
	int checkDistanceFront();
    int checkDistanceLeft();
    int checkDistanceRight();
private:
    ServoController *_servo;
};

#endif