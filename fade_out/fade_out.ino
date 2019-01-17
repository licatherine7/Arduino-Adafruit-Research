#include <LedControl.h>

int DIN = 12; 
int CS =  11;
int CLK = 10; 

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);
 lc.setIntensity(0,15);      
 lc.clearDisplay(0);
}

void loop() {
  lc.setLed(0, 0, 0, true);
  for (int c = 0; c < 8; c++) {
    for (int d = 0; d < 8; d++) {
      lc.setLed(0, c, c + d, true);
      lc.setLed(0, c + d, d, true);
      delay(50);
    }
  }
  lc.clearDisplay(0);
}
