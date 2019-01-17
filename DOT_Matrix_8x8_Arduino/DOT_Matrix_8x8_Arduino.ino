/*
* LED 8x8 DotMarix using Arduino
* Created by TheCircuit
*/

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

void loop(){ 
  for (int c = 0; c < 8; c++) {
    for (int d = 0; d < 8; d++) {
      lc.setLed(0, c, d, true);
      delay(50);
    }
    lc.setRow(0, c, 240); 
  }
 lc.clearDisplay(0);
}
