#ifndef motor_h
#define motor_h

#define MOTOR_PAS 8
#define MOTOR_PIN 4


#include "Arduino.h"

class motor
{
  public:
    motor(int p1, int p2, int p3, int p4, int d=5);
    void go(int count);
  private:
    int _l[4];
    int _delay;
    int _pos;
    bool _data[MOTOR_PAS][MOTOR_PIN]={
      {true,false,false,false},
      {true,true,false,false},
      {false,true,false,false},
      {false,true,true,false},
      {false,false,true,false},
      {false,false,true,true},
      {false,false,false,true},
      {true,false,false,true}
    };
};

#endif
