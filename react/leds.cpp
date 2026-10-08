#include "leds.h"
#include "Arduino.h"
#include "config.h"

// Variabili interne al modulo utili per il fading non bloccante
static int fadeValue = 0;       // Luminosità attuale (da 0 a 255)
static int fadeAmount = 5;      // Di quanto cambia la luminosità a ogni step
static long lastFadeTime = 0;   // Memorizza l'istante dell'ultimo aggiornamento
#define FADE_INTERVAL 30        // Millisecondi tra un aggiornamento e l'altro (modificabile)

void initLeds() {
  pinMode(LED01_PIN, OUTPUT);
  pinMode(LED02_PIN, OUTPUT);
  pinMode(LED03_PIN, OUTPUT);
  pinMode(LED04_PIN, OUTPUT);
}

void turnOffAllLeds() {
  digitalWrite(LED01_PIN, LOW)
  digitalWrite(LED02_PIN, LOW)
  digitalWrite(LED03_PIN, LOW)
  digitalWrite(LED04_PIN, LOW)
}

void turnOnLed(int ledPin) {
  digitalWrite(ledPin, HIGH)
}

void turnOffLed(int ledPin) {
  digitalWrite(ledPin, LOW)
}

void updateLedsFading() {
  // TODO: Implementa il fading in controfase.
  // 
  // Suggerimenti per la logica:
  // 1. Calcola il tempo trascorso: (millis() - lastFadeTime)
  // 2. Se è maggiore di FADE_INTERVAL, aggiorna i LED:
  //    - analogWrite(L2_PIN, fadeValue);
  //    - analogWrite(L3_PIN, 255 - fadeValue); // Controfase!
  // 3. Aggiorna lastFadeTime con il millis() attuale
  // 4. Somma fadeAmount a fadeValue.
  // 5. Se fadeValue <= 0 oppure >= 255, inverti il segno di fadeAmount.
  unsigned long tempoTrascorso = millis() - lastFadeTime;
  if (tempoTrascorso > FADE_INTERVAL) {
    analogWrite(LED02_PIN, fadeValue);
    analogWrite(LED03_PIN, 255-fadeValue);
    lastFadeTime = millis();
  }
  fadeAmount += fadeValue;
  if (fadeValue <= 0 || fadeValue >= 255) {
    fadeAmount = -(fadeAmount)
  }

}