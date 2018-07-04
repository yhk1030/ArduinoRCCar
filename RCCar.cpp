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
    _irProxi.init();
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
void RCCar::forward(int numberOfMovement){
    _car.fwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500*numberOfMovement);
    _car.carStop();
    delay(500);
}

/*************************************
 * name : backward
 * input : none
 * return : none
 * backward during 1s
 ************************************/
void RCCar::backward(int numberOfMovement){
    _car.bwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500*numberOfMovement);
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
    delay(_turnDelay);
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
    delay(_turnDelay);
    _car.carStop();
    delay(250);
}

void RCCar::checkUnitDistance(){
    int initDistance;
    initDistance = _ultraSonic.checkDistanceFront();
    forward(1);
    _unitDistance = initDistance - _ultraSonic.checkDistanceFront();
    _lcdDisplay.print(_unitDistance);
    _turnDelay = 9000/_unitDistance;
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

int RCCar::senseObstacleDistance(int check[], int number){
    if(number < 1 || number > 160){
        return -1;
    }
    else if(number==1){
        check[0] = _ultraSonic.checkDistanceFront();
    }
    else{
        int interval = 160/(number-1);
        int degree = 10;
        for(int i=0; i<number; i++){
            check[i] = _ultraSonic.checkDistancePosition(degree+interval*i);
            delay(interval*5);
        }
        // set servo motor position to front
        _ultraSonic.checkDistanceFront();
    }
    delay(500);
    return 0;
}

boolean RCCar::isObstacle(int check, int distanceUnit){
    int unit = (check-RCCAR_SAFETY_BUFFER)/_unitDistance;
    return (unit > distanceUnit);
}

int RCCar::checkUnitDistance(int degree){
    int distance = _ultraSonic.checkDistancePosition(degree);
    int unitDistance = (distance-RCCAR_SAFETY_BUFFER)/_unitDistance;
    if(unitDistance>3)
        unitDistance = 3;
    return unitDistance;
}

int RCCar::nUnitDistance(int nUnit[], int numberOfDirection){
    if(numberOfDirection<1 || numberOfDirection>9){
        return -1;
    }

    int check[9];
    senseObstacleDistance(check,numberOfDirection);

    for(int i = 0; i<numberOfDirection; i++){
        nUnit[i]=(check[i]-RCCAR_SAFETY_BUFFER)/_unitDistance;
        _lcdDisplay.print(nUnit[i]);
    }

    return 0;
}

boolean RCCar::checkIRPLeft(){
    return _irProxi.checkLeft();
}

boolean RCCar::checkIRPCenter(){
    return _irProxi.checkCenter();
}

boolean RCCar::checkIRPRight(){
    return _irProxi.checkRight();
}
//no Delay...
void RCCar::nDForward(){
    _car.fwdStraight(RCCAR_DEFAULT_SPEED);
}

void RCCar::nDTurnRight(){
    _car.fwdRight(RCCAR_DEFAULT_SPEED);
}

void RCCar::nDTurnLeft(){
    _car.fwdLeft(RCCAR_DEFAULT_SPEED);
}