/**
 * MomentaryButton.h
 *
 * Class for handling momentary button inputs.
 *
 * ken.frederick@gmx.de
 * http://kenfrederick.de/
 *
 * License:
 * https://opensource.org/licenses/MIT
 */

#ifndef _MOMENTARY_BUTTON
#define _MOMENTARY_BUTTON


#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


class MomentaryButton {
  private:
    uint8_t buttonPin_;

    byte state_;
    byte statePrev_;

    uint16_t lastDebounceTime_;
    uint16_t debounceDelay_;

  public:
    MomentaryButton(uint8_t buttonPin = 7) {
      buttonPin_ = buttonPin;
      statePrev_ = LOW;
      lastDebounceTime_ = 0;
      debounceDelay_ = 100;
    }

    // Deconstructor
    ~MomentaryButton() {
    }

    /**
     * Init/setup pins.
     */
    void init() {
      pinMode(buttonPin_, INPUT_PULLUP);
    }

    /**
     * Return state of button.
     */
    byte get() {
      uint8_t currentState = digitalRead(buttonPin_);

      if (currentState != statePrev_) {
        lastDebounceTime_ = millis();
      }

      if ((millis() - lastDebounceTime_) > debounceDelay_) {
        if (currentState != state_) {
          state_ = currentState;
          if (state_ == HIGH) {
            return state_;
          }
        }
      }

      statePrev_ = currentState;

      return 0;
    }

};



#endif
