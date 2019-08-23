/** @module Menu.h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Menu_
#define _Menu_

// #include <Arduino.h>
// #include <M5Stack.h>

#include "Config.h"

struct MenuItem {
  int id;
  String text;
};

// Singleton class
class Menu {

  private:

    MenuItem[]

    // Singleton instance reference
    static Menu* menu;

  public:

    Menu();

    // Singleton getter
    static Menu* getMenu();

    // int wasClicked();

};

#endif // _Menu_
// vim: ft=arduino
