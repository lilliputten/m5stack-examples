/** @module Menu.cpp
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#include "Menu.h"

// Uninitialized singleton instance reference
Menu* Menu::menu = 0;

// Get or create singleton instance reference
Menu* Menu::getMenu() {
  if (Menu::menu == 0) {
    Menu::menu = new Menu();
  }
  return Menu::menu;
}

Menu::Menu(void) {
  // cout << "Object is being created" << endl;
}
