/** @module Constants_h
 *  @since 2019.08.23, 21:31
 *  @changed 2019.08.23, 21:31
 */

#ifndef _Constants_h_
#define _Constants_h_

#ifdef ESP32
// #include <Arduino.h>
// #include <M5Stack.h>
#include <utility/ILI9341_Defines.h> // Color definitions
#endif

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_LAST_X 319
#define SCREEN_LAST_Y 239
#define SCREEN_H_CENTER 160
#define SCREEN_V_CENTER 120
#define SCREEN_CENTER_X 159
#define SCREEN_CENTER_Y 119
#define SCREEN_V_MENU_POS 215
#define DEFAULT_FONT 1

#define MENU_COLOR GREENYELLOW
#define DEFAULT_FONT_SIZE 2

#endif // _Constants_h_
