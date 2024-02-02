/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#ifndef DE1SOCFPGA_H
#define DE1SOCFPGA_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

// Physical base address of FPGA Devices 
const unsigned int LW_BRIDGE_BASE 	= 0xFF200000;  // Base offset 

// Length of memory-mapped IO window 
const unsigned int LW_BRIDGE_SPAN 	= 0x00005000;  // Address map size

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE 		= 0x00000000;  // Leds offset 
const unsigned int SW_BASE 			= 0x00000040;  // Switches offset
const unsigned int KEY_BASE 		= 0x00000050;  // Push buttons offset

// HEX Offset Values
const unsigned int HEX3_HEX0_BASE = 0x00000020; // Data Reg1 offset
const unsigned int HEX5_HEX4_BASE = 0x00000030; // Data Reg2 offset

using namespace std;

class DE1SoCfpga { 
  public:
    char *pBase;
    int fd;
    // Constructor for the DE1SoCfpga class
    DE1SoCfpga(); 
    // Destructor for the DE1SoCfpga class
    ~DE1SoCfpga();

    /** 
     * Write a 4-byte value at the specified general-purpose I/O location. 
     * 
     * @param offset	Offset where device is mapped. 
     * @param value	Value to be written. 
     */ 
    void RegisterWrite(unsigned int reg_offset, int value);

    /** 
     * Read a 4-byte value from the specified general-purpose I/O location. 
     *
     * @param offset	Offset where device is mapped. 
     * @return		Value read. 
     */     
    int RegisterRead(unsigned int reg_offset); 

};

#endif