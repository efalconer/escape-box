#ifndef _ESCAPE_GAME_H
#define _ESCAPE_GAME_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include "PuzzleKeyPad.h"

#define RED_BUTTON_PIN A2
#define GREEN_BUTTON_PIN A3
#define BLUE_BUTTON_PIN A4
#define YELLOW_BUTTON_PIN A5
enum ButtonColor {
  RED, GREEN, BLUE, YELLOW, NONE
};

class EscapeGame {

  protected:
    int numPuzzles = 0;
    PuzzleKeyPad* keypad;
    Adafruit_ST7789 * tft;
    void getPuzzle();
    virtual void drawMenu() = 0;
    virtual void runPuzzle(int puzzleId);
    String getKeyPadCode(int codeLength, uint16_t x = 0, uint16_t y = 0);
    String getColorCode(int codeLength, uint16_t x = 0, uint16_t y = 0);
    char waitForKey();
    ButtonColor waitForColorButton();

  public:
    virtual void Setup();
    virtual void GameLoop() = 0; // execute the main loop

    // helper functions
    void drawText(char *text, uint16_t color, uint16_t x = 0, uint16_t y = 0, uint8_t size=3);
    void drawCircle(uint16_t color, uint16_t x = 0, uint16_t y = 0, uint16_t radius = 10);
    void openDoor(int doorPin);
    ButtonColor getButtonColor();
  
  private:
    void waitForButtonRelease(int buttonPin);

    
};

#endif 