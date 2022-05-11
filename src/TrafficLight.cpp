#include "TrafficLight.h"


TrafficLight::TrafficLight(
            Led &redLed,
            Led &yellowLed,
            Led &greenLed,
            LedBlinker &greenLedBlinker,
            PushButton &button,
            Potentiometer &potentiometer) {

    this->redLed = redLed;
    this->greenLed = greenLed;
    this->yellowLed = yellowLed;
    this->greenLedBlinker = greenLedBlinker;
    this->button = button;
    this->potentiometer = potentiometer;

}

// Methods
void TrafficLight::init() {
    redLed.init();
    yellowLed.init();
    greenLed.init();
    button.init();
    delay(100);

    updateLedsBrightness();
    state = STATE_RED;  // initialize state machine
    red();  // power on red LED when we initialize the traffic light
}

void TrafficLight::red() {
    redLed.on(ledsBrightness);
    yellowLed.off();
    greenLed.off();
}

void TrafficLight::yellow() {
    redLed.off();
    yellowLed.on(ledsBrightness);
    greenLed.off();
}

void TrafficLight::green() {
    redLed.off();
    yellowLed.off();
    greenLed.on(ledsBrightness);
}

void TrafficLight::allLedsOff() {
    redLed.off();
    yellowLed.off();
    greenLed.off();
}

void TrafficLight::updateLedsBrightness() {
    ledsBrightness = potentiometer.getValue() / 1023 * 255; // convert 0...1023 to 0...255 
}

void TrafficLight::update() {

    updateLedsBrightness();
    unsigned long timeNow = millis();

    switch (state)
    {
    case STATE_RED:{ 
        red();
        if (button.isPressed()){
            state = STATE_YELLOW;
            yellowStateStartTime = timeNow;
        }
        break;
    }
    case STATE_YELLOW:{ 
        yellow();
        if (timeNow - yellowStateStartTime > yellowStateDuration){
            state = STATE_GREEN;
            greenStateStartTime = timeNow;
        }
        break;
    }
    case STATE_GREEN:{ 
        green();
        if(timeNow - greenStateStartTime > greenStateDuration){
            state = STATE_BLINK_GREEN;
            blinkGreenStateStartTime = timeNow;
            allLedsOff();
        }
        break;
    }
    case STATE_BLINK_GREEN:{ 
        greenLedBlinker.update();   // note we run the update() method here
        if (timeNow - blinkGreenStateStartTime > blinkGreenStateDuration){
            state = STATE_RED;
        }
        break;
    }
    
    default:    // if error, go to Red state
        state = STATE_RED;
        break;
    }
}
