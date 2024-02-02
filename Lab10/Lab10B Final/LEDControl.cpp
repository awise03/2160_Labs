/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include <iostream>

#include "LEDControl.h"
using namespace std;


LEDControl::LEDControl(){
  leds_regValue = 0;
}

LEDControl::~LEDControl(){
  cout << "Closing LEDs, Switches, and Buttons...";
}

void LEDControl::Write1Led(int ledNum, int state) {
    int curValue = ReadAllSwitches();
    // Checks the input state to decide whether or not to turn the LED on
    if(state == 1)
      curValue |= (1 << ledNum);
    else if(state == 0)
      curValue &= (0 << ledNum);
    else
      cout << "Invalid state";
    // Writes high or low to the selected LED.
    RegisterWrite(LEDR_BASE, curValue);
}

void LEDControl::WriteAllLeds(int value) {
    value = max(0, min(1023, value));

    RegisterWrite(LEDR_BASE, value);
}

int LEDControl::PushButtonGet() {
  // Reads the current state of the push buttons
    int buttonState = RegisterRead(KEY_BASE);
    
    // Variables to track the number of buttons pressed 
    int countPressed = 0;
    int lastPressed = -1;
    
    for(int i = 0; i < 4; i++){
        // Checks to see if i-th button is pressed (i.e returning a value of 1)
        if((buttonState & (1 << i)) != 0 ){
            // Increment number of buttons being pressed
            countPressed++;
            // Record index of button
            lastPressed = i;
        }
    }
    // Sends the proper code based on buttons pressed. Returns -1 if no button pressed.
    if(countPressed == 1){
        return lastPressed;
    } else if (countPressed > 1) {
        return 4;
    } else {
        return -1;
    }
}

int LEDControl::ReadAllSwitches() {
    int switchValue = RegisterRead(SW_BASE);

    switchValue &= 0x003FFFFF;

    return switchValue;
}
int LEDControl::Read1Switch(int switchNum) {
    int allSwitches = ReadAllSwitches();
    
    int switchStatus = (allSwitches >> switchNum) & 1;
    return switchStatus;
}

