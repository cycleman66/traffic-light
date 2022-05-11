#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {

    private:
        byte pin;

    public:
        Potentiometer(){}           // default constructor - do not use
        Potentiometer(byte pin);    //constructor

        unsigned int getValue();    // will return value between 0 - 1023

};










#endif