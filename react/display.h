#ifndef __DISPLAY__
#define __DISPLAY__

void initLCD();
void showWelcome();
void startGame();
void showNumber(int num);
void gameOver(int winner);
void showScore(int scoreP1, int scoreP2);
void clearLCD();
void scrollText();

#endif