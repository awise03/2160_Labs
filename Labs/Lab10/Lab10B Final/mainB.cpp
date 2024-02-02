/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include "SevenSegment.h"
#include "DE1SoCfpga.h"
#include "LEDControl.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

int main() 
{ 
	 
	// ************** Put your code here **********************
  // Creates new LEDControl and SevenSegment objects dynamically
  LEDControl* leds = new LEDControl();
  SevenSegment* ss = new SevenSegment();
  
  // Code to turn on initial LEDs based on switch input
  int value = leds->ReadAllSwitches();
  leds->WriteAllLeds(value);
  
  // Loops infinitely until user manualy exits program
  while(true){
      // Gets the state of the push buttons
      int state = leds->PushButtonGet();
      
      // Switch statement to process push button state
      switch(state){
        // Increments the value displayed by the leds by 1
        case 0:
          value++;
          sleep(1);
          break;
        // Decrements the value displayed by the leds by 1
        case 1:
          value--;
          sleep(1);
          break;
        // Shifts the binary number displayed by the Leds to the right by 1 bit
        case 2:
          value >>=1;
          sleep(1);
          break;
        // Shifts the binary number displayed by the leds to the left by 1
        case 3:
          value <<= 1;
          sleep(1);
          break;
        // Reads value from switches and loads/sends it to the leds
        case 4:
          value = leds->ReadAllSwitches();
          sleep(1);
          break; 
      };
      // Sends change in value to the fpga board
      leds->WriteAllLeds(value);
      ss->Hex_WriteNumber(value);
  }
  // Delets the LEDControl and SevenSegment object to free up memory
  delete leds;
  delete ss;
}