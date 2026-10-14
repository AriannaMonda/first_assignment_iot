#include "display.h"
#include "Arduino.h"
#include "config.h"
#include <time.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);
const char startMessage[] = "Welcome to the React! Game. Press Buttons to Start. ";
const char finalMessage1[] = "Game Over - The winner is P1. ";
const char finalMessage2[] = "Game Over - The winner is P2. ";
const char finalMessageTie[] = "Game Over - Tie. ";
int p = 0;
unsigned long ultimoPasso = 0;

void initLCD() {
  lcd.init();
  lcd.backlight();
}

void scrollText(const char* message) {
  if (millis() - ultimoPasso >= 300) {
    ultimoPasso = millis();

    int len = strlen(message);
    lcd.setCursor(0, 0);

    for (int i = 0; i < 20; i++) {
      lcd.print(message[(p + i) % len]);
    }

    p = (p + 1) % len;
  }
}

void showWelcome() {
  scrollText(startMessage);
}

void startGame() {
  clearLCD();
  lcd.setCursor(0, 0);
  lcd.print("Go!");
}

void showNumber(int num) {
  clearLCD();
  lcd.setCursor(0, 0);
  lcd.print(num);
}

void gameOver(int winner) {
  if (winner == 1) {
    scrollText(finalMessage1);
  } else if (winner == 2) {
    scrollText(finalMessage2);
  } else {
    scrollText(finalMessageTie);
  }
}

void showScore(int scoreP1, int scoreP2) {
  clearLCD();
  lcd.setCursor(0, 0);
  lcd.print(scoreP1);
  lcd.setCursor(18, 0);
  lcd.print(scoreP2);
}

void clearLCD() {
  lcd.clear();
}