
#include <Shiftduino.h>

Shiftduino sd(8, 9 , 10, 1);
boolean prueba[] = {0, 1, 0, 1, 0, 1, 0, 1};

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly: 
  sd.setPins(prueba);
  delay(200);
  sd.clear();
  delay(200);
}
