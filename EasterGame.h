#ifndef _EASTER_GAME_H_
#define _EASTER_GAME_H_
#include "EscapeGame.h"

class EasterGame : public EscapeGame {
  public:
    EasterGame(PuzzleKeyPad* keypad, Adafruit_ST7789* tft, int door1Pin, int door2Pin);
    void Setup() override;
    void GameLoop() override;

  private:
    int door1Pin;
    int door2Pin;
    void drawMenu() override;
    void runPuzzle(int puzzleId) override;

    

    
};

#endif