#include "CarController.h"
#include <Arduino.h>

/*************************************
 * name : CarContoller
 * input : none
 * return : none
 * set the Pinmode(all output)
 ************************************/
CarController::CarController(){
}

void CarController::init(){
    pinMode(CC_RW_PIN1,OUTPUT);
    pinMode(CC_RW_PIN2,OUTPUT);
    pinMode(CC_RW_ENABLE,OUTPUT); // rw spd pin
    pinMode(CC_LW_PIN1,OUTPUT);
    pinMode(CC_LW_PIN2,OUTPUT);
    pinMode(CC_LW_ENABLE,OUTPUT); // lw spd pin
    carStop();
}

/*************************************
 * name : fwdStraight
 * input : speed of device(must positive number)
 * return : none
 * go straight and set speed to input value
 ************************************/
void CarController::fwdStraight(int speed){
    //int dSpeed = map(speed, 0, 1023, 0 , 255);
    //analogWrite(CC_RW_ENABLE,dSpeed);
    digitalWrite(CC_RW_ENABLE,HIGH);
    digitalWrite(CC_RW_PIN1,HIGH);
    digitalWrite(CC_RW_PIN2,LOW);
    digitalWrite(CC_LW_ENABLE,HIGH);
    digitalWrite(CC_LW_PIN1,HIGH);
    digitalWrite(CC_LW_PIN2,LOW);
}

/*************************************
 * name : fwdLeft
 * input : speed of device(must positive number)
 * return : none
 * fwd turn Left and set speed to input value
 ************************************/
void CarController::fwdLeft(int speed){
    //int dSpeed = map(speed, 0, 1023, 0 , 255);
    //analogWrite(CC_RW_ENABLE,dSpeed);
    digitalWrite(CC_RW_ENABLE,HIGH);
    digitalWrite(CC_RW_PIN1,HIGH);
    digitalWrite(CC_RW_PIN2,LOW);
    //analogWrite(CC_LW_ENABLE,0);
    digitalWrite(CC_LW_ENABLE,LOW);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,LOW);
}

/*************************************
 * name : fwdRight
 * input : speed of device(must positive number)
 * return : none
 * fwd turn Right and set speed to input value
 ************************************/
void CarController::fwdRight(int speed){
    //int dSpeed = map(speed, 0, 1023, 0 , 255);
    //analogWrite(CC_RW_ENABLE,0);
    digitalWrite(CC_RW_ENABLE,LOW);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,LOW);
    //analogWrite(CC_LW_ENABLE,dSpeed);
    digitalWrite(CC_LW_ENABLE,HIGH);
    digitalWrite(CC_LW_PIN1,HIGH);
    digitalWrite(CC_LW_PIN2,LOW);
}

/*************************************
 * name : turnLeft
 * input : none
 * return : none
 * set the Device turn 90 degree to Left
 ************************************/
void CarController::turnRight(void){
    //analogWrite(CC_RW_ENABLE,CC_DEFAULT_SPEED);
    digitalWrite(CC_RW_ENABLE,HIGH);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,HIGH);
//    analogWrite(CC_LW_ENABLE,CC_DEFAULT_SPEED);
    digitalWrite(CC_LW_ENABLE,HIGH);
    digitalWrite(CC_LW_PIN1,HIGH);
    digitalWrite(CC_LW_PIN2,LOW);
}

/*************************************
 * name : turnRight
 * input : none
 * return : none
 * set the Device turn 90 degree to Right
 ************************************/
void CarController::turnLeft(void){
    //analogWrite(CC_RW_ENABLE,CC_DEFAULT_SPEED);
    digitalWrite(CC_RW_ENABLE,HIGH);
    digitalWrite(CC_RW_PIN1,HIGH);
    digitalWrite(CC_RW_PIN2,LOW);
    //analogWrite(CC_LW_ENABLE,CC_DEFAULT_SPEED);
    digitalWrite(CC_LW_ENABLE,HIGH);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,HIGH);
}

/*************************************
 * name : bwdStraight
 * input : speed of device(must positive number)
 * return : none
 * go bwd Straight and set speed to input value
 ************************************/
void CarController::bwdStraight(int speed){
    //int dSpeed = map(speed, 0, 1023, 0 , 255);
    //analogWrite(CC_RW_ENABLE,dSpeed);
    digitalWrite(CC_RW_ENABLE,HIGH);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,HIGH);
    //analogWrite(CC_LW_ENABLE,dSpeed);
    digitalWrite(CC_LW_ENABLE,HIGH);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,HIGH);
}

/*************************************
 * name : bwdRight
 * input : speed of device(must positive number)
 * return : none
 * bwd turn Right and set speed to input value
 ************************************/
void CarController::bwdRight(int speed){
    int dSpeed = map(speed, 0, 1023, 0 , 255);
    analogWrite(CC_RW_ENABLE,0);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,LOW);
    analogWrite(CC_LW_ENABLE,dSpeed);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,HIGH);
}

/*************************************
 * name : bwdLeft
 * input : speed of device(must positive number)
 * return : none
 * bwd turn Left and set speed to input value
 ************************************/
void CarController::bwdLeft(int speed){
    int dSpeed = map(speed, 0, 1023, 0 , 255);
    analogWrite(CC_RW_ENABLE,dSpeed);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,HIGH);
    analogWrite(CC_LW_ENABLE,0);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,LOW);
}

/*************************************
 * name : carStop
 * input : none
 * return : none
 * Stop the device
 ************************************/
void CarController::carStop(void){
    analogWrite(CC_RW_ENABLE,0);
    digitalWrite(CC_RW_PIN1,LOW);
    digitalWrite(CC_RW_PIN2,LOW);
    analogWrite(CC_LW_ENABLE,0);
    digitalWrite(CC_LW_PIN1,LOW);
    digitalWrite(CC_LW_PIN2,LOW);
}
