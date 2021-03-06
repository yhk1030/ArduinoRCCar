#include "UltraSonicSensor.h"
#include <Arduino.h>


/*************************************
 * name : UltraSonicSensor
 * input : ServoContoller(initalized)
 * return : none
 * set the pin mode
 * (Trig pin : output / Echo pin : input)
 * This Class must need the ServoController!
 ************************************/
UltraSonicSensor::UltraSonicSensor(){
}

void UltraSonicSensor::init(ServoController *servo){
    pinMode(US_TRIG_PIN, OUTPUT);
    pinMode(US_ECHO_PIN, INPUT);
    _servo = servo;
    _servo->init();
}

/*************************************
 * name : checkDistanceFront
 * input : none
 * return : Distance to Front side(cm)
 * Pulse timing / 58 = distance(cm)
 ************************************/
int UltraSonicSensor::checkDistanceFront(){
    _servo->setFront();
    delay(500);
    digitalWrite(US_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG_PIN, LOW);
    float Fdistance = pulseIn(US_ECHO_PIN, HIGH);
    Fdistance= Fdistance/58;
    if(Fdistance < 0.01)
        Fdistance = 400;
    return Fdistance;
}

/*************************************
 * name : checkDistanceLeft
 * input : none
 * return : Distance to Left side(cm)
 * Pulse timing / 58 = distance(cm)
 ************************************/
int UltraSonicSensor::checkDistanceLeft(){
    _servo->setLeft();
    delay(500);
    digitalWrite(US_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG_PIN, LOW);
    float Fdistance = pulseIn(US_ECHO_PIN, HIGH);
    Fdistance= Fdistance/58;
    if(Fdistance < 0.01)
        Fdistance = 400;
    return Fdistance;
}

/*************************************
 * name : checkDistanceRight
 * input : none
 * return : Distance to Right side(cm)
 * Pulse timing / 58 = distance(cm)
 ************************************/
int UltraSonicSensor::checkDistanceRight(){
    _servo->setRight();
    delay(500);
    digitalWrite(US_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG_PIN, LOW);
    float Fdistance = pulseIn(US_ECHO_PIN, HIGH);
    Fdistance= Fdistance/58;
    if(Fdistance < 0.01)
        Fdistance = 400;
    return Fdistance;
}

/*************************************
 * name : checkDistancePosition
 * input : Position(0~180)
 * return : Distance to input side(cm)
 * Pulse timing / 58 = distance(cm)
 ************************************/
int UltraSonicSensor::checkDistancePosition(int position){
    _servo->setPosition(position);
    delay(500);
    digitalWrite(US_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG_PIN, LOW);
    float Fdistance = pulseIn(US_ECHO_PIN, HIGH);
    Fdistance= Fdistance/58;
    if(Fdistance < 0.01)
        Fdistance = 400;
    return Fdistance;
}