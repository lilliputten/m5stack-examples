/** @module MenuContainer_cpp
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _MenuContainer_cpp_
#define _MenuContainer_cpp_

#include "MenuContainer.h"

MenuContainer::MenuContainer(void) {
  this->itemsCount = 0;
  this->activeItem = 0;
}

void MenuContainer::setItems(String str, int active) {
  this->itemsStr = str; // Save original string
  this->activeItem = active; // Set active item
  this->itemsCount = 0; // Reset items count
  int len = str.length();
  int pos = 0;
  while (pos < len) {
    int next = str.indexOf('|', pos);
    if (next == -1) {
      next = len;
    }
    String text = str.substring(pos, next);
    #ifdef DEBUG
    Serial.println("MenuContainer::setItems: [" + String(this->itemsCount) + "] " + String(pos) + "-" + String(next) + ": " + text);
    #endif
    pos = next + 1;
    this->itemTexts[this->itemsCount++] = text;
  }
  // #ifdef DEBUG
  // Serial.println("MenuContainer::setItems: itemsCount: " + String(this->itemsCount));
  // #endif
}
void MenuContainer::setItems(String str) {
  this->setItems(str, 0);
}

int MenuContainer::getItemsCount() {
  return itemsCount;
}

int MenuContainer::getActiveItem() {
  return activeItem;
}

String MenuContainer::getItemText(int no) {
  return (no >= 0 && no < itemsCount) ? itemTexts[no] : "";
}

#endif // _MenuContainer_cpp_
