#include "EasterGame.h"

EasterGame::EasterGame(PuzzleKeyPad* keypad, Adafruit_ST7789* tft, int door1Pin, int door2Pin) {
  this->keypad = keypad;
  this->tft = tft;
  this->door1Pin = door1Pin;
  this->door2Pin = door2Pin;
  this->Setup();
}

void EasterGame::Setup() {
  EscapeGame::Setup();
  this->numPuzzles = 6;
}

void EasterGame::GameLoop() {
  this->drawMenu();
  this->getPuzzle();
  delay(100);  
}

void EasterGame::drawMenu() {
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

void EasterGame::runPuzzle(int puzzleId) {
  //char codeBuffer[10];
  String code;
  switch(puzzleId) {
    // Color puzzle
    // Displays clue
    case 1:
      code = this->getColorCode(4, 10, 200);
      if (code != "") {
        if (code == "YBGR") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 220, 4);
          delay(500);
          // display clue
          char clue[] = "These puzzles\n"
            "are making my\n"
            "head sleepy\n"
            "I need something\n"
            "to perk me up\n"
            "\n\n\nPress any key\nto continue";
          this->tft->fillScreen(ST77XX_BLACK);
          this->drawText(clue, ST77XX_MAGENTA, 0, 0, 2);
          this->waitForKey(); // wait for key press
        } else {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 220, 4);
        }
      }
      break;
    case 2:
      code = this->getKeyPadCode(4, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "8772") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "My tummy is\n"
            "rumbling\n"
            "I need a snack\n"
            "to keep moving\n"
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
    case 3:
      code = this->getKeyPadCode(6, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "192158") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          this->openDoor(this->door2Pin);
        } else
        {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 0, 4);
        }
      }
      break;
    case 4:
      code = this->getKeyPadCode(4, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "4235") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "What am I\n"
            "to do with these\n"
            "damp clothes?"
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
      code = this->getKeyPadCode(5, 0, 200);
      if (code != "") {
        this->tft->fillScreen(ST77XX_BLACK);
        if (code == "42512") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 0, 4);
          delay(500);
          // display clue
          char clue[] = "I should\n"
            "really clean up\n"
            "these clothes\n"
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
      code = this->getColorCode(4, 10, 200);
      if (code != "") {
        if (code == "RYBG") {
          this->drawText("Code\nAccepted!", ST77XX_GREEN, 0, 220, 4);
          delay(500);
          this->openDoor(this->door1Pin);
        } else {
          this->drawText("Incorrect\nCode!", ST77XX_RED, 0, 220, 4);
        }
      }
      break;
  }
  delay(1000);
}
