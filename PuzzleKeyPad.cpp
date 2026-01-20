#include "PuzzleKeyPad.h"

PuzzleKeyPad::PuzzleKeyPad(byte *rowPins, byte *colPins) {
  this->rowPins = rowPins;
  this->colPins = colPins;
  
  // initialize row and column pins
  for(int r = 0; r < numRows; r++)
  {
      pinMode(rowPins[r], INPUT);
  }

  for(int c = 0; c < numCols; c++)
  {
      pinMode(colPins[c], INPUT);
  }
}


char PuzzleKeyPad::getKey()
{
   bool keyDown = false;
   char key = NULL;

   // scan for keypress  
   for (byte col = 0; col < numCols; col++)        
     {
        // set column pin mode to OUTPUT and 
        // set column pin to LOW
       pinMode(colPins[col], OUTPUT);
       digitalWrite(colPins[col],LOW);
      
       for (byte row = 0; row < numRows; row++)
       { 
           // check each row for LOW
           pinMode(rowPins[row], INPUT_PULLUP);           
           if (digitalRead(rowPins[row]) == LOW)             
            {
               // detected possible keypress - debounce               
               delay(50);
               
               // now check row again
               if (digitalRead(rowPins[row]) == LOW)
                {
                  // valid keypress - send coordinates to processKey
                  keyDown = true;
                  key = processKey(row, col);
                                   
                  // Wait for key to be released.
                  do
                   {
                      //delay before checking pin state
                      delay(10); 

                   } while (digitalRead(rowPins[row]) == LOW); 
                  break;                     
                }              
            }
          pinMode(rowPins[row], INPUT);
          if (keyDown == true) break;
       }
       pinMode(colPins[col], INPUT);
       if (keyDown == true)break;       
     }
     
     return key;
}

// ****************************processKey******************************************

char PuzzleKeyPad::processKey(byte row, byte col)
// When called, uses row and col coordinates to retrieve key value from keyChars array   
//   and do something with it. For this example it just prints the character to the
//   serial monitor.      
{          
    char keyVal;    
    char keyChars[numRows][numCols] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };

        
     {
       // get the key label from the array and send it to the serial terminal       
       keyVal = keyChars[row][col];        
       Serial.print(keyVal);
       Serial.print(" ");
       
       return keyVal;        
      }  
       
} 