int rows;
int cols;
int marker = 2;
int centerCol = 4;
int centerRow = 4;
int r = 50;
#include <FastLED.h>
//the adresses of the leds
int myLeds[][9] = {
{0,9,18,27,36,45,54,63},
{1,10,19,28,37,46,55,64},
{2,11,20,29,38,47,56,65},
{3,12,21,30,39,48,57,66},
{4,13,22,31,40,49,58,67},
{5,14,23,32,41,50,59,68},
{6,15,24,33,42,51,60,69},
{7,16,25,34,43,52,61,70},
{8,17,26,35,44,53,62,71},
};
//the level of the lights
int lightUp[][9] = { {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
};

#define NUM_LEDS 72
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  leds[myLeds[centerCol][centerRow]] = CRGB::Black;
  lightUp[centerCol][centerRow] = 1;
  Serial.print(lightUp[centerCol][centerRow]);
  delay(90);
}

void loop() {
  //light1s();
  addNeighbors(marker);
  marker = marker + 1;
  delay(90);

}

//Adds the next layer of lights if the board isn't full
void addNeighbors(int level) {
  if (allOff()) {
    clearLightUp();
  }
  if (allFull() && marker > 6) {
  fadeDown();
  } else {
fadeUp();
for (cols = 0; cols < 9; cols++) {
      for (rows = 0; rows < 8; rows++) {
        if (lightUp[cols][rows] == level - 1) {
          if (lightUp[cols - 1][rows + 1] == 0) {
            leds[myLeds[cols - 1][rows + 1]] = CRGB::Black;
            //leds[myLeds[cols - 1][rows + 1]] += 10;
            lightUp[cols - 1][rows + 1] = level;
          }
          if (lightUp[cols + 1][rows - 1] == 0) {
            leds[myLeds[cols + 1][rows - 1]] = CRGB::Black;
           // leds[myLeds[cols + 1][rows - 1]] += 10;
            lightUp[cols + 1][rows - 1] = level;
          }
          if (lightUp[cols + 1][rows + 1] == 0) {
            leds[myLeds[cols + 1][rows + 1]] = CRGB::Black;
            //leds[myLeds[cols + 1][rows + 1]] += 10;
            lightUp[cols + 1][rows + 1] = level;
          }
          if (lightUp[cols - 1][rows - 1] == 0) {
            leds[myLeds[cols - 1][rows - 1]] = CRGB::Black;
            //leds[myLeds[cols - 1][rows - 1]] += 10;
            lightUp[cols - 1][rows - 1] = level;
          }
          if (lightUp[cols - 1][rows] == 0) {
            leds[myLeds[cols - 1][rows]] = CRGB::Black;
            //leds[myLeds[cols - 1][rows]] += 10;
            lightUp[cols - 1][rows] = level;
          }
          if (lightUp[cols + 1][rows] == 0) {
            leds[myLeds[cols + 1][rows]] = CRGB::Black;
            //leds[myLeds[cols + 1][rows]] += 10;
            lightUp[cols + 1][rows] = level;
          }
          if (lightUp[cols][rows + 1] == 0) {
            leds[myLeds[cols][rows + 1]] = CRGB::Black;
            //leds[myLeds[cols][rows + 1]] += 10;
            lightUp[cols][rows + 1] = level;
          }
          if (lightUp[cols][rows - 1] == 0) {
            leds[myLeds[cols][rows - 1]] = CRGB::Black;
            //leds[myLeds[cols][rows - 1]] += 10;
            lightUp[cols][rows - 1] = level;
            
            FastLED.show();
          }
      }}
      
      
      
      
     
}
}
}

void fadeDown(){
  for (cols = 0; cols < 9; cols++) {
      for (rows = 0; rows < 8; rows++) {
        if (lightUp[cols][rows] <= marker - 7) {
          leds[myLeds[cols][rows]].subtractFromRGB(2);
}
      }
  }
      FastLED.show();}

void fadeUp() {
  for (cols = 0; cols < 9; cols++) {
      for (rows = 0; rows < 8; rows++) {
        if (lightUp[cols][rows] <= marker - 1 && lightUp[cols][rows] != 0) {
            leds[myLeds[cols][rows]].addToRGB(3);
        }
       
}
  }
}

//Returns true if the board is completely lit up
boolean allFull() {
  boolean result = true;
  for (cols = 0; cols < 9; cols++){
      for (rows = 0; rows < 8; rows++){
        if (lightUp[cols][rows] == 0) {
          result = false;
        }
      }
  } return result;
}

boolean allOff() {
  boolean result = true;
  for (cols = 0; cols < 9; cols++){
      for (rows = 0; rows < 8; rows++){
        if (leds[myLeds[cols][rows]] != CRGB(0,0,0)) {
          result = false;
        }
      }
  } return result;
}

//Clears the board and recalls addNeighbors
void clearLightUp() {
  for (cols = 0; cols < 9; cols++){
      for (rows = 0; rows < 8; rows++){
          lightUp[cols][rows] = 0;
          }

      }
      FastLED.clear();
      FastLED.show();
      //r = r + 10;
      leds[myLeds[centerCol][centerRow]].addToRGB(4);
      lightUp[centerCol][centerRow] = 1;
      
  marker = 2;
  
  delay(90);
  FastLED.show();
  delay(90);
  addNeighbors(marker);
  
}
