#include <M5Stack.h>
// #include "m5_logo.h"
#include "image-2x2-04.c"

void setup() {
  M5.begin();
  // M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoM5);
  M5.Lcd.drawBitmap(0, 0, 2, 2, (uint16_t *)image_data_image2x2);
}

void loop() {
}
