#ifndef RCCAR_H
#define RCCAR_H

#include "ServoContoller.h"
#include "LcdDisplay.h"
#include "RemoteController.h"
#include "CarController.h"
#include "UltraSonicSensor.h"
#include "IRProximity.h"
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
    void checkUnitDistance();
    boolean start();
    boolean startSimple();
    void senseObstacle(boolean check[],int distance);
    int senseObstacleDistance(int check[], int number);
    boolean isObstacle(int check, int destanceUnit);
    void forward(int numberOfMovement);
    void turnRight();
    void turnLeft();
    void nDForward();
    void nDTurnRight();
    void nDTurnLeft();
    void backward(int numberOfMovement);
    int checkUnitDistance(int degree);
    int nUnitDistance(int nUnit[], int numberOfDirection);
    boolean checkIRPLeft();
    boolean checkIRPCenter();
    boolean checkIRPRight();
private:
    ServoController _servo;
    LcdDisplay _lcdDisplay;
    RemoteController _remote;
    CarController _car;
    UltraSonicSensor _ultraSonic;
    IRProximity _irProxi;
    int _unitDistance;
    int _turnDelay;
    int _carCommand;
    int _carSpeed;
    int _distance;
};

#endif