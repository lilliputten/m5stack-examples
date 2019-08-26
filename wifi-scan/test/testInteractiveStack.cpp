/** @module testInteractiveStackContainer
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

// #define ESP32

#define DEBUG

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "used-libs/ILI9341_Defines.h" // Color definitions

#include "used-libs/stdlib_noniso.h" // stdlib extensions
#include "used-libs/WString.h" // String class

#include "used-libs/stdlib_noniso.c"
#include "used-libs/WString.cpp"

#include "fake-libs/Serial.cpp" // Serial debug stdout emualtion

#include "../Config/Config.cpp"

#include "../Menu/Menu.cpp"
#include "../Interactive/Interactive.cpp"
#include "../InteractiveStack/InteractiveStack.cpp"

// const char *pointer[] = { "uno", "due",  "due", "xxx", };
// const int pointerSize = (sizeof(pointer)/sizeof(*pointer));

Config config = Config::singleton();

// InteractiveStack* interactiveStack = new InteractiveStack();
InteractiveStack interactiveStack = InteractiveStack::singleton();

int main() {

  // Create interactive menu instance...
  Menu menu1("menu1", "btn1|btn2");
  // Interactive menu1("menu1");

  // Add menu to stack
  interactiveStack.push(&menu1);
  Serial.println("size1: " + String(interactiveStack.getSize()));

  // Get last interactive instance from stack
  Interactive* last = interactiveStack.getLast();
  // Get last item id
  String lastId = last ? last->getId() : "null";
  Serial.println("last interactive id: " + lastId);

  // // Call overrided interactive methods
  // last->pollButtons();
  // last->wasPressed();

  // Call last interactive methods

  int lastPollButtons = interactiveStack.lastPollButtons();
  Serial.println("lastPollButtons: " + String(lastPollButtons));

  int lastWasPressed1 = interactiveStack.lastWasPressed();
  Serial.println("lastWasPressed1: " + String(lastWasPressed1));

  // // Test to create overrided interactive class...
  // // Menu* ptr = &menu1;
  // Interactive* ptr = &menu1;
  // ptr->wasPressed();

  // Remove last interactive handler...
  interactiveStack.pop();
  Serial.println("size2: " + String(interactiveStack.getSize()));

  int lastWasPressed2 = interactiveStack.lastWasPressed();
  Serial.println("lastWasPressed2: " + String(lastWasPressed2));

  return 0;
}
