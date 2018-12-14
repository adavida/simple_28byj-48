#include "motor.h"

motor::motor(int p1, int p2, int p3, int p4, int d=5){
  _l[0] = p1;
  _l[1] = p2;
  _l[2] = p3;
  _l[3] = p4;
  _pos  = 0;
  _delay=d;
  for(int i=0; i<MOTOR_PIN; i++) {
    pinMode(_l[i], OUTPUT);
  }

}

void motor::go(int count){
  int mode = 1;
  int p2=0;
  if(count < 0){
    count = -count;
    mode  = 0;    
  }
  while(count >=0){
    p2=_pos; //==4?0:_pos+1;
    for(int i=0; i<MOTOR_PAS; i++){
      digitalWrite(_l[i], _data[_pos][i]);
    }
    _pos += (mode? 1:-1);
    if(_pos >= MOTOR_PAS) _pos = 0;
    if(_pos <  0) _pos = MOTOR_PAS - 1;
    count --;
    delay(_delay);
  }
}
