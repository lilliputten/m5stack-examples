/** @module Menu_cpp
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Menu_cpp_
#define _Menu_cpp_

#include "Menu.h"

#include "../Interactive/Interactive.cpp"

#include "MenuContainer.cpp"

// Singleton...
Menu* Menu::__singleton = 0; Menu Menu::singleton() {
  if (Menu::__singleton == 0) Menu::__singleton = new Menu("singletonMenu");
  return *Menu::__singleton;
}

Menu::Menu(void) : Interactive(DEFAULT_MENU_ID) {
}
Menu::Menu(String id) : Interactive(id) {
}
Menu::Menu(String id, String items, int active) : Interactive(id) {
  this->setItems(items, active);
}

// void Menu::setItems(String str) {
//   this->menuContainer.setItems(str);
// }
void Menu::setItems(String str, int active) {
  this->menuContainer.setItems(str, active);
}

String Menu::getId() {
  String id = Interactive::getId();
  String itemsStr = this->menuContainer.getItemsStr();
  if (itemsStr != "") {
    id += ":[" + itemsStr + "]";
  }
  return id;
}

void Menu::render() {
  #ifdef ESP32
    M5.Lcd.fillRect(0, SCREEN_LAST_Y - MENU_HEIGHT, SCREEN_LAST_X, SCREEN_LAST_Y, MENU_BG_COLOR);
    int itemsCount = this->menuContainer.getItemsCount();
    if (itemsCount <= 0) {
      return;
    }
    int activeItem = this->menuContainer.getActiveItem();
    // Draw active menu item...
    String text = (activeItem >= 0 && activeItem < itemsCount) ? this->menuContainer.getItemText(activeItem) : "";
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
  #endif
}

int Menu::wasPressed() {
  int pressed = Interactive::wasPressed();
  String id = this->getId();
  Serial.println("Menu::wasPressed: (" + id + "): Button code: " + String(pressed));
  return pressed;
}

int Menu::pollButtons() {

  // Get pressed status
  int buttonPressed = Interactive::pollButtons();

  // #ifdef DEBUG // Test mode...
  //   String id = this->getId();
  //   Serial.println("Menu::pollButtons(" + id + "): " + String(buttonPressed));
  // #endif

  // Return current status
  return buttonPressed;

}


#endif // _Menu_cpp_
