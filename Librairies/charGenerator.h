#ifndef CHARGENERATOR_H
#define CHARGENERATOR_H

class CharGenerator {
    int displayNumber;
    SegmentGenerator  charSegments;
    
  public:
    CharGenerator() {
      set_char (" ", 16);      
    }
    
    void set_char (String character, char brightness, CRGB color_number = CRGB::Green, CRGB color_dots = CRGB::Red, CRGB color_decimal_point = CRGB::Blue);
    void set_string(String stringToDisplay, char brightness=16, CRGB color_number = CRGB::Red, CRGB color_dots = CRGB::Black, CRGB color_decimal_point = CRGB::Black);
     
};

#endif 