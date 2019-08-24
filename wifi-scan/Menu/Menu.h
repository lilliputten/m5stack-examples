/** @module Menu_h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Menu_h_
#define _Menu_h_

#ifdef ESP32
// #include <Arduino.h>
// #include <M5Stack.h>
// #include <WString.h>
#endif

#include "MenuContainer.h"

#define MENU_HEIGHT 22
// #define MENU_BG_COLOR

// Singleton class
class Menu {

  // Singleton...
  private: static Menu* __singleton;
  public: static Menu singleton();

  private:

    MenuContainer menuContainer;

  public:

    Menu();

    void setItems(String str);
    void display();

    // int wasClicked();

};

#endif // _Menu_h_
