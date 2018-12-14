#include "motor.h"

int tour=1; //2048*5;
motor M(4,5,6,7,1);
int btnu = 9;
int btno = 8;
void setup() {
  Serial.begin(115200);
  pinMode(btnu, INPUT);
  pinMode(btno, INPUT);
}

void loop() {
  if(digitalRead(btnu))
    M.go(tour);
  else if(digitalRead(btno))
    M.go(-tour);
}
