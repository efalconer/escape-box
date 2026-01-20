#ifndef _INHERITANCE_GAME_H_
#define _INHERITANCE_GAME_H_
#include "EscapeGame.h"

class InheritanceGame : public EscapeGame {
  public:
    InheritanceGame(PuzzleKeyPad* keypad, Adafruit_ST7789* tft, int door1Pin, int door2Pin);
    void Setup() override;
    void GameLoop() override;

  private:
    int door1Pin;
    int door2Pin;
    void drawMenu() override;
    void runPuzzle(int puzzleId) override;

    

    
};

#endif