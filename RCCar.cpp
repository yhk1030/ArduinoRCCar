#include "RCCar.h"

LiquidCrystal_I2C lcd(0x3F,16,2);
IRrecv irrecv(RCCAR_IR_PIN);

RCCar::RCCar(){

}

void RCCar::init(){
    _lcdDisplay.init(&lcd);
    _remote.init(&irrecv,&_lcdDisplay);
    _car.init();
    _ultraSonic.init(&_servo);
    _carSpeed = 0;
    _distance = 0;
    _carCommand = RC_STOP;
}

boolean RCCar::start(){
    _carCommand = _remote.getCommand();
    _carSpeed = _remote.getSpeed();
    switch(_carCommand){
    case RC_TL:
        _car.turnLeft();
        break;
    case RC_TR:
        _car.turnRight();
        break;
    case RC_STOP:
        _car.carStop();
        break;
    case RC_MOVE:
        if(_carSpeed > 0)
        _car.fwdStraight(_carSpeed);
        else
        _car.bwdStraight(-_carSpeed);
        return true;
        break;
    default:
        break;
    }
    return false;
}

/*************************************
 * name : startSimple
 * input : none
 * return : true => move, false => stop
 ************************************/
boolean RCCar::startSimple(){
    _carCommand = _remote.getCommand();
    switch(_carCommand){
     case RC_STOP:
        return false;
        break;
    case RC_MOVE:
        return true;
        break;
    default:
        break;
    }
    return false;
}

/*************************************
 * name : forward
 * input : none
 * return : none
 * forward during 1s
 ************************************/
void RCCar::forward(){
    _car.fwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500);
    _car.carStop();
    delay(500);
}

/*************************************
 * name : backward
 * input : none
 * return : none
 * backward during 1s
 ************************************/
void RCCar::backward(){
    _car.bwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500);
    _car.carStop();
    delay(500);
}

/*************************************
 * name : turnLeft
 * input : none
 * return : none
 * Turn left during 1s
 ************************************/
void RCCar::turnLeft(){
    _car.turnLeft();
    delay(750);
    _car.carStop();
    delay(250);
}

/*************************************
 * name : turnRight
 * input : none
 * return : none
 * turn Right during 1s
 ************************************/
void RCCar::turnRight(){
    _car.turnRight();
    delay(750);
    _car.carStop();
    delay(250);
}

/*************************************
 * name : senseObstacle
 * input : for store 3 check value
 * return : none
 ************************************/
void RCCar::senseObstacle(boolean check[], int distance = RCCAR_COLLISION_DISTANCE){ 
    // 0 : left, 1 : front, 2 : right & true : block, false : not block
    check[0] = false;
    check[1] = false;
    check[2] = false;
    if(distance > _ultraSonic.checkDistanceLeft()){
        check[0] = true;
    }
    delay(250);
    if(distance > _ultraSonic.checkDistanceRight()){
        check[2] = true;
    }
    delay(250);
    if(distance > _ultraSonic.checkDistanceFront()){
        check[1] = true;
    }
    delay(500);
}

void RCCar::senseObstacleDistance(int check[], int number){
    int interval = 160/(number-1);
    int degree = 10;
    int currentDegree = 0;
    for(int i=0; i<number; i++){
        currentDegree = degree+interval*i;
        check[i] = _ultraSonic.checkDistancePosition(currentDegree);
        delay(100);
    }
    delay(500);
}

boolean RCCar::isObstacle(int check, int distanceUnit){
    int unit = (check-RCCAR_SAFETY_BUFFER)/RCCAR_MOVING_DISTANCE;
    return (unit > distanceUnit);
}

boolean RCCar::senseObstacleFront(int distance = RCCAR_COLLISION_DISTANCE){
    if(distance > _ultraSonic.checkDistanceFront())
        return true;
    return false;
}


int RCCar::checkUnitDistance(int degree){
    int distance = _ultraSonic.checkDistancePosition(degree);
    int unitDistance = (distance-RCCAR_SAFETY_BUFFER)/RCCAR_MOVING_DISTANCE;
    if(unitDistance>3)
        unitDistance = 3;
    return unitDistance;
}

void RCCar::nUnitDistance(int check[3]){
    int distance = _ultraSonic.checkDistancePosition(0);
    int unitDistance = (distance-RCCAR_SAFETY_BUFFER)/RCCAR_MOVING_DISTANCE;
    check[0] = unitDistance;
    _lcdDisplay.print((char)unitDistance);
    delay(1000);
    distance = _ultraSonic.checkDistancePosition(180);
    unitDistance = (distance-RCCAR_SAFETY_BUFFER)/RCCAR_MOVING_DISTANCE;
    check[2] = unitDistance;
    _lcdDisplay.print((char)unitDistance);
    delay(1000);
    distance = _ultraSonic.checkDistancePosition(90);
    unitDistance = (distance-RCCAR_SAFETY_BUFFER)/RCCAR_MOVING_DISTANCE;
    check[1] = unitDistance;
    _lcdDisplay.print((char)unitDistance);
    delay(1000);

}