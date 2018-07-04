#include "IRProximity.h"
#include <Arduino.h>

IRProximity::IRProximity(){

}

void IRProximity::init(){
    pinMode(IP_LEFT_PIN,INPUT);
    pinMode(IP_CENTER_PIN,INPUT);
    pinMode(IP_RIGHT_PIN,INPUT);
}

// LOW = white, HIGH = black
bool IRProximity::checkLeft(){
    if(digitalRead(IP_LEFT_PIN)==LOW)
        return false;
    else
        return true;
}

bool IRProximity::checkCenter(){
    if(digitalRead(IP_CENTER_PIN)==LOW)
        return false;
    else
        return true;
}

bool IRProximity::checkRight(){
    if(digitalRead(IP_RIGHT_PIN)==LOW)
        return false;
    else
        return true;
}