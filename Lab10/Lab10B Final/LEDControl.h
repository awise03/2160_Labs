/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include "DE1SoCfpga.h"
#include "SevenSegment.h"

class LEDControl : public DE1SoCfpga {
  private:
    unsigned int leds_regValue;
  public:
    // Constructor for LEDControl class
    LEDControl();
    // Destructor for LEDControl class
    ~LEDControl();

    /** Changes the state of an LED (ON or OFF)
    * @param ledNum An LED number (0 to 9)
    * @param state State to change to (ON or OFF)
    */
    void Write1Led(int ledNum, int state);

    /** Set the state of the LEDs with the given value.
    * @param value Value between 0 and 1023 written to the LEDs
    */
    void WriteAllLeds(int value);

    /** Reads the value of a switch
    * @param switchNum A Switch number (0 to 9)
    * @return Switch value read
    */
    int Read1Switch(int switchNum);

    /** Reads all the switches and returns their value in a single integer.
    * @return A value that represents the value of the switches
    */
    int ReadAllSwitches();

    /** Read button states and returns state based on pushbutton input
    * @return A value that represents the state of the switches
    */
    int PushButtonGet();
};

#endif