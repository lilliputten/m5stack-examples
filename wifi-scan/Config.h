/** @module Config.h
 *  @since 2019.08.23, 21:31
 *  @changed 2019.08.23, 21:31
 */

#ifndef _Config_
#define _Config_

// #include <Arduino.h>
// #include <M5Stack.h>
#include <utility/ILI9341_Defines.h>

#include "Constants.h"

// Singleton class
class Config {

  private:

    // Singleton instance reference
    static Config* config;

  public:

    // Config();

    // Singleton getter
    static Config* getConfig();

    // Common config variables...

    int menuColor = MENU_COLOR;
    int menuFontSize = 2;

};

#endif // _Config_
// vim: ft=arduino
