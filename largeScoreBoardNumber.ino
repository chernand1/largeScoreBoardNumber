#include "FastLED.h"
#define NUM_LEDS 140
#define LED_TYPE WS2812B
#define LED_PIN 8
#define COLOR_ORDER GRB

    struct displaySegments_struct {
      char segs[7];
      CRGB color_segs[7];
      char decimal_point;
      CRGB color_decimal_point;
      char dots[2];
      CRGB color_dots[2];
      char brightness;
    };
    
class lightAssignment {

  CRGB leds[NUM_LEDS];

  const int segments[7][22] = {{ 1,  2,  3,  4,  5,  6,  7,  8, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 29, 29, 29, 39},
                                {11, 12, 13, 14, 15, 16, 17, 18, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 39, 39, 39, 39},
                                { 1, 20, 21, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 59},
                                {56, 57, 59, 60, 61, 62, 63, 64, 65, 66, 78, 79, 80, 81, 82, 83, 84, 85, 85, 85, 85, 85},
                                {69, 70, 71, 72, 73, 74, 75, 76, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 95, 95, 95, 95},
                                {18, 38, 39, 76, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111},
                                {67, 68, 85, 86, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 126, 127, 127}};
                                

  const int dots[2][4] = {{128, 129, 130, 131},
                          {132, 133, 134, 135}};

  const int decimal[4] = {136, 137, 138, 139};
                           
  public:
    lightAssignment(){
      initializeLeds();
    }
    void initializeLeds ();
    void segmentsToLight (displaySegments_struct);
};

void lightAssignment::initializeLeds(){
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(16);
  
  for (int i=0; i<NUM_LEDS; i++)
    leds[i] = CRGB(0, 0, 0);

  FastLED.show();

}

void lightAssignment::segmentsToLight(displaySegments_struct segmentsToDisplay){
int led_index;

  for (int seg_index=0; seg_index<7; seg_index++)
    for(led_index=0; led_index<(sizeof(segments[0]) / sizeof(segments[0][0])); led_index++)
      leds[segments[seg_index][led_index]] = CRGB::Black;
      
  for (int seg_index=0; seg_index<7; seg_index++){   
    for(led_index=0; led_index<(sizeof(segments[0]) / sizeof(segments[0][0])); led_index++){
      if (segmentsToDisplay.segs[seg_index] == 1)
        leds[segments[seg_index][led_index]] = segmentsToDisplay.color_segs[seg_index];
    }
  }

  for(int dot_index=0; dot_index<2; dot_index++){
    for(led_index=0; led_index<(sizeof(dots[0]) / sizeof(dots[0][0])); led_index++)
      if (segmentsToDisplay.dots[dot_index] == 1)
        leds[dots[dot_index][led_index]] = segmentsToDisplay.color_dots[dot_index];
      else
        leds[dots[dot_index][led_index]] = CRGB::Black;
  }

  
  for(led_index=0; led_index<(sizeof(decimal) / sizeof(decimal[0])); led_index++)
    if (segmentsToDisplay.decimal_point == 1)
      leds[decimal[led_index]] = segmentsToDisplay.color_decimal_point;
    else
      leds[decimal[led_index]] = CRGB::Black;

  FastLED.show();

}

class SegmentGenerator {

//           6 
//           _   
//       2 |   | 5
// dot 0  .  _   7
// dot 1  .       
//       1 |   | 4
// dp     .  _
//           3
                    //segments  1, 2, 3, 4, 5, 6, 7
  const char numbers[12][7] = {{ 1, 1, 1, 1, 1, 1, 0 },// 0
                              { 0, 0, 0, 1, 1, 0, 0 }, // 1
                              { 1, 0, 1, 0, 1, 1, 1 }, // 2
                              { 0, 0, 1, 1, 1, 1, 1 }, // 3
                              { 0, 1, 0, 1, 1, 0, 1 }, // 4
                              { 0, 1, 1, 1, 0, 1, 1 }, // 5
                              { 1, 1, 1, 1, 0, 1, 1 }, // 6
                              { 0, 0, 0, 1, 1, 1, 0 }, // 7
                              { 1, 1, 1, 1, 1, 1, 1 }, // 8
                              { 0, 1, 1, 1, 1, 1, 1 }, // 9
                              { 0, 0, 0, 0, 0, 0, 0 }  // Blank = 10
                              };

 //char alphabet[7] = {'E', 'F', 'L', 'S', 'T', '\0'};
 String alphabet = "EFLST";

 const char letters[6][7] = {{ 1, 1, 1, 0, 0, 1, 1 }, // E
                             { 1, 1, 0, 0, 0, 1, 1 }, // F
                             { 1, 1, 1, 0, 0, 0, 0 }, // L
                             { 0, 1, 1, 1, 0, 1, 1 }, // S                       
                             { 1, 1, 1, 0, 0, 0, 1 },  // T
                             };

                        
  public:

    displaySegments_struct displaySegments;
    lightAssignment currentLightAssignment;
    
    SegmentGenerator(){
      displaySegments.decimal_point = 0;
      displaySegments.dots[0] = 0;
      displaySegments.dots[1] = 0;
      displaySegments.brightness = 16;
    }
    void set_segments (int number, char decimal_point, char dots[2], CRGB color_number, CRGB color_dots, CRGB color_decimal_point);
    void set_lights (displaySegments_struct displaySegments);
};

void SegmentGenerator::set_segments(int number, char decimal_point, char dots[2], CRGB color_number, CRGB color_dots, CRGB color_decimal_point) {

  for (int i=0; i<7; i++) {
    if(number > 9){
      displaySegments.segs[i] = letters[alphabet.indexOf(number)][i];
      Serial.println(alphabet.indexOf(number));
      Serial.println(number);
    }
    else
      displaySegments.segs[i] = numbers[number][i];
    displaySegments.color_segs[i] = color_number;
  }
  
  displaySegments.decimal_point = decimal_point;
  displaySegments.dots[0] = dots[0];
  displaySegments.dots[1] = dots[1];
  displaySegments.color_dots[0] = color_dots;
  displaySegments.color_dots[1] = color_dots;
  displaySegments.color_decimal_point = color_decimal_point;
  set_lights(displaySegments);
}

void SegmentGenerator::set_lights (displaySegments_struct displaySegments) {
  int i;

  currentLightAssignment.segmentsToLight(displaySegments);
}

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
