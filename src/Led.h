#ifndef LED_H   // header guards (define guards)
#define LED_H

#include <Arduino.h>

class Led
{
  private:
    byte pin;
    byte state;

  public:
    Led() {}        // default constructor, do not use
    Led(byte pin);   // constructor

    void init(); // two different ways to initialise the led
    void init(byte defaultState);

    void on();
    void on(byte brightness); // alternative method (overload)

    void off();
    // toggle LED depending on previous state
    void toggle();

    bool isPoweredOn();
};

#endif