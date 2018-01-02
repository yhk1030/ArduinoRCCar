#ifndef REMOTECONTROLLER_H
#define REMOTECONTROLLER_H

#include <IRremote.h>
#include "LcdDisplay.h"

#define RC_TURN_RIGHT	0xFF22DD   //The remote control >> key
#define RC_TURN_LEFT	0xFF02FD   //The remote control << key
#define RC_GO_STOP  	0xFFC23D   //The remote control > | key
#define RC_SPEED_DOWN   0xFFE01F   //The remote control - key
#define RC_SPEED_UP  	0xFFA857   //The remote control + key

#define RC_SPEED_DEFAULT 25
#define RC_STOP 0
#define RC_MOVE 1
#define RC_TL	2
#define RC_TR 	3

class RemoteController {
public:
	RemoteController();
	void init(IRrecv *irRecvr, LcdDisplay *lcd); // receiver pin
	int getSpeed(void);
	int getCommand(void);
private:
	IRrecv *_irRecvr; //IR receiver
	LcdDisplay *_lcd;
	decode_results _results; //IR command
	int _pin;
	int _speed;
	int _command;  
};

#endif