#include "EscapeGame.h"

void EscapeGame::Setup() {
  pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
  pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON_PIN, INPUT_PULLUP);
}

void EscapeGame::drawText(char *text, uint16_t color, uint16_t x, uint16_t y, uint8_t size) {
  this->tft->setCursor(x, y);
  this->tft->setTextColor(color);
  this->tft->setTextWrap(true);
  this->tft->setTextSize(size);
  this->tft->print(text);
}

void EscapeGame::drawCircle(uint16_t color, uint16_t x, uint16_t y, uint16_t radius) {
  this->tft->fillCircle(x, y, radius, color);
}

void EscapeGame::openDoor(int doorPin) {
  pinMode(doorPin, OUTPUT);
  digitalWrite(doorPin, HIGH);
  delay(500); // wait for door to open
  digitalWrite(doorPin, LOW);
}

void EscapeGame::waitForButtonRelease(int buttonPin) {
  while (digitalRead(buttonPin) == HIGH) {
    delay(10); // sleep before checking pin again
  }
}

ButtonColor EscapeGame::getButtonColor() {
  
  if (digitalRead(RED_BUTTON_PIN) == HIGH) {
    Serial.print("RED");
    Serial.print(" ");
    this->waitForButtonRelease(RED_BUTTON_PIN);
    return ButtonColor::RED;
  }
  if (digitalRead(GREEN_BUTTON_PIN) == HIGH) {
    Serial.print("GREEN");
    Serial.print(" ");
    this->waitForButtonRelease(GREEN_BUTTON_PIN);
    return ButtonColor::GREEN;
  }
  if (digitalRead(BLUE_BUTTON_PIN) == HIGH) {
    Serial.print("BLUE");
    Serial.print(" ");
    this->waitForButtonRelease(BLUE_BUTTON_PIN);
    return ButtonColor::BLUE;
  }
  if (digitalRead(YELLOW_BUTTON_PIN) == HIGH) {
    Serial.print("YELLOW");
    Serial.print(" ");
    this->waitForButtonRelease(YELLOW_BUTTON_PIN);
    return ButtonColor::YELLOW;
  }

  return ButtonColor::NONE;
}

void EscapeGame::getPuzzle() {
  // spin until we get a key associated with a valid puzzle
  while (true) {
    char key = this->keypad->getKey();    
     
    if (key && isDigit(key)){
      int selection = key - '0'; // convert to number
      // ensure our selection is within the current game limit
      if (selection > 0 && selection <= this->numPuzzles) {
        this->runPuzzle(selection);
      }
      else {
        this->tft->fillScreen(ST77XX_BLACK);
        this->drawText("Invalid\npuzzle", ST77XX_RED);
        delay(1000);
      }
      // once puzzle finishes redraw menu and wait for next input
      this->drawMenu();
    }
    delay(100);
  }
}

char EscapeGame::waitForKey() {
  char key;
  while (true) {
      key = this->keypad->getKey();
      if (key) {
        return key;
      }
      delay(100);
  }
}

ButtonColor EscapeGame::waitForColorButton() {
  while(true) {
    ButtonColor color = this->getButtonColor();
    if (color != ButtonColor::NONE) {
      return color;
    }

    // check for escape key
    char key = this->keypad->getKey();
    if (key == '#') {
      return ButtonColor::NONE;
    }

    delay(100);
  }
}

/*
  Get a code from the keypad and display at coordinates 
  TODO: indicate code length
*/
String EscapeGame::getKeyPadCode(int codeLength, uint16_t x, uint16_t y) {
  char headerText [] = "Enter X-digit\ncode using\nthe keypad:\n"
    "\n\nHit '#'\nto exit";
  headerText[6] = codeLength + '0'; // hacky way to enter the digit
  char key;
  char codeKey [] = "D\n";
  uint16_t offset = 0;
  String code;
  this->tft->fillScreen(ST77XX_BLACK);
  this->drawText(headerText, ST77XX_GREEN);
  for (int i=0; i<codeLength; i++) {
    // loop while waiting for keypad presses
    key = this->waitForKey();
    if (key == '#') {
      return ""; //exit
    }
    // draw next character
    codeKey[0] = key;
    code.concat(key);
    this->drawText(codeKey, ST77XX_BLUE, x+offset, y, 4);
    offset+=40;
  }
  return code;
}


String EscapeGame::getColorCode(int codeLength, uint16_t x, uint16_t y) {
  char headerText [] = "Enter X\ncolor code: \n"
    "\n\nHit '#'\nto exit";
  headerText[6] = codeLength + '0'; // hacky way to enter the digit
  ButtonColor color;
  String code;
  this->tft->fillScreen(ST77XX_BLACK);
  this->drawText(headerText, ST77XX_CYAN);
  uint16_t offset = 0;
  for (int i=0; i<codeLength; i++) {
    // loop while waiting for keypad presses
    color = this->waitForColorButton();
    if (color == ButtonColor::NONE) {
      return ""; //exit
    }

    // draw and set next code piece
    switch(color) {
      case ButtonColor::RED:
        this->drawCircle(ST77XX_RED, x+offset, y);
        code.concat("R");
        break;
      case ButtonColor::GREEN:
        this->drawCircle(ST77XX_GREEN, x+offset, y);
        code.concat("G");
        break;
      case ButtonColor::BLUE:
        this->drawCircle(ST77XX_BLUE, x+offset, y);
        code.concat("B");
        break;
      case ButtonColor::YELLOW:
        this->drawCircle(ST77XX_YELLOW, x+offset, y);
        code.concat("Y");
        break;
    }
    
    offset+=50;
  }
  return code;
}