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
    
    DE1SoCfpga(); 
    
    void RegisterWrite(unsigned int reg_offset, int value);
    int RegisterRead(unsigned int reg_offset); 

    ~DE1SoCfpga();
};

#endif