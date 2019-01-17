int rows;
int cols;
int marker = 2;
#include <FastLED.h>
int myLeds[][8] = {
{0, 1, 2, 3, 4, 5, 6, 7},
{8, 9, 10, 11, 12, 13, 14, 15},
{16, 17, 18, 19, 20, 21, 22, 23},
{24, 25, 26, 27, 28, 29, 30, 31},
{32, 33, 34, 35, 36, 37, 38, 39}};

int lightUp[][8] = {{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};

#define NUM_LEDS 40
#define DATA_PIN 6
#define BRIGHTNESS 20

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  leds[myLeds[2][3]].setRGB(55,60,40);
  lightUp[2][3] = 1;
  Serial.print(lightUp[2][3]);
  FastLED.show();
  delay(1000);
}

void loop() {
  //light1s();
  addNeighbors(marker);
  marker = marker + 1;
  delay(1000);
}

//Adds the next layer of lights if the board isn't full
void addNeighbors(int level) {
  for (cols = 0; cols < 4; cols++) {
    for (rows = 0; rows < 7; rows++) {
      if (lightUp[cols][rows] == level - 1) {
        leds[myLeds[cols - 1][rows]].setRGB(55,60,40);
        lightUp[cols - 1][rows] = level;
        leds[myLeds[cols + 1][rows]].setRGB(55,60,40);
        lightUp[cols + 1][rows] = level;
        leds[myLeds[cols][rows + 1]].setRGB(55,60,40);
        lightUp[cols][rows + 1] = level;
        leds[myLeds[cols][rows - 1]].setRGB(55,60,40);
        lightUp[cols][rows - 1] = level;
        FastLED.show();
      } 
      else if (lightUp[cols][rows] == level - 2 && level != 2) {
        int FastLED_fade_counter = 255;
        for ( int i = 255; i > 0; i--)
        {
          leds[myLeds[cols][rows]].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How low we want to fade down to 0 = maximum.
          FastLED.show();
          FastLED_fade_counter -- ;  // Decrement
        }
      }
    }
  } 
    
  if (allFull()) {
    delay(1000);
    clearLightUp();
    Serial.print(lightUp[2][3]);
  }
}

//Returns true if the board is completely lit up
boolean allFull() {
  boolean result = true;
  for (cols = 0; cols < 4; cols++){
    for (rows = 0; rows < 7; rows++){
      if (lightUp[cols][rows] == 0) {
        result = false;
      }
    }
  } 
  return result;
}

//Clears the board and recalls addNeighbors
void clearLightUp() {
  for (cols = 0; cols < 4; cols++){
    for (rows = 0; rows < 7; rows++){
      lightUp[cols][rows] = 0;
    }
  }
  FastLED.clear();
  FastLED.show();
  leds[myLeds[2][3]].setRGB(55,60,40);
  lightUp[2][3] = 1;
      
  marker = 2;
  FastLED.show();
  delay(1000);
  addNeighbors(marker);
}
