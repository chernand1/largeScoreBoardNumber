#include "lightAssignment.h"

lightAssignment::lightAssignment(){
      initializeLeds();
    }
	
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