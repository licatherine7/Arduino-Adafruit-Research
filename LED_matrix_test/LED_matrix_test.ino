
//use FastLED.h for this program
//controls rows, columns and uses rainbow and fill functions
//tests FastLED.h 

#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    40
#define NUM_ROWS    5
#define NUM_COLS    8
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  20

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {

    int row, row2, row3, row4, row5;
    row = 1;
    row2 = row * 8;
    row3 = row * 16;
    row4 = row * 24;
    row5 = row * 32;
    int col0, col1, col2, col3, col4, col5, col6, col7;
    col0 = row * 0;
    col1 = row * 1;
    col2 = row * 2;
    col3 = row * 3;
    col4 = row * 4;
    col5 = row * 5;
    col6 = row * 6;
    col7 = row * 7;
    
    //outer loop
    for (int i = 0; i < BRIGHTNESS; i++)
    {
      leds[row-1] = CRGB::Red;
      leds[row+1] = CRGB::Red;
      leds[row+2] = CRGB::Red;
      leds[row+3] = CRGB::Red;
      leds[row+4] = CRGB::Red;
      leds[row+5] = CRGB::Red;
      leds[row+6] = CRGB::Red;
      leds[row] = CRGB::Red;

      leds[row5 + 1] = CRGB::Red;
      leds[row5 + 2] = CRGB::Red;
      leds[row5 + 3] = CRGB::Red;
      leds[row5 + 4] = CRGB::Red;
      leds[row5 + 5] = CRGB::Red;
      leds[row5 + 6] = CRGB::Red;
    
      leds[col0+8] = CRGB::Red;
      leds[col0+16] = CRGB::Red;
      leds[col0+24] = CRGB::Red;
      leds[col0+32] = CRGB::Red;
    
      leds[col7+8] = CRGB::Red;
      leds[col7+16] = CRGB::Red;
      leds[col7+24] = CRGB::Red;
      leds[col7+32] = CRGB::Red;

      FastLED.setBrightness(i);
      FastLED.show();
      delay(100);
      
    }FastLED.clear();

    FastLED.setBrightness(BRIGHTNESS);

    for (int i = BRIGHTNESS; i >= 0; --i)
    {
      leds[row -1] = CRGB::Red;
      leds[row+1] = CRGB::Red;
      leds[row+2] = CRGB::Red;
      leds[row+3] = CRGB::Red;
      leds[row+4] = CRGB::Red;
      leds[row+5] = CRGB::Red;
      leds[row+6] = CRGB::Red;
      leds[row] = CRGB::Red;

      leds[row5 + 1] = CRGB::Red;
      leds[row5 + 2] = CRGB::Red;
      leds[row5 + 3] = CRGB::Red;
      leds[row5 + 4] = CRGB::Red;
      leds[row5 + 5] = CRGB::Red;
      leds[row5 + 6] = CRGB::Red;
    
      leds[col0+8] = CRGB::Red;
      leds[col0+16] = CRGB::Red;
      leds[col0+24] = CRGB::Red;
      leds[col0+32] = CRGB::Red;
    
      leds[col7+8] = CRGB::Red;
      leds[col7+16] = CRGB::Red;
      leds[col7+24] = CRGB::Red;
      leds[col7+32] = CRGB::Red;

      FastLED.setBrightness(i);
      FastLED.show();
      delay(100);
      
    }FastLED.clear();

    FastLED.setBrightness(BRIGHTNESS);

    //second loop
    for (int i = 0; i < BRIGHTNESS; i++)
    {
    leds[row2+1] = CRGB::Yellow;
    leds[row2+2] = CRGB::Yellow;
    leds[row2+3] = CRGB::Yellow;
    leds[row2+4] = CRGB::Yellow;
    leds[row2+5] = CRGB::Yellow;
    leds[row2+6] = CRGB::Yellow;

    leds[row4+1] = CRGB::Yellow;
    leds[row4+2] = CRGB::Yellow;
    leds[row4+3] = CRGB::Yellow;
    leds[row4+4] = CRGB::Yellow;
    leds[row4+5] = CRGB::Yellow;
    leds[row4+6] = CRGB::Yellow;

    leds[row3+1] = CRGB::Yellow;
    leds[row3+6] = CRGB::Yellow;

    FastLED.setBrightness(i);
    FastLED.show();
    delay (100);
    }FastLED.clear();

    FastLED.setBrightness(BRIGHTNESS);

    for (int i = BRIGHTNESS; i >= 0; i--)
    {
    leds[row2+1] = CRGB::Yellow;
    leds[row2+2] = CRGB::Yellow;
    leds[row2+3] = CRGB::Yellow;
    leds[row2+4] = CRGB::Yellow;
    leds[row2+5] = CRGB::Yellow;
    leds[row2+6] = CRGB::Yellow;

    leds[row4+1] = CRGB::Yellow;
    leds[row4+2] = CRGB::Yellow;
    leds[row4+3] = CRGB::Yellow;
    leds[row4+4] = CRGB::Yellow;
    leds[row4+5] = CRGB::Yellow;
    leds[row4+6] = CRGB::Yellow;

    leds[row3+1] = CRGB::Yellow;
    leds[row3+6] = CRGB::Yellow;

    FastLED.setBrightness(i);
    FastLED.show();
    delay (100);
    }FastLED.clear();

    for (int i = 0; i < BRIGHTNESS; i++)
    {
    leds[row3+2] = CRGB::Green;
    leds[row3+3] = CRGB::Green;
    leds[row3+4] = CRGB::Green;
    leds[row3+5] = CRGB::Green;
    
    FastLED.setBrightness(i);
    FastLED.show();
    delay(100);
    }
    FastLED.clear();

    for (int i = BRIGHTNESS; i >= 0; i--)
    {
    leds[row3+2] = CRGB::Green;
    leds[row3+3] = CRGB::Green;
    leds[row3+4] = CRGB::Green;
    leds[row3+5] = CRGB::Green;
    
    FastLED.setBrightness(i);
    FastLED.show();
    delay(100);
    }
    FastLED.clear();

//  // put your main code here, to run repeatedly:
//  FastLED.clear();
//  fill_solid(leds, NUM_LEDS, CRGB(145,44,20));
//  FastLED.show();
//  delay(1000);
//  FastLED.clear();
//
//  fill_solid(leds, NUM_LEDS, CRGB::Yellow);
//  FastLED.show();
//  delay(1000);
//  FastLED.clear();
//
//  for (int i=0; i<NUM_ROWS; i++) //turns on each led in a row for row 1
//  {
//    leds[i].setRGB(255,0,0);
//    FastLED.show();
//    delay(100);
//    FastLED.clear(); //if you want to clear after showing each led
//  }
//  for (int i=NUM_COLS; i<(NUM_COLS*2); i++) //turns on each led in a row for row 2
//  {
//    leds[i].setRGB(0,255,0);
//    FastLED.show();
//    delay(100);
//    FastLED.clear(); //if you want to clear after showing each led
//  }
//  for (int i=0; i< NUM_LEDS; i++) //turns on leds in a column
//  {
//    leds[NUM_COLS*i].setRGB(0,255,255);
//    FastLED.show();
//    delay(10);
//  }
//  for (int i=0;i<NUM_LEDS;i++)
//  {
//    fill_rainbow(leds, i, 0, 5);
//    FastLED.show();
//    delay(100);
//  }
//  
//  FastLED.clear();
  
}

//work on fade
//circles and diamonds and squares that expand out
//diagonals
