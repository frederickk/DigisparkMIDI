/**
 * Jan Ostman
 * Janost 2019 Sweden
 * DIY USB MIDI to Sync
 * http://blog.dspsynth.eu/diy-usb2din-sync/
 *
 * Copyright 2019 DSP Synthesizers Sweden.
 *
 * Updated to include user modifiable trigger interval.
 * Ken Frederick
 * ken.frederick@gmx.de
 *
 * (*) All in the spirit of open-source and open-hardware
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <DigiMIDI.h>;

// These pins values are hard coded into DigiMIDI.h usbFunctionWriteOut().
#define CLOCK_OUT_PIN 1
#define NOTE_OUT_PIN 5


DigiMIDIDevice midi;


void setup() {
  pinMode(CLOCK_OUT_PIN, OUTPUT);
  pinMode(NOTE_OUT_PIN, OUTPUT);

  digitalWrite(CLOCK_OUT_PIN, LOW);
  digitalWrite(NOTE_OUT_PIN, LOW);

  // Default trigger interval is 24 (quarter notes), but
  // for Pocket Operators and Volcas, use 12 (eighth notes).
  midi.setClockTriggerInterval(12);
}

void loop() {
  midi.update();
}