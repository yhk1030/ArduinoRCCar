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
    boolean goStop = false;
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
        goStop = true;
        if(_carSpeed > 0)
        _car.fwdStraight(_carSpeed);
        else
        _car.bwdStraight(-_carSpeed);
        break;
    default:
        break;
    }
    return goStop;
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

void RCCar::senseObstacle(boolean [3]){ // 0 : left, 1 : front, 2 : right & true : block, false : not block
    sense[0] = (RCCAR_COLLISION_DISTANCE < _ultraSonic.checkDistanceLeft());
    sense[2] = (RCCAR_COLLISION_DISTANCE < _ultraSonic.checkDistanceRight());
    sense[1] = (RCCAR_COLLISION_DISTANCE < _ultraSonic.checkDistanceFront());
}