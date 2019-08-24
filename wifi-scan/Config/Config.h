/** @module Config_h
 *  @since 2019.08.23, 21:31
 *  @changed 2019.08.23, 21:31
 */

#ifndef _Config_h_
#define _Config_h_

#include "Constants.h"

// Singleton class
class Config {

  // Singleton...
  private: static Config* __singleton;

  public: // Common config variables...

  static Config singleton();

  int menuColor = MENU_COLOR;

  int menuFontSize = 2;

};

#endif // _Config_h_
