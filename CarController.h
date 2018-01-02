#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

// Right Wheel Pins
#define CC_RW_PIN1 6  // Clock direction (fwd)
#define CC_RW_PIN2 7  // Anticlock direction (bwd)
#define CC_RW_ENABLE 5  // Wheel Speed
// Left Wheel Pins
#define CC_LW_PIN1 9  // Clock direction (fwd)
#define CC_LW_PIN2 8  // Anticlock direction (bwd)
#define CC_LW_ENABLE 10  // Wheel Speed

// pin1 HIGH, pin2 LOW : go fwd
// pin1 LOW, pin2 HIGH : go bwd
// pin1 LOW, pin2 LOW : stop

#define CC_DEFAULT_SPEED 100

class CarController 
{
  public:
    CarController();
    void init();
    void fwdStraight(int speed);
    void fwdLeft(int speed);
    void fwdRight(int speed);
    void turnLeft(void);
    void turnRight(void);
    void bwdStraight(int speed);
    void bwdRight(int speed);
    void bwdLeft(int speed);
    void carStop(void);
  private:
};

#endif