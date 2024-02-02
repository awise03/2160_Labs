#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "DE1SoCfpga.h"

class SevenSegment : public DE1SoCfpga {
  private:
    unsigned int dataReg1;
    unsigned int dataReg2;
    
  public:
    SevenSegment();
    
    void Hex_ClearAll();
    void Hex_ClearSpecific(int index);
    void Hex_WriteSpecific(int display_id, int value);
    void Hex_WriteNumber(int number);
    
    ~SevenSegment();
};

#endif