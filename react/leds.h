#ifndef __LEDS__
#define __LEDS__

void initLeds();
void turnOnLed(int ledPin);
void turnOffLed(int ledPin);
void turnOffAllLeds();
void updateLedsFading();

#endif