int rows;
int cols;
static uint8_t hue = 0;
#include <FastLED.h>

#define NUM_LEDS 40
#define DATA_PIN 6
#define BRIGHTNESS 1

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for (int c = 0; c < 2; c++) {
    leds[c] = CRGB::Red;
    leds[c + 8] = CRGB::Red;
    delay(100);
    FastLED.show();
  }
  for (int c = 2; c < 4; c++) {
    leds[c] = CRGB::Purple;
    leds[c + 8] = CRGB::Purple;
    delay(100);
    FastLED.show();
  }
  for (int c = 4; c < 6; c++) {
    leds[c] = CRGB::Yellow;
    leds[c + 8] = CRGB::Yellow;
    delay(100);
    FastLED.show();
  }
  for (int c = 6; c < 8; c++) {
    leds[c] = CRGB::Green;
    leds[c + 8] = CRGB::Green;
    delay(100);
    FastLED.show();
  }
  for (int c = 16; c < 18; c++) {
    leds[c] = CRGB::Blue;
    leds[c + 8] = CRGB::Blue;
    delay(100);
    FastLED.show();
  }
  for (int c = 18; c < 20; c++) {
    leds[c] = CRGB::Red;
    leds[c + 8] = CRGB::Red;
    delay(100);
    FastLED.show();
  }
  for (int c = 20; c < 22; c++) {
    leds[c] = CRGB::Purple;
    leds[c + 8] = CRGB::Purple;
    delay(100);
    FastLED.show();
  }
  for (int c = 22; c < 24; c++) {
    leds[c] = CRGB::Yellow;
    leds[c + 8] = CRGB::Yellow;
    delay(100);
    FastLED.show();
  }
  for (int c = 32; c < 34; c++) {
    leds[c] = CRGB::Green;
    delay(100);
    FastLED.show();
  }
  for (int c = 34; c < 36; c++) {
    leds[c] = CRGB::Blue;
    delay(100);
    FastLED.show();
  }
  for (int c = 36; c < 38; c++) {
    leds[c] = CRGB::Red;
    delay(100);
    FastLED.show();
  }
  for (int c = 38; c < 40; c++) {
    leds[c] = CRGB::Purple;
    delay(100);
    FastLED.show();
  }
}
