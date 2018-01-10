#ifndef RCCAR_H
#define RCCAR_H

#include "ServoContoller.h"
#include "LcdDisplay.h"
#include "RemoteController.h"
#include "CarController.h"
#include "UltraSonicSensor.h"
#include <Wire.h> 

#define RCCAR_IR_PIN 3
#define RCCAR_COLLISION_DISTANCE 10 // 충돌감지 거리
#define RCCAR_DEFAULT_SPEED 100
#define RCCAR_MOVING_DISTANCE 11
#define RCCAR_SAFETY_BUFFER 3


class RCCar {
public:
	RCCar();
    void init();
    boolean start();
    boolean startSimple();
    void senseObstacle(boolean check[],int distance);
    void senseObstacleDistance(int check[], int number);
    boolean isObstacle(int check, int destanceUnit);
    void forward();
    void turnRight();
    void turnLeft();
    void backward();
    boolean senseObstacleFront(int distance);
    int checkUnitDistance(int degree);

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