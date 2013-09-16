/*
  Library to control the 74HC595
  More info at http://bildr.org/?s=74hc595
*/

#ifndef Shiftduino_h
#define Shiftduino_h

#include "Arduino.h"

class Shiftduino
{
	public:
		Shiftduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t numOfRegisters);
		void clear();
		void setPin(int index, int value);
		void setPin(int registerNum, int index, int value);
		void setPins(boolean values[]);
		void setPins(uint64_t values);

	private:
		void writeValues();

};

#endif