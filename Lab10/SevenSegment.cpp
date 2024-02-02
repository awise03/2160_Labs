#include <iostream>

#include "SevenSegment.h"

const unsigned int bit_values[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x78, 0x39, 0x5E, 0x79, 0x71};


SevenSegment::SevenSegment(){
  dataReg1 = 0;
  dataReg2 = 0;
}

SevenSegment::~SevenSegment() { 
    Hex_ClearAll(); 
} 

  

void SevenSegment::Hex_ClearAll() { 
  dataReg1 = 0; 
  dataReg2 = 0; 

} 

  

void SevenSegment::Hex_ClearSpecific(int index) { 
  if (index >= 0 && index < 6) { 
      dataReg1 &= ~(0x7 << (index * 4)); 
  } 
}

void SevenSegment::Hex_WriteSpecific(int display_id, int value) { 
  if (display_id >= 0 && display_id < 6 && value >= 0 && value < 16) { 
     unsigned int mask = 0xFF << (display_id * 8);
     dataReg1 &= ~mask;
     dataReg1 |= (value & 0xFF) << (display_id * 8);
     
     dataReg2 &= ~mask;
     dataReg2 |= (value & 0xFF) << (display_id * 8);
     
     RegisterWrite(HEX3_HEX0_BASE, dataReg1);
     RegisterWrite(HEX5_HEX4_BASE, dataReg2);
  } 
} 
  
void SevenSegment::Hex_WriteNumber(int number) { 
  Hex_ClearAll();
  if(number < 0) number *= -1;
  
  for(int i = 0; i < 6; i++){
    unsigned int mask = 0xFF << (i * 8);
    dataReg1 &= ~mask;
    dataReg1 |= (number & 0xFF) << (i * 8);
     
    dataReg2 &= ~mask;
    dataReg2 |= (number & 0xFF) << (i * 8);
    
    number /= 16;
    RegisterWrite(HEX3_HEX0_BASE, dataReg1);
  }
  //RegisterWrite(HEX3_HEX0_BASE, dataReg1);
  RegisterWrite(HEX5_HEX4_BASE + 4, dataReg2);
  
} 

