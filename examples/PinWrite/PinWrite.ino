
#include <Shiftduino.h>

//To shift registers
Shiftduino sd(30, 31 , 32, 2);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  sd.clear(); //all pins set to 0
  sd.setPin(0, 1); //pin QA in the first register set to 1
  sd.setPin(8, 1); //pin QA in the second register set to 1
  sd.setPin(9, 1); //pin QB in the second register set to 1
  
  sd.setPin(0, 1, 1); //pin QB in the first register set to 1
  sd.setPin(1, 2, 1); //pin QC in the second register set to 1
}
