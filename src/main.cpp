#include <Arduino.h>
#include "TrafficLight.h"

// Hardware setup - Pin definitions
#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9
#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A0

// Instantiate Objects from Classes
Potentiometer potentiometer(POTENTIOMETER_PIN);
Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);
PushButton button(BUTTON_PIN, true, true);
LedBlinker greenLedBlinker(greenLed, 100); // delay 100

TrafficLight trafficLight(redLed, yellowLed, greenLed, greenLedBlinker, button, potentiometer);

void setup() {
  trafficLight.init();
}

void loop() {
  trafficLight.update();
  delay(100);
}