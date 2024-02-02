/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include "SevenSegment.h"
#include <iostream>
using namespace std;

// Define a constant array representing 7-segment display values for hexadecimal digits
const unsigned int bit_values[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

// Constructor for the SevenSegment class
SevenSegment::SevenSegment() {
  // Initialize data registers to 0
  dataReg1 = 0;
  dataReg2 = 0;
}

// Destructor for the SevenSegment class
SevenSegment::~SevenSegment() { 
  // Clear all 7-segment displays when the object is destroyed
  Hex_ClearAll(); 
} 

// Clear the values in both data registers and update the corresponding hardware registers
void SevenSegment::Hex_ClearAll() { 
  dataReg1 = 0; 
  dataReg2 = 0; 
  RegisterWrite(HEX3_HEX0_BASE, dataReg1);
  RegisterWrite(HEX5_HEX4_BASE, dataReg2);
} 

// Clear the value in a specific 7-segment display in dataReg1
void SevenSegment::Hex_ClearSpecific(int index) { 
  if (index >= 0 && index < 6) { 
    dataReg1 &= ~(0x7 << (index * 4)); 
  } 
}

// Write a specific value to a specific 7-segment display
void SevenSegment::Hex_WriteSpecific(int display_id, int value) { 
  if(display_id < 4){
    // Clear the bits corresponding to the specified display in dataReg1
    dataReg1 &= ~(0xFF << (display_id * 8));
    // Set the bits with the new value for the specified display in dataReg1
    dataReg1 |= (value & 0xFF) << (display_id * 8);
    // Update the hardware register for the specified displays
    RegisterWrite(HEX3_HEX0_BASE, dataReg1); 
  } else {
    // Clear the bits corresponding to the specified display in dataReg2
    dataReg2 &= ~(0xFF << ((display_id - 4) * 8));
    // Set the bits with the new value for the specified display in dataReg2
    dataReg2 |= (value & 0xFF) << ((display_id - 4) * 8);
    // Update the hardware register for the specified displays
    RegisterWrite(HEX5_HEX4_BASE, dataReg2);
  }
} 
  
// Write a decimal number to the 7-segment displays
void SevenSegment::Hex_WriteNumber(int number) { 
  // Clear all displays before writing a new number
  Hex_ClearAll();
  // Check if the number is negative
  bool negative = false;
  if(number < 0){
    number *= -1;
    negative = true;
  }
  
  // Convert the decimal number to hexadecimal and write to the displays
  for(int i = 0; i < 6; i++){
    int remainder = number % 16;
    // Write the 7-segment value for the hexadecimal digit to the specified display
    Hex_WriteSpecific(i, bit_values[remainder]);
    number /= 16;
  }
  // If the original number was negative, display a negative sign
  if(negative) Hex_WriteSpecific(4, 0x40);
}


