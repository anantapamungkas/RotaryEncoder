#include "RotaryEncoder.h"

// Interrupt service routine untuk rotary encoder input
void isr() {
  static int8_t oldA = 0, oldB = 0;
  static int8_t newA = 0, newB = 0;
  static int8_t rotaryState = 0;

  // Baca interupt pin
  newA = digitalRead(2);
  newB = digitalRead(3);

  // State perputaran rotary encoder
  if (newA != oldA || newB != oldB) {
    if (newA == newB) {
      rotaryState--;
    } else {
      rotaryState++;
    }
  }

  // Update posisi jika state perputaran berubah
  if (rotaryState == 4) {
    rotaryState = 0;
    RotaryEncoder::_position++;
  } else if (rotaryState == -4) {
    rotaryState = 0;
    RotaryEncoder::_position--;
  }

  oldA = newA;
  oldB = newB;
}

// Constructor
RotaryEncoder::RotaryEncoder(int pinA, int pinB) {
  _pinA = pinA;
  _pinB = pinB;
  _position = 0;
  _isrFlag = false;
}

// Initialization method
void RotaryEncoder::begin() {
  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_pinA), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(_pinB), isr, CHANGE);
}

// Update method (called in main loop)
void RotaryEncoder::update() {
  if (_isrFlag) {
    noInterrupts();
    _isrFlag = false;
    interrupts();
  }
}

// Get current position
int RotaryEncoder::getPosition() {
  return _position;
}

// Set current position
void RotaryEncoder::setPosition(int position) {
  _position = position;
}
