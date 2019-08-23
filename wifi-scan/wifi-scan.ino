#include <M5Stack.h>
#include "WiFi.h"
#include <String.h>

extern unsigned char IconClock60w[];
extern unsigned char IconWifi60w[];
extern unsigned char IconCounterSm60w[];

#define MENU_COLOR GREENYELLOW

int networksCount;
int ssidLength = 12;
int thisPage = 0;
const int pageSize = 8;
bool showMenu = false;
bool leftLocked = false;
bool rightLocked = false;

void LCD_Clear() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  // M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextColor(LIGHTGREY);
  M5.Lcd.setTextSize(2);
}

void DrawMenu(){
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(MENU_COLOR);

  if (showMenu == true) {
    M5.Lcd.setCursor(125, 215);
    M5.Lcd.printf("Rescan");
    if (thisPage != 0) {
      M5.Lcd.setCursor(60, 215);
      M5.Lcd.printf("<");
      leftLocked = false;
    }
    else {
      leftLocked = true;
    }
    if (thisPage < ((networksCount - 1) / pageSize)) {
      M5.Lcd.setCursor(250, 215);
      M5.Lcd.printf(">");
      rightLocked = false;
    }
    else {
      rightLocked = true;
    }
  }
  else {
    M5.Lcd.setCursor(135, 215);
    M5.Lcd.printf("Scan");
  }
}

void Show(int nav = 0) { // -1 top, 1 bottom
  if (nav == -1) {
    if ((showMenu == true) && (leftLocked == false)) {
      thisPage--;
      if (thisPage < 0) thisPage = 0;
      Show();
    }
  }
  else if (nav == 1) {
    if ((showMenu == true) && (rightLocked == false)) {
      if ((thisPage) <= (networksCount / pageSize)) thisPage++;
      Show();
    }
  }
  else {
    LCD_Clear();
    M5.Lcd.setCursor(100, 5);
    M5.Lcd.setTextColor(DARKGREY);
    M5.Lcd.print("Total: ");
    M5.Lcd.setTextColor(LIGHTGREY);
    M5.Lcd.print(networksCount);
    for (int y = 35, i = (thisPage * pageSize); i < ((thisPage * pageSize) + pageSize); i++, y += 22) {
      if (i >= networksCount) break;
      M5.Lcd.setCursor(10, y);
      M5.Lcd.setTextColor(DARKGREY);
      M5.Lcd.print(String(i + 1) + ". ");
      String ssid = WiFi.SSID(i);
      ssid = (ssid.length() > ssidLength) ? (ssid.substring(0, ssidLength) + "...") : ssid;
      M5.Lcd.setCursor(55, y);
      M5.Lcd.setTextColor(WHITE);
      // M5.Lcd.print(ssid + " (" + WiFi.RSSI(i) + ")\n");
      M5.Lcd.print(ssid);
      M5.Lcd.setCursor(270, y);
      M5.Lcd.setTextColor(DARKGREY);
      int strength = WiFi.RSSI(i);
      M5.Lcd.print(String(strength));
    }
    DrawMenu();
  }
}

void Search() {
  showMenu = true;
  LCD_Clear();
  M5.Lcd.drawBitmap(30, 85, 60, 60, (uint16_t *)IconClock60w);
  M5.Lcd.setCursor(110, 95);
  M5.Lcd.printf("Please, wait.");
  M5.Lcd.setCursor(110, 125);
  M5.Lcd.printf("Searching...");
  networksCount = WiFi.scanNetworks();
  Show();
}

// cppcheck-suppress unusedFunction
void setup() {
  M5.begin();
  Serial.begin(9600);
  Serial.println("Start");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  M5.Lcd.setBrightness(10);
  M5.Lcd.drawBitmap(30, 85, 60, 60, (uint16_t *)IconWifi60w);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(110, 110);
  M5.Lcd.printf("Wi-Fi scanner");
  DrawMenu();
}

// cppcheck-suppress unusedFunction
void loop() {
  if (M5.BtnA.wasPressed()) Show(-1);
  if (M5.BtnB.wasPressed()) Search();
  if (M5.BtnC.wasPressed()) Show(1);
  M5.update();
}
