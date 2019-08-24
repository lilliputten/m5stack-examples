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

#define WIDTH 320
#define HEIGHT 240
#define SCREEN_H_CENTER_POS 160
#define SCREEN_V_CENTER_POS 120
#define SCREEN_V_MENU_POS 215
#define SCREEN_DEFAULT_FONT 1

#define MENU_COLOR GREENYELLOW
#define DEFAULT_FONT_SIZE 2
#define MENU_FONT_SIZE DEFAULT_FONT_SIZE

#endif // _Constants_h_
