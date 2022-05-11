#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <Arduino.h>

#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"

class TrafficLight {

    private:
        // set up h/w components as attributes
        Led redLed;
        Led yellowLed;
        Led greenLed;
        LedBlinker greenLedBlinker;
        PushButton button;
        Potentiometer potentiometer;

        byte ledsBrightness;    // 0 - 255 

        enum trafficLightState{
            STATE_RED,
            STATE_YELLOW,
            STATE_GREEN,
            STATE_BLINK_GREEN
        };

        int state;

        unsigned long yellowStateStartTime;
        unsigned long greenStateStartTime;
        unsigned long blinkGreenStateStartTime;

        const int yellowStateDuration = 3000;
        const int greenStateDuration = 2000;
        const int blinkGreenStateDuration = 5000;

        void updateLedsBrightness();

    public:
        // Constructors
        TrafficLight() {}   // dafault constructor - do not use
        TrafficLight(Led &redLed,
                    Led &yellowLed,
                    Led &greenLed,
                    LedBlinker &greenLedBlinker,
                    PushButton &button,
                    Potentiometer &potentiometer);

        // Methods
        void init();

        void red();
        void yellow();
        void green();
        void allLedsOff();

        void update();

};

#endif