#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
using namespace std;

// Physical base address of FPGA Devices 
const unsigned int LW_BRIDGE_BASE 	= 0xFF200000;  // Base offset 

// Length of memory-mapped IO window 
const unsigned int LW_BRIDGE_SPAN 	= 0x00005000;  // Address map size

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE 		= 0x00000000;  // Leds offset 
const unsigned int SW_BASE 			= 0x00000040;  // Switches offset
const unsigned int KEY_BASE 		= 0x00000050;  // Push buttons offset

class DE1SoCfpga { 
  public:
    char *pBase;
    int fd;
    
    // Constructor for the DE1SoCfpga class
    DE1SoCfpga() {
      // Open /dev/mem to give access to physical addresses
    	fd = open( "/dev/mem", (O_RDWR | O_SYNC));
      if (fd == -1)			//  check for errors in openning /dev/mem
    	{
        cout << "ERROR: could not open /dev/mem..." << endl;
        exit(1);
    	}
    	
       // Get a mapping from physical addresses to virtual addresses
       char *virtual_base = (char *)mmap (NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, LW_BRIDGE_BASE);
       if (virtual_base == MAP_FAILED)		// check for errors
       {
          cout << "ERROR: mmap() failed..." << endl;
          close (fd);		// close memory before exiting
          exit(1);        // Returns 1 to the operating system;
       }
       // Initializes pBase to virtual_base
       pBase = virtual_base;
    }
    // Destructor for the DE1SoCfpga class. Same functionality as finalize()
    ~DE1SoCfpga() {
 	    if (munmap (pBase, LW_BRIDGE_SPAN) != 0)
      	{
           cout << "ERROR: munmap() failed..." << endl;
           exit(1);
      	}
         close (fd); 	// close memory
    }
    
    /** 
     * Write a 4-byte value at the specified general-purpose I/O location. 
     * 
     * @param offset	Offset where device is mapped. 
     * @param value	Value to be written. 
     */ 
    void RegisterWrite(unsigned int reg_offset, int value) 
    { 
    	* (volatile unsigned int *)(pBase + reg_offset) = value; 
    		//volatile prevents the compiler from optimizing code
    } 
    
    /** 
     * Read a 4-byte value from the specified general-purpose I/O location. 
     *
     * @param offset	Offset where device is mapped. 
     * @return		Value read. 
     */ 
    int RegisterRead(unsigned int reg_offset) 
    { 
    	return * (volatile unsigned int *)(pBase + reg_offset); 
    } 

};

class LEDControl : public DE1SoCfpga  {
    public:
      // Constructor for LEDControl. Calls DE1SoCfpga constructor
      LEDControl(){
        DE1SoCfpga();
      }

      /** Reads all the switches and returns their value in a single integer.
      *
      * @return A value that represents the value of the switches
      */
      int ReadAllSwitches() {
          int switchValue = RegisterRead(SW_BASE);
      
          switchValue &= 0x003FFFFF;
      
          return switchValue;
      }
      
      /** Set the state of the LEDs with the given value.
      *
      * @param value Value between 0 and 1023 written to the LEDs
      */
      void WriteAllLeds(int value) {
          value = max(0, min(1023, value));
      
          RegisterWrite(LEDR_BASE, value);
      }
      
      /** Read button states and returns state based on pushbutton input
      * @return A value that represents the state of the switches
      */
      int PushButtonGet() {
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
      
      /** Changes the state of an LED (ON or OFF)
      * @param ledNum An LED number (0 to 9)
      * @param state State to change to (ON or OFF)
      */
      void Write1Led(int ledNum, int state) {
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
      
      /** Reads the value of a switch
      * @param switchNum A Switch number (0 to 9)
      * @return Switch value read
      */
      int Read1Switch(int switchNum) {
          int allSwitches = ReadAllSwitches();
          
          int switchStatus = (allSwitches >> switchNum) & 1;
          return switchStatus;
      }
      
      ~LEDControl();
};


int main() 
{ 
	 
	// ************** Put your code here **********************
  // Creates new LEDControl object dynamically
  LEDControl* leds = new LEDControl();
  
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
  }
  // Delets the LEDControl object to free up memory
  delete leds;
	// Done 
	//Finalize(pBase, fd); 
}
