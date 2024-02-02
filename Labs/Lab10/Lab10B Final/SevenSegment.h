/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "DE1SoCfpga.h"

class SevenSegment : public DE1SoCfpga {
  private:
    unsigned int dataReg1;
    unsigned int dataReg2;
    
  public:
    SevenSegment();

    /** Clears the HEX Displays*/
    void Hex_ClearAll();

    /** Clears a specific HEX display
     * @param index the display number to be cleared
    */
    void Hex_ClearSpecific(int index);

    /** Displays a specific value to the desired display_id
     * @param display_id display number to be written to (0 to 6)
     * @param value value to be displayed by the displays
    */
    void Hex_WriteSpecific(int display_id, int value);

    /** Breaks number up to be displayed in Hex_WriteSpecific
     * @param number value to be split up for displaying on the display
    */
    void Hex_WriteNumber(int number);
    
    ~SevenSegment();
};

#endif