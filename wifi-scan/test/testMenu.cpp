/** @module testMenuContainer
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

#include "../Menu/MenuContainer.cpp"
#include "../Menu/Menu.cpp"

// const char *pointer[] = { "uno", "due",  "due", "xxx", };
// const int pointerSize = (sizeof(pointer)/sizeof(*pointer));

const String menuStr = "uno|due|tri";

Config config = Config::singleton();

// MenuContainer menu;
// Menu* menu = new Menu();
Menu menu = Menu::singleton();

int main() {
  Serial.println("testMenu::main: config.menuColor: " + String(config.menuColor, 16));
  String str = String(menuStr);
  Serial.println("testMenu::main: menuStr: " + str);
  menu.setItems(menuStr);
  // String firstText = menu->getItemText(0);
  // cout << "firstText: " << firstText.c_str() << endl;
  return 0;
}
