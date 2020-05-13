#ifndef SEGMENTGENERATOR_H
#define SEGMENTGENERATOR_H

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
    
    SegmentGenerator();
    void set_segments (int number, char decimal_point, char dots[2], CRGB color_number, CRGB color_dots, CRGB color_decimal_point);
    void set_lights (displaySegments_struct displaySegments);
};

#endif 