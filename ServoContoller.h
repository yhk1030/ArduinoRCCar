#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include <Servo.h>

#define SC_PIN_NUM 4
#define SC_FRONT 90
#define SC_RIGHT 170
#define SC_LEFT 10
#define SC_DELAY_TIME 250
// position 0 is left side and 180 is right side.


class ServoController {
public:
	ServoController();
    void init();
	void setFront();
    void setLeft();
    void setRight();
    void setPosition(int);
private:
    Servo _servo;
};

#endif