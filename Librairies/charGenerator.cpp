#include "charGenerator.h"

void CharGenerator::set_char(String character, char brightness, CRGB color_number = CRGB::Green, CRGB color_dots = CRGB::Red, CRGB color_decimal_point = CRGB::Blue) {
      char decimal_point = 0;
      char dots[2];
      
      displayNumber = 10;
      
      dots[0] = 0;
      dots[1] = 0;

      int index_of_decimal = character.indexOf('.');
      int index_of_dots = character.indexOf(':');

      if (index_of_decimal >= 0)
        decimal_point = 1;

      if (index_of_dots >= 0){
        dots[0] = 1;
        dots[1] = 1;   
      }
      
      int stringLength = character.length();
      char characterToCheck;
      
      for (int i=0; i<stringLength; i++) {
        characterToCheck = character[i];

        if((int(characterToCheck) >= '0') && (int(characterToCheck) <= '9')){
          charSegments.set_segments(int(characterToCheck - 0x30), decimal_point, dots, color_number, color_dots, color_decimal_point);
        }
        else if((int(characterToCheck) >= 'A') && (int(characterToCheck) <= 'Z')){
          charSegments.set_segments(int(characterToCheck), decimal_point, dots, color_number, color_dots, color_decimal_point);
        }
      }
    
}

void CharGenerator::set_string(String stringToDisplay, char brightness=16, CRGB color_number = CRGB::Red, CRGB color_dots = CRGB::Black, CRGB color_decimal_point = CRGB::Black) {
  
}
