#ifndef LED_BLINKER_H   // header guards (define guards)
#define LED_BLINKER_H

#include <Arduino.h>
#include "Led.h"

class LedBlinker {

    private:
        // this class contains Led class
        Led led;
        unsigned long lastTimeBlinked;
        unsigned long blinkDelay;

        void toggleLed();


    public:
        // default constructor - do not use
        LedBlinker(){}
        // constructor - we pass the reference to the led object here
        LedBlinker(Led &led);
        // constructor - with blinkDelay parameter
        LedBlinker(Led &led, unsigned long blinkDelay);

        // allows led to be initialised from ledBlinker
        void initLed();

        void update();

        // getters
        unsigned long getBlinkDelay();

        // setters
        void setBlinkDelay(unsigned long blinkDelay);

};



#endif