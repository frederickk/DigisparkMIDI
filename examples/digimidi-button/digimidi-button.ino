#include "MomentaryButton.h"

#define MODE_TOGGLE_PIN 12

// These pins values are hard coded into DigiMIDI.h usbFunctionWriteOut().
#define CLOCK_OUT_PIN 1


MomentaryButton modeButton(MODE_TOGGLE_PIN);
boolean modeFlag = 1; // 1 = clock, 0 = note
boolean modeFlagPrev = 1;


void setup() {
  pinMode(CLOCK_OUT_PIN, OUTPUT);
  modeButton.init();
}

void loop() {
  if(modeButton.get() == HIGH) {
    modeFlag = 1 - modeFlag;
  }

  if(modeFlag == 1 && modeFlagPrev == 0) {
    digitalWrite(CLOCK_OUT_PIN, HIGH);
  }
  if(modeFlag == 0 && modeFlagPrev == 1) {
    digitalWrite(CLOCK_OUT_PIN, LOW);
  }

  modeFlagPrev = modeFlag;
}
