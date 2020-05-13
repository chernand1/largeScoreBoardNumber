#include "FastLED.h"
#include "Librairies\lightAssignment.cpp"
#include "Librairies\segmentGenerator.cpp"
#include "Librairies\charGenerator.cpp"

void setup() {

  Serial.begin(9600);
  
}

void loop() {

  String stringToPrint = "   ";
  
  CharGenerator charToDisplay;
  
  CRGB color_chars[6] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Fuchsia, CRGB::White};
  int color_index = 0;
  int Red, Green, Blue;
  
  charToDisplay.set_char("S", 16, CRGB(255, 0, 0));
  delay(500);
  charToDisplay.set_char("E", 16, CRGB(255, 255, 0));
  delay(500);
  charToDisplay.set_char("L", 16, CRGB(255, 255, 255));
  delay(500);
  charToDisplay.set_char("F", 16, CRGB(0, 255, 0));
  delay(500);
  charToDisplay.set_char("T", 16, CRGB(0, 255, 255));
  delay(500);
  charToDisplay.set_char("E", 16, CRGB(255, 255, 255));
  delay(500);
  charToDisplay.set_char("S", 16, CRGB(0, 0, 255));
  delay(500);
  charToDisplay.set_char("T", 16, CRGB(255, 0, 255));
  delay(500);
  charToDisplay.set_char(".:8", 16, CRGB::Black, CRGB::Black, CRGB::Black);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::White, CRGB::White, CRGB::White);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::Black, CRGB::Black, CRGB::Black);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::White, CRGB::White, CRGB::White);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::Black, CRGB::Black, CRGB::Black);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::White, CRGB::White, CRGB::White);
  delay(1000);
  charToDisplay.set_char(".:8", 16, CRGB::Black, CRGB::Black, CRGB::Black);
  
  while(1){
    
    for (int i=0; i<=9; i++){
      Red = random(255);
      Green = random(255);
      Blue = random(255);
      stringToPrint[0] = ' ';
      stringToPrint[1] = '.';
      stringToPrint[2] = i + 0x30;
        
      charToDisplay.set_char(stringToPrint, 16, CRGB(Red, Green, Blue));
      delay(250);
      stringToPrint[0] = ':';
      stringToPrint[1] = ' ';
      charToDisplay.set_char(stringToPrint, 16, CRGB(Red, Green, Blue));
      delay(250);
  
      color_index++;
      if (color_index == 6)
        color_index = 0;
  
    }
  
  }

}
