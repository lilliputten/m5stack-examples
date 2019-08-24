/** @module Menu_cpp
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Menu_cpp_
#define _Menu_cpp_

#include "Menu.h"

#include "MenuContainer.cpp"

Menu* Menu::__singleton = 0; Menu Menu::singleton() {
// Singleton...
  if (Menu::__singleton == 0) Menu::__singleton = new Menu();
  return *Menu::__singleton;
}

Menu::Menu(void) {
  // menuContainer = new MenuContainer();
}

void Menu::setItems(String str) {
  menuContainer.setItems(str);
}

#endif // _Menu_cpp_
