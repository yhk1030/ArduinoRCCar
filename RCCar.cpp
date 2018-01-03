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

void RCCar::forward(){
    _car.fwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500);
}

void RCCar::backward(){
    _car.bwdStraight(RCCAR_DEFAULT_SPEED);
    delay(500);
}

void RCCar::turnLeft(){
    _car.turnLeft();
}

void RCCar::turnRight(){
    _car.turnRight();
}

void RCCar::senseObstacle(boolean check[]){ // 0 : left, 1 : front, 2 : right & true : block, false : not block
    check[0] = false;
    check[1] = false;
    check[2] = false;
    if(RCCAR_COLLISION_DISTANCE > _ultraSonic.checkDistanceLeft()){
        check[0] = true;
    }
    delay(200);
    if(RCCAR_COLLISION_DISTANCE > _ultraSonic.checkDistanceRight()){
        check[2] = true;
    }
    delay(200);
    if(RCCAR_COLLISION_DISTANCE > _ultraSonic.checkDistanceFront()){
        check[1] = true;
    }
    delay(200);
}

boolean RCCar::senseObstacleFront(){
    if(RCCAR_COLLISION_DISTANCE > _ultraSonic.checkDistanceFront())
        return true;
    return false;
}