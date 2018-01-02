#ifndef LCDDISPLAY_H
#define LCDDISPLAY_H

#include <LiquidCrystal_I2C.h>

class LcdDisplay {
public:
	LcdDisplay();
	void init(LiquidCrystal_I2C *lcd);
	void print(const char message[]);
	void turnOff(void);
	void turnOn(void);
	void print(const int value);
private:
	LiquidCrystal_I2C *_lcd;
};

#endif