/** @module Menu_h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Menu_h_
#define _Menu_h_

#ifdef ESP32
// #include <M5Stack.h>
// #include <WString.h>
#include <utility/ILI9341_Defines.h> // Color definitions
#endif

#include "MenuContainer.h"

#include "../Interactive/Interactive.h"

#define MENU_HEIGHT 21
#define MENU_BG_COLOR BLACK
// #define MENU_BG_COLOR MAROON
#define MENU_TEXT_COLOR GREENYELLOW
#define MENU_ARROWS_COLOR LIGHTGREY
#define MENU_MAX_ITEM_LENGTH 18
#define MENU_FONT_SIZE DEFAULT_FONT_SIZE
#define MENU_H_OFFSET 5

#define DEFAULT_MENU_ID "defaultMenu"

class Menu: public Interactive {

  // Singleton...
  private: static Menu* __singleton;
  public: static Menu singleton();

  private:

    MenuContainer menuContainer;

  public:

    Menu();
    explicit Menu(String id);
    Menu(String id, String items, int active = 0);

    virtual String getId();

    // void setItems(String str);
    virtual void setItems(String str, int active = 0);

    virtual void render();

    virtual int wasPressed();
    virtual int pollButtons();

};

#endif // _Menu_h_
