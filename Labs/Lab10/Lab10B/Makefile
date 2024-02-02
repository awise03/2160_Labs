#main Makefile

main: main.o SevenSegment.o DE1SoCfpga.o LEDControl.o
	g++ main.o SevenSegment.o DE1SoCfpga.o LEDControl.o -o LEDS

main.o: main.cpp
	g++ -c main.cpp

SevenSegment.o: SevenSegment.cpp SevenSegment.h
	g++ -c SevenSegment.cpp

DE1SoCfpga.o: DE1SoCfpga.cpp DE1SoCfpga.h
	g++ -c DE1SoCfpga.cpp

LEDControl.o: LEDControl.cpp LEDControl.h
	g++ -c LEDControl.cpp

clean:
	rm main.o SevenSegment.o DE1SoCfpga.o LEDControl.o
