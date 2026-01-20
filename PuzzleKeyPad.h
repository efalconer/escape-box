#ifndef _PUZZLEKEYPAD_H
#define _PUZZLEKEYPAD_H
#include "Arduino.h"

class PuzzleKeyPad {
  private:
    constexpr static byte numRows = 4;
    constexpr static byte numCols = 4;
    byte *rowPins;
    byte *colPins;

    constexpr static char keyChars[numRows][numCols] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };
  public:
    PuzzleKeyPad(byte *rowPins, byte *colPins);

    char getKey();
    char processKey(byte row, byte col);
};


#endif