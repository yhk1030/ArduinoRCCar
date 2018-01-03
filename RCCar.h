#ifndef RCCAR_H
#define RCCAR_H

#include "ServoContoller.h"
#include "LcdDisplay.h"
#include "RemoteController.h"
#include "CarController.h"
#include "UltraSonicSensor.h"
#include <Wire.h> 

#define RCCAR_IR_PIN 3
#define RCCAR_COLLISION_DISTANCE 10
#define RCCAR_DEFAULT_SPEED 100


class RCCar {
public:
	RCCar();
    void init();
    void start();
    void senseObstacle(boolean check[3]);
    void forward();
    void turnRight();
    void turnLeft();
    void backward();

private:
    ServoController _servo;
    LcdDisplay _lcdDisplay;
    RemoteController _remote;
    CarController _car;
    UltraSonicSensor _ultraSonic;
    int _carCommand;
    int _carSpeed;
    int _distance;
};

#endif