#ifndef LIGHTASSIGNMENT_H
#define LIGHTASSIGNMENT_H

#ifdef __cplusplus
extern "C" {
#endif

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
    lightAssignment ();
    void initializeLeds ();
    void segmentsToLight (displaySegments_struct);
};

#ifdef __cplusplus
}
#endif

#endif 
