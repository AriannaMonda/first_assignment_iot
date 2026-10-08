#ifndef __CONFIG__
#define __CONFIG__

// #define __DEBUG__

#define NUM_BUTTONS 2
#define NUM_LED 4

#define POT_PIN 10
#define BUT01_PIN 2
#define BUT02_PIN 3
#define LED01_PIN 13
#define LED02_PIN 12
#define LED03_PIN 8
#define LED04_PIN 7


//metti costanti di tempo di gioco
/*Aggiungere un modulo Output (Consigliatissimo!):
Per mantenere il codice pulito come ha fatto il prof, 
non mettere i digitalWrite o le chiamate all'LCD direttamente 
dentro core.cpp. Crea un nuovo modulo (es. display.h e leds.h) 
che si occupa solo di far lampeggiare i led o scrivere su schermo.*/

#endif
