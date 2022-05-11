#include "LedBlinker.h"

LedBlinker::LedBlinker(Led &led){
    this->led = led;
    lastTimeBlinked = millis();
    blinkDelay = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long blinkDelay){
    this->led = led;
    lastTimeBlinked = millis();
    this->blinkDelay = blinkDelay;
}


void LedBlinker::initLed(){
    // using the Led class init method
    led.init();
}

void LedBlinker::toggleLed(){
    led.toggle();
}

void LedBlinker::update(){
    unsigned long timeNow = millis();
    if (timeNow - lastTimeBlinked > blinkDelay){
        lastTimeBlinked = timeNow;
        toggleLed();
    }
}

// getters
unsigned long LedBlinker::getBlinkDelay(){
    return blinkDelay;
}

// setters
void LedBlinker::setBlinkDelay(unsigned long blinkDelay){
    this->blinkDelay = blinkDelay;
}