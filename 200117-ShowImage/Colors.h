// @see ILI9341_Defines.h, Color-Samples.c
// Color mode: Color R5G6B5
// RGB565 <-> RGB888 ???
// - [Rinky-Dink Electronics](http://www.rinkydinkelectronics.com/t_imageconverter565.php)
// - [Help converting RGB565 to RGB888](https://forum.arduino.cc/index.php?topic=285303.0)
// - [RGB8888 to RGB565 pixel format conversion - Graphics and GPU Programming - GameDev.net](https://www.gamedev.net/forums/topic/385638-rgb8888-to-rgb565-pixel-format-conversion/)

#define BLACK               0x0000      /*   0   0   0 */
#define NAVY                0x000F      /*   0   0 128 */
#define DARKGREEN           0x03E0      /*   0 128   0 */
#define DARKCYAN            0x03EF      /*   0 128 128 */
#define MAROON              0x7800      /* 128   0   0 */
#define PURPLE              0x780F      /* 128   0 128 */
#define OLIVE               0x7BE0      /* 128 128   0 */
#define LIGHTGREY           0xC618      /* 192 192 192    ->    1100,0110,0001,1000 */
#define DARKGREY            0x7BEF      /* 128 128 128    ->    0111,1011,1110,1111 */
#define BLUE                0x001F      /*   0   0 255    ->    0000,0000,0001,1111 */
#define GREEN               0x07E0      /*   0 255   0    ->    0000,0111,1110,0000 */
#define CYAN                0x07FF      /*   0 255 255 */
#define RED                 0xF800      /* 255   0   0    ->    1111,1000,0000,0000 */
#define MAGENTA             0xF81F      /* 255   0 255 */
#define YELLOW              0xFFE0      /* 255 255   0    ->    1111,1111,1110,0000 */
#define WHITE               0xFFFF      /* 255 255 255 */
#define ORANGE              0xFD20      /* 255 165   0 */
#define GREENYELLOW         0xAFE5      /* 173 255  47 */
#define PINK                0xF81F
