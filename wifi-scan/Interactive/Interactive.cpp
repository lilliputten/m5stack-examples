/** @module Interactive_cpp
 *  @since 2019.08.26, 20:03
 *  @changed 2019.08.26, 20:03
 */

#ifndef _Interactive_cpp_
#define _Interactive_cpp_

#include "Interactive.h"

/* // Singleton
 * Interactive* Interactive::__singleton = 0; Interactive Interactive::singleton() { // Singleton...
 *   if (Interactive::__singleton == 0) Interactive::__singleton = new Interactive();
 *   return *Interactive::__singleton;
 * }
 */

// Interactive::Interactive(void) {
//   this->init();
// }
Interactive::Interactive(String id = "") {
  this->init();
  this->setId(id);
}

void Interactive::init() {
  this->enabled = true;
  this->buttonPressed = NO_BTN;
}

void Interactive::setEnabled(bool enabled) {
  this->enabled = enabled;
}
bool Interactive::getEnabled() {
  return this->enabled;
}
void Interactive::enable() {
  this->setEnabled(true);
}
void Interactive::disable() {
  this->setEnabled(false);
}

void Interactive::setId(String id) {
  this->id = id;
}
String Interactive::getId() {
  return this->id;
}

int Interactive::wasPressed() {
  return this->buttonPressed;
}

void Interactive::pollButtons() {
  #ifdef ESP32 // Arduino build...
    this->buttonPressed = NO_BTN;
    #if defined(DEBUG)
      String btnId;
    #endif
    if (this->enabled) {
      if (M5.BtnA.wasPressed()) {
        this->buttonPressed = BTN_A;
        #if defined(DEBUG)
          btnId = "A";
        #endif
      }
      else if (M5.BtnB.wasPressed()) {
        this->buttonPressed = BTN_B;
        #if defined(DEBUG)
          btnId = "B";
        #endif
      }
      else if (M5.BtnC.wasPressed()) {
        this->buttonPressed = BTN_C;
        #if defined(DEBUG)
          btnId = "C";
        #endif
      }
      #if defined(DEBUG)
        if (this->buttonPressed != NO_BTN) {
          String id = this->getId();
          Serial.println("Interactive::pollButtons(" + id + "): Pressed button " + btnId + " (" + String(this->buttonPressed) + ")");
        }
      #endif
    }
  #else // Test mode...
    String id = this->getId();
    Serial.println("Interactive::pollButtons(" + id + "): Test mode");
  #endif
}

#endif // _Interactive_cpp_
