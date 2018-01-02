#include "LcdDisplay.h"
#include <Arduino.h>

/*************************************
 * name : RemoteContoller
 * input : LiquidCrystal_I2C(initalized)
 * return : none
 * set the _lcd to inputed LiquidCrystal_I2C
 * init the _Lcd(initalize, backlight on and
 * Cursor position to 0,0)
 ************************************/
LcdDisplay::LcdDisplay(){
}

void LcdDisplay::init(LiquidCrystal_I2C *lcd){
    _lcd = lcd;
    _lcd->init();
    _lcd->backlight();
    _lcd->setCursor(0,0);
    _lcd->print("Welcome RC Car!");
}

/*************************************
 * name : Print
 * input : String array(char[])
 * return : none
 * print string to display
 ************************************/
void LcdDisplay::print(const char message[]){
    _lcd->clear();
    _lcd->setCursor(0,0);
    _lcd->print("RC Car In Motion");
    _lcd->setCursor(0,1);
    _lcd->print(message);
}

void LcdDisplay::print(const int value){
    _lcd->clear();
    _lcd->setCursor(0,0);
    _lcd->print("RC Car In Motion");
    _lcd->setCursor(0,1);
    _lcd->print(value);
}

/*************************************
 * name : TurnOff
 * input : none
 * return : none
 * set the _lcd off
 ************************************/
void LcdDisplay::turnOff(void){
    _lcd->noBacklight();
}

/*************************************
 * name : TurnOn
 * input : none
 * return : none
 * set the _lcd on
 ************************************/
void LcdDisplay::turnOn(void){
    _lcd->backlight();
}