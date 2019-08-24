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
void Menu::setItems(String str, int active) {
  menuContainer.setItems(str, active);
}

void Menu::display() {
  M5.Lcd.fillRect(0, SCREEN_LAST_Y - MENU_HEIGHT, SCREEN_LAST_X, SCREEN_LAST_Y, MENU_BG_COLOR);
  int itemsCount = menuContainer.getItemsCount();
  if (itemsCount <= 0) {
    return;
  }
  int activeItem = menuContainer.getActiveItem();
  // Draw active menu item...
  String text = (activeItem >= 0 && activeItem < itemsCount) ? menuContainer.getItemText(activeItem) : "";
  text = (text.length() >= MENU_MAX_ITEM_LENGTH) ? (text.substring(0, MENU_MAX_ITEM_LENGTH - 3) + "...") : text;
  M5.Lcd.setTextColor(MENU_TEXT_COLOR);
  M5.Lcd.setTextSize(MENU_FONT_SIZE);
  int yTextPos = SCREEN_LAST_Y - MENU_HEIGHT + 2;
  M5.Lcd.drawCentreString(text, SCREEN_CENTER_X, yTextPos, DEFAULT_FONT);
  // Draw arrows...
  int yArrowsPos = yTextPos + 1;
  M5.Lcd.setTextColor(MENU_ARROWS_COLOR);
  if (activeItem > 0) {
    M5.Lcd.drawString("<", MENU_H_OFFSET, yArrowsPos, DEFAULT_FONT);
  }
  if (activeItem < itemsCount - 1) {
    M5.Lcd.drawRightString(">", SCREEN_LAST_X - MENU_H_OFFSET, yArrowsPos, DEFAULT_FONT);
  }
}

#endif // _Menu_cpp_
