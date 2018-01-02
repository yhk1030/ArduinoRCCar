#include "RemoteController.h"
#include <Arduino.h>

/*************************************
 * name : RemoteContoller
 * input : IRrecv(initalized)
 * return : none
 * set the irRecvr to inputed IRrecv
 * and speed, command value initialize
 ************************************/
RemoteController::RemoteController()
{
}

void RemoteController::init(IRrecv *irRecvr, LcdDisplay *lcd)
{
	_irRecvr = irRecvr;
	_speed = 0;
	_command = RC_STOP;
  _lcd = lcd;
  pinMode(3,INPUT);
  _irRecvr->enableIRIn();
}

/*************************************
 * name : getSpeed
 * input : void
 * return : speed of device
 ************************************/
int RemoteController::getSpeed(void)
{
	return _speed;
}

/*************************************
 * name : getCommand
 * input : void
 * return : command(flase : stop / true : movement)
 * recv the IR remotecontoller signal
 * input >| : toggle the stop and move
 * input +  : speed up to speed + RC_SPEED_DEFAULT
 * input -  : speed down to speed + RC_SPEED_DEFAULT
 * speed value can be minus value(move back)
 *************************************/
int RemoteController::getCommand(void)
{
	if (_irRecvr->decode(&_results))
  {
		switch(_results.value)
    {
    case RC_GO_STOP:   // > | key to toggle CAR movement
		  _command = !_command;
		 if(_command == RC_STOP){
        _lcd->print("STOP!");
		    _speed = 0; 
     }
		  else{
        _lcd->print("GO!");
        _speed = RC_SPEED_DEFAULT;	
      } 
      break;
    case RC_TURN_LEFT: // << key : turn left
      _command = RC_TL;
      _lcd->print("TURN LEFT");
      break;
    case RC_TURN_RIGHT: // >> key : turn right
      _command = RC_TR;
      _lcd->print("TURN RIGHT");
      break;
    case RC_SPEED_DOWN: // - key : speed down
      _lcd->print("SPEED DOWN");
      _speed -= RC_SPEED_DEFAULT;
      if(_speed == 0)
        _command = RC_STOP;
      else
        _command = RC_MOVE;
      break;
    case RC_SPEED_UP: // + key : speed down
      _lcd->print("SPEED UP");
      _speed += RC_SPEED_DEFAULT;
      if(_speed == 0)
        _command = RC_STOP;
      else
        _command = RC_MOVE;
      break;
    default:
        _lcd->print("UNKNOWN COMMAND");
        _command = RC_STOP;
        _speed = 0;
      break;
    }
    _irRecvr->resume(); // To receive the next value
	}  
	return _command;
}