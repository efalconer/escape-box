
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include "PuzzleKeyPad.h"
#include "EasterGame.h"
#include "InheritanceGame.h"

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define DOOR1_PIN A0
#define DOOR2_PIN A1



 // ***************************Globals*********************************************
const byte maxRows = 8;
const byte maxCols = 8;
float p = 3.1415926;

byte rowPins[] = {7, 0, 1, 3}, colPins[] ={2, 4, 5, 6};
PuzzleKeyPad keypad = PuzzleKeyPad(rowPins, colPins);
// display
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
EasterGame easterGame = EasterGame(&keypad, &tft, DOOR1_PIN, DOOR2_PIN);
InheritanceGame inheritanceGame = InheritanceGame(&keypad, &tft, DOOR1_PIN, DOOR2_PIN);

// ****************************getKey ********************************************




// *********************************************************************************


void setup() {
  
    // initialize serial monitor
  Serial.begin(9600);

  // initialize display
  tft.init(240, 320);           // Init ST7789 320x240

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

}


void loop() {  
  // TOOD: make a switcher for the games

  // easter game
  //easterGame.GameLoop();

  // inheritance game
  inheritanceGame.GameLoop();
}

   
    
    