#ifndef IRPROXIMITY_H
#define IRPROXIMITY_H

#define IP_LEFT_PIN     1
#define IP_CENTER_PIN   2
#define IP_RIGHT_PIN    3

class IRProximity{
    public:
    IRProximity();
    void init();
    bool checkLeft();
    bool checkCenter();
    bool checkRight();
    private:
};

#endif