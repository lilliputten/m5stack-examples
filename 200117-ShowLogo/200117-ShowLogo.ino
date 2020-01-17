#include <M5Stack.h>
#include "m5_logo.h"

void setup() {
  M5.begin();
  M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoM5);
}

void loop() {
}
