#include "display.h"
#include "Arduino.h"
#include "config.h"
#include <time.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);
const char messaggio[] = "Welcome to the React! Game. Press Buttons to Start";
int partenza = 0;
unsigned long ultimoPasso = 0;

void initLCD() {
  lcd.init();
  lcd.backlight();
}

void showWelcome() {
  if (millis() - ultimoPasso >= 300) {
    ultimoPasso = millis();

    int lunghezza = strlen(messaggio);
    lcd.setCursor(0, 0);

    for (int i = 0; i < 20; i++) {
      lcd.print(messaggio[(partenza + i) % lunghezza]);
    }

    partenza = (partenza + 1) % lunghezza;
  }
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
  clearLCD();
  lcd.setCursor(0, 0);
  if (winner == 1) {
    lcd.print("Game Over - The winner is P1");
  } else if (winner == 2) {
    lcd.print("Game Over - The winner is P2");
  } else {
    lcd.print("Game Over - Tie");
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