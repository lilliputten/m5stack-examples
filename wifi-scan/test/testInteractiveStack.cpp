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
  Menu menu1("menu1");
  // Interactive menu1("menu1");
  interactiveStack.push(&menu1);
  Serial.println("size1: " + String(interactiveStack.getSize()));
  Interactive* active = interactiveStack.getActive();
  active->pollButtons();
  String activeId = active ? active->getId() : "null";
  Serial.println("active interactive: " + activeId);
  interactiveStack.pop();
  Serial.println("size2: " + String(interactiveStack.getSize()));
  // String firstText = interactiveStack->getItemText(0);
  // cout << "firstText: " << firstText.c_str() << endl;
  return 0;
}
