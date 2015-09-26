# DigisparkMIDI

## Library for [Digispark](http://digistump.com/products/) (and clones) Attiny85 and Attiny 135 boards that allows for it to function as a HID-MIDI device.

Based on V-MIDI-HID [cryptomys.de/horo/V-USB-MIDI/](http://cryptomys.de/horo/V-USB-MIDI/)

Tested and working On:
- MacNook MacOS 10.10.5
- MacBook MacOS 10.14.5
- iPhone 6 iOS 9.0.0


---
### Installing

**Digispark boards**

If you haven't already, be sure to follow the directions from Digispark on "[Connecting and Programming Your Digispark](https://digistump.com/wiki/digispark/tutorials/connecting)". Once you've done that move on to installing this library.


**Library installation**
Click the "Clone or Download" button and click "Download ZIP". and install with [Arduino](https://www.arduino.cc/en/Guide/Libraries#toc4) via "Sketch > Include Library > Add .ZIP Library..."

Alternatively you can clone this repo directly into the appropriate folder.

```bash
# For MacOS, this is the default library location
$ cd ~/Documents/Arduino/Libraries
$ git clone https://github.com/frederickk/DigisparkMIDI/
$ echo "et voilà!"
```

Then restart the Arduino IDE. The included examples will appear under "Examples > DigisparkMIDI" and you're good to go!


---
### API

```cpp
DigiMIDIDevice.update()
```
This should be called in a sketch's main loop. We need this to poll our interface<br><br>

```cpp
DigiMIDIDevice.sendNoteOn(int key, int velocity, uchar channel)
```
Sends note on (`0x90`) message, with a default velocity of `100` by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendNoteOff(int key, int velocity, uchar channel)
```
Sends note off (`0x80`) message, with a default velocity of `0` by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendProgramChange(int inProgramNumber, uchar channel)
```
Sends program change (`0xC0`) message, by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendControlChange(int inControlNumber, int inControlValue, uchar channel)
```
Sends control change (`0xB0`) message, with a default control value of `0` by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendPolyPressure(int inNoteNumber, int inPressure, uchar channel)
```
Sends poly pressure (`0xB0`) message, by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendAfterTouch(int inPressure, uchar channel)
```
Sends after touch (`0xD0`) message, by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.sendPitchBend(int|double inPitchValue, uchar channel)
```
Sends pitch bend (`0xE0`) message, by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.getStatus(byte inType, byte inChannel)
```
Get status of any MIDI message, by default on channel `1`.<br><br>

```cpp
DigiMIDIDevice.setClockTriggerInterval(uint8_t interval)
```
Change the analog trigger interval for pulses sent to clock out (pin `1`), default is `24` (quarter notes).<br><br>



---
### Examples

A number of [examples](./examples) are included with the library to show some of it's functionality.

**digimidi-analog-sync**

This example is taken nearly verbatim from the [Jan Ostman's](http://blog.dspsynth.eu/diy-usb2din-sync/). It takes a clock signal from a [USB Midi host](https://www.midi.org/articles-old/basic-of-usb) and ouput an analog pulse on pin `1`. Also, this example has been updated to allow for user customizeable clock trigger interval via `midi.setClockTriggerInterval(uint8_t)`.<br><br>


**digimidi-blink**

This example is the "blink" equivalent for Midi, it sends a `60` (middle C) every `500` milliseconds (and blinks the LED on `PB1`).<br><br>


**digimidi-button**

This example shows how you might integrate a momentary button to cycle through different trigger intervals. If you wanted to sync different devices with different pulse interval e.g. Volcas/Pocket Operators sync on the eighth note (`12`) whereas other devices sync on the quarter note (`24`). Included is a simple library for handling button debouncing, etc.<br><br>

**digimidi-test**

This is the original test example that is a more complex blink example.


---
### License

Based on Obdev's [AVRUSB](https://github.com/obdev/v-usb) code and under the same license. See [License.txt](./License.txt) for details.
