/*
  Library to control the 74HC595
  More info at http://bildr.org/?s=74hc595
*/

#include "Arduino.h"
#include "Shiftduino.h"

int _dataPin;				//pin 14 on the 75HC595
int _latchPin;				//pin 12 on the 75HC595
int _clockPin;				//pin 11 on the 75HC595

int _numOfRegisterPins;		//number of c.i. in cascade

#define maxRegisterPins 64

boolean _registers[maxRegisterPins];

Shiftduino::Shiftduino(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t numOfRegisters){

	_dataPin = dataPin;
	pinMode(_dataPin, OUTPUT);

	_clockPin = clockPin;
	pinMode(_clockPin, OUTPUT);

	_latchPin = latchPin;
	pinMode(_latchPin, OUTPUT);

	_numOfRegisterPins = numOfRegisters * 8;
	
	//reset all register pins
	clear();
	writeValues();
}               


//set all register pins to LOW
void Shiftduino::clear(){
  for(int i = _numOfRegisterPins - 1; i >=  0; i--){
     _registers[i] = LOW;
  }

  //set pins
  writeValues();
} 


//set an individual pin HIGH or LOW
void Shiftduino::setPin(int index, int value){
  _registers[index] = value;

  //set pins
  writeValues();
}

//set an individual pin HIGH or LOW, specifiying the register number
void Shiftduino::setPin(int registerNum, int index, int value){
  int finalIndex = (registerNum * 8) + index;
  _registers[finalIndex] = value;

  //set pins
  writeValues();
}


//set all pins HIGH or LOW
void Shiftduino::setPins(boolean values[]){
  for(int i = _numOfRegisterPins - 1; i >=  0; i--){
     _registers[i] = values[i];
  }

  //set pins
  writeValues();
}

//set all pins HIGH or LOW
void Shiftduino::setPins(uint64_t values){
  for(int i = 0; i < _numOfRegisterPins; i++){
    _registers[i] = values & 0x00000001;
	values >>= 1;
  }

  //set pins
  writeValues();
}

//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void Shiftduino::writeValues(){

  digitalWrite(_latchPin, LOW);

  for(int i = _numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(_clockPin, LOW);

    int value = _registers[i];

    digitalWrite(_dataPin, value);
    digitalWrite(_clockPin, HIGH);

  }
  digitalWrite(_latchPin, HIGH);
}

