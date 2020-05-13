#include "segmentGenerator.h"

SegmentGenerator::SegmentGenerator(){
      displaySegments.decimal_point = 0;
      displaySegments.dots[0] = 0;
      displaySegments.dots[1] = 0;
      displaySegments.brightness = 16;
    }
	
	
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

