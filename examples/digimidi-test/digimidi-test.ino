#include <DigiMIDI.h>


DigiMIDIDevice midi;

// Set to 1 to enable, 0 to disable
#define DEBUG 1

#if DEBUG
  // Digispark model A onboard LED
  #define DebugPin 1
  #define DebugBlink 75
  #define DebugPause 300
  // Change if you need a special delay function (e.g. if you use libraries
  // that need regular refresh calls)
  #define debugDelay(ms) delay(ms)

  void _debugBlink(int n) {
    for (uint16_t i = 0 ; i < n ; i++ ) {
      digitalWrite(DebugPin, HIGH);
      debugDelay(DebugBlink);
      digitalWrite(DebugPin, LOW);
      debugDelay(DebugBlink);
    }
    debugDelay(DebugPause);
  }

  void _debugSetup() {
    pinMode(DebugPin, OUTPUT);
  }

  // Do the blink when DEBUG is set
  #define debugBlink(n) _debugBlink(n)
  #define debugSetup() _debugSetup()

#else
  // Make the calls disappear when DEBUG is 0
  #define debugBlink(n)
  #define debugSetup()
#endif


void setup() {
  // put your setup code here, to run once:
  debugSetup();
  debugBlink(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  midi.update();

  midi.delay(500);
  debugBlink(1);

  // Note number, velocity, channel (optional)
  midi.sendNoteOn(60, 100);
  debugBlink(1);
}