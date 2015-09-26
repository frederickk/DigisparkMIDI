#include <DigiMIDI.h>

// These pins values are hard coded into DigiMIDI.h usbFunctionWriteOut().
#define CLOCK_OUT_PIN 1
#define NOTE_OUT_PIN 5


DigiMIDIDevice midi;


void setup() {
  // pinMode(0, OUTPUT); // LED on Model B
  // pinMode(1, OUTPUT); // LED on Model A
  pinMode(CLOCK_OUT_PIN, OUTPUT);
  pinMode(NOTE_OUT_PIN, OUTPUT);

  digitalWrite(CLOCK_OUT_PIN, LOW);
  digitalWrite(NOTE_OUT_PIN, LOW);
}

void loop() {
  midi.update();

  midi.sendNoteOn(60, 0);
  delay(500);

  midi.sendNoteOff(60, 0);
  delay(500);
}
