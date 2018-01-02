#include "ServoContoller.h"
#include <Arduino.h>

/*************************************
 * name : ServoController
 * input : none
 * return : none
 * attach the Servo using pin number
 ************************************/
ServoController::ServoController(){
}

void ServoController::init(){
    _servo.attach(SC_PIN_NUM);
    setFront();
}

/*************************************
 * name : setFront
 * input : none
 * return : none
 * Set the servo Position to Front
 ************************************/
void ServoController::setFront(){
    _servo.write(SC_FRONT);   
}

/*************************************
 * name : setLeft
 * input : none
 * return : none
 * Set the servo Position to Left
 ************************************/
void ServoController::setLeft(){
    _servo.write(SC_LEFT);
}

/*************************************
 * name : setRight
 * input : none
 * return : none
 * Set the servo Position to Right
 ************************************/
void ServoController::setRight(){
    _servo.write(SC_RIGHT);
}

/*************************************
 * name : setPosition
 * input : position value
 * return : none
 * Set the servo Position to custom position
 ************************************/
void ServoController::setPosition(int position){
    _servo.write(position);
}