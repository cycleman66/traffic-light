#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin){
    this->pin = pin;
}


unsigned int Potentiometer::getValue(){
    return analogRead(pin);
}
