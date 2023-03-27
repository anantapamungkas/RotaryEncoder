#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder {
  public:
    RotaryEncoder(int pinA, int pinB);
    void begin();
    void update();
    int getPosition();
    void setPosition(int position);

  private:
    int _pinA;
    int _pinB;
    volatile int _position;
    volatile bool _isrFlag;
};

#endif
