int rows;
int cols;
int marker = 2;
int centerCol = 4;
int centerRow = 4;
int r = 50;
#include <FastLED.h>
#include <LedControl.h>

int myLeds[][9] = {
{0,8,16,24,32,40,48,56},
{1,9,17,25,33,41,49,57},
{2,10,18,26,34,42,50,58},
{3,11,19,27,35,43,51,59},
{4,12,20,28,36,44,52,60},
{5,13,21,29,37,45,53,61},
{6,14,22,30,38,46,54,62},
{7,15,23,31,39,47,55,63}};
int lightUp[][9] = { {0,0,0,0,0,0,0,0},
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

int DIN = 12; 
int CS =  11;
int CLK = 10; 

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      // Set the brightness to maximum value
  lc.clearDisplay(0);         // and clear the display
}

void loop() {
  //light1s();
  if (marker > 20) {
    lc.clearDisplay(0);  
  } else {
  addNeighbors(marker);
  marker = marker + 1;
  delay(200);
}
}

//Adds the next layer of lights if the board isn't full
void addNeighbors(int level) {
//fadeUp();
for (cols = 0; cols < 40; cols++) {
        if (byte a[cols] == level - 1) {
          if (byte a[cols - 1] == 0) {
            byte a[cols + 1] = CRGB::Black;
            //leds[myLeds[cols - 1][rows + 1]] += 10;
            byte a[cols + 1] = level;
          }
//          if (lightUp[cols + 1][rows - 1] == 0) {
//            leds[myLeds[cols + 1][rows - 1]] = CRGB::Black;
//           // leds[myLeds[cols + 1][rows - 1]] += 10;
//            lightUp[cols + 1][rows - 1] = level;
//          }
//          if (lightUp[cols + 1][rows + 1] == 0) {
//            leds[myLeds[cols + 1][rows + 1]] = CRGB::Black;
//            //leds[myLeds[cols + 1][rows + 1]] += 10;
//            lightUp[cols + 1][rows + 1] = level;
//          }
//          if (lightUp[cols - 1][rows - 1] == 0) {
//            leds[myLeds[cols - 1][rows - 1]] = CRGB::Black;
//            //leds[myLeds[cols - 1][rows - 1]] += 10;
//            lightUp[cols - 1][rows - 1] = level;
//          }
//          if (lightUp[cols - 1][rows] == 0) {
//            leds[myLeds[cols - 1][rows]] = CRGB::Black;
//            //leds[myLeds[cols - 1][rows]] += 10;
//            lightUp[cols - 1][rows] = level;
//          }
//          if (lightUp[cols + 1][rows] == 0) {
//            leds[myLeds[cols + 1][rows]] = CRGB::Black;
//            //leds[myLeds[cols + 1][rows]] += 10;
//            lightUp[cols + 1][rows] = level;
//          }
//          if (lightUp[cols][rows + 1] == 0) {
//            leds[myLeds[cols][rows + 1]] = CRGB::Black;
//            //leds[myLeds[cols][rows + 1]] += 10;
//            lightUp[cols][rows + 1] = level;
//          }
//          if (lightUp[cols][rows - 1] == 0) {
//            leds[myLeds[cols][rows - 1]] = CRGB::Black;
//            //leds[myLeds[cols][rows - 1]] += 10;
//            lightUp[cols][rows - 1] = level;
//            
//            FastLED.show();
//          }
      }}
      
      
      
      
     
}
if (allFull()) {
  fadeDown();
}
}

void fadeDown(){
  for (cols = 0; cols < 9; cols++) {
      for (rows = 0; rows < 8; rows++) {
        if (lightUp[cols][rows] <= marker - 7 && lightUp[cols][rows] != CRGB::Black) {
        leds[myLeds[cols][rows]] -= 19;
        
}
      }}
      FastLED.show();}

void fadeUp() {
  for (cols = 0; cols < 9; cols++) {
      for (rows = 0; rows < 8; rows++) {
        if (lightUp[cols][rows] <= marker - 1 && lightUp[cols][rows] != 0) {
          leds[myLeds[cols][rows]] += 9;
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
      leds[myLeds[centerCol][centerRow]].setRGB(r,35,0);
      lightUp[centerCol][centerRow] = 1;
      
  marker = 2;
  FastLED.show();
  delay(200);
  addNeighbors(marker);
  
}
