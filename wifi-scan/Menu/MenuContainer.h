/** @module MenuContainer_h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _MenuContainer_h_
#define _MenuContainer_h_

#ifdef ESP32
// #include <Arduino.h>
// #include <M5Stack.h>
#include <WString.h>
#endif

#define MAX_MENU_ITEMS 20

class MenuContainer {

  private:

    String itemsStr;

    // Items array
    String itemTexts[MAX_MENU_ITEMS];

    // Items array actual length
    int itemsCount;

    // Current active item
    int activeItem;

  public:

    MenuContainer();

    void setItems(String str, int active);
    void setItems(String str);
    int getItemsCount();
    String getItemsStr();
    int getActiveItem();
    String getItemText(int no);

};

#endif // _MenuContainer_h_
