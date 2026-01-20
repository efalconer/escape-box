#include "InheritanceGame.h"

InheritanceGame::InheritanceGame(PuzzleKeyPad* keypad, Adafruit_ST7789* tft, int door1Pin, int door2Pin) {
  this->keypad = keypad;
  this->tft = tft;
  this->door1Pin = door1Pin;
  this->door2Pin = door2Pin;
  this->Setup();
}

void InheritanceGame::Setup() {
  EscapeGame::Setup();
  this->numPuzzles = 6;
}

void InheritanceGame::GameLoop() {
  this->drawMenu();
  this->getPuzzle();
  delay(100);  
}

void InheritanceGame::drawMenu() {
  char menuText [] = "Select a\n"
    "puzzle \n"
    "to solve: \n\n"
    "1: Puzzle 1\n"
    "2: Puzzle 2\n"
    "3: Puzzle 3\n"
    "4: Puzzle 4\n"
    "5: Puzzle 5\n"
    "6: Puzzle 6\n";
  this->tft->fillScreen(ST77XX_BLACK);
  this->drawText(menuText, ST77XX_WHITE, 0, 0, 3);
}

void InheritanceGame::runPuzzle(int puzzleId) {
  //char codeBuffer[10];
  String code;
  switch(puzzleId) {
    // Color puzzle
    // Displays clue
    case 1:
      code = this->getKeyPadCode(4, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "2236") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "My penpal wrote\n"
            "me all summer.\n"
            "I kept the letters\n"
            "in a box in my room\n"
            "\n\n\n"
            "Press any key\nto continue";
          this->tft->fillScreen(ST77XX_BLACK);
          this->drawText(clue, ST77XX_MAGENTA, 0, 0, 2);
          this->waitForKey(); // wait for key press
        } else
        {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 0, 4);
        }
        break;
      }
    case 2:
      code = this->getColorCode(5, 10, 200);
      if (code != "") {
        if (code == "RGBYB") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 220, 4);
          delay(500);
          this->openDoor(this->door1Pin);
        } else {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 220, 4);
        }
      }
      break;
    
    case 3:
      code = this->getKeyPadCode(6, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "954871") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "My favorite book\n"
            "involved a little \n"
            "dog and red\n"
            "shoes.\n"
            "\n\n\n"
            "Press any key\nto continue";
          this->tft->fillScreen(ST77XX_BLACK);
          this->drawText(clue, ST77XX_MAGENTA, 0, 0, 2);
          this->waitForKey(); // wait for key press
        } else
        {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 0, 4);
        }
      }
      break;
    case 4:
      code = this->getColorCode(5, 10, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "BYRBG") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "I have so much\n"
            "work to do.\n"
            "How will I ever\n"
            "Finish on time?\n"
            "\n\n\n"
            "Press any key\nto continue";
          this->tft->fillScreen(ST77XX_BLACK);
          this->drawText(clue, ST77XX_MAGENTA, 0, 0, 2);
          this->waitForKey(); // wait for key press
        } else
        {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 0, 4);
        }
        break;
      }
    case 5:
      code = this->getColorCode(6, 10, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "BRBGYG") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "I'm in the mood\n"
            "to listen\n"
            "to some old\n"
            "music.\n"
            "\n\n\n"
            "Press any key\nto continue";
          this->tft->fillScreen(ST77XX_BLACK);
          this->drawText(clue, ST77XX_MAGENTA, 0, 0, 2);
          this->waitForKey(); // wait for key press
        } else
        {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 0, 4);
        }
        break;
      }
    case 6:
      code = this->getColorCode(6, 10, 200);
      if (code != "") {
        if (code == "RBRBYG") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 220, 4);
          delay(500);
          this->openDoor(this->door2Pin);
        } else {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 220, 4);
        }
      }
      break;
  }
  delay(1000);
}
