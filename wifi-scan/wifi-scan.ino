/** @module wifi-scan
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.24, 04:39
 */

#define DEBUG // Display debug info to Serial line

#include <M5Stack.h>
#include <WiFi.h>
// #include <String.h>

// Icons...
#include "Icons/IconClock60w.c";
#include "Icons/IconWifi60w.c";
#include "Icons/IconCounterSm60w.c";

#include "Config/Config.cpp"
#include "Menu/Menu.cpp"

// XXX STOPPED 2019.08.24, 05:25 -- Process menu buttons (wasPressed?) + Parse menu item id's.

Config config = Config::singleton();
Menu menu = Menu::singleton();

// Global variables (TO REFACTOR!)

int networksCount;
int ssidLength = 12;
int thisPage = 0;
const int pageSize = 8;
bool showMenu = false;
bool leftLocked = false;
bool rightLocked = false;

// #define ARRAYSIZE 10
const String mainMenu = "Scan|Duo|Tri|Four";

void LCD_Clear() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  // M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextColor(LIGHTGREY);
  M5.Lcd.setTextSize(DEFAULT_FONT_SIZE);
}

void DrawMenu(){
  M5.Lcd.setTextSize(DEFAULT_FONT_SIZE);
  M5.Lcd.setTextColor(config.menuColor);

  if (showMenu == true) {
    // M5.Lcd.setCursor(125, 215);
    // M5.Lcd.printf("Rescan");
    M5.Lcd.drawCentreString("Rescan", SCREEN_H_CENTER, SCREEN_V_MENU_POS, DEFAULT_FONT);
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
    // M5.Lcd.setCursor(135, 215);
    // M5.Lcd.printf("Scan");
    M5.Lcd.drawCentreString("Scan", SCREEN_H_CENTER, SCREEN_V_MENU_POS, DEFAULT_FONT);
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
    // M5.Lcd.setCursor(100, 5);
    // M5.Lcd.print("Total: ");
    // M5.Lcd.setTextColor(LIGHTGREY);
    // M5.Lcd.print(networksCount);
    M5.Lcd.setTextColor(LIGHTGREY);
    M5.Lcd.drawCentreString("Total: " + String(networksCount), SCREEN_H_CENTER, 5, DEFAULT_FONT);
    for (int y = 35, i = (thisPage * pageSize); i < ((thisPage * pageSize) + pageSize); i++, y += 22) {
      if (i >= networksCount) break;
      M5.Lcd.setTextColor(DARKGREY);
      // M5.Lcd.setCursor(10, y);
      // M5.Lcd.print(String(i + 1) + ". ");
      M5.Lcd.drawString(String(i + 1), 10, y, DEFAULT_FONT);
      String ssid = WiFi.SSID(i);
      ssid = (ssid.length() > ssidLength) ? (ssid.substring(0, ssidLength) + "...") : ssid;
      M5.Lcd.setTextColor(WHITE);
      // M5.Lcd.print(ssid + " (" + WiFi.RSSI(i) + ")\n");
      // M5.Lcd.setCursor(55, y);
      // M5.Lcd.print(ssid);
      M5.Lcd.drawString(ssid, 55, y, DEFAULT_FONT);
      M5.Lcd.setTextColor(DARKGREY);
      int strength = WiFi.RSSI(i);
      // M5.Lcd.print(String(strength));
      // M5.Lcd.setCursor(270, y);
      M5.Lcd.drawRightString(String(strength), 310, y, DEFAULT_FONT);
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
  // M5.Lcd.setTextSize(DEFAULT_FONT_SIZE);
  // M5.Lcd.setCursor(110, 110);
  // M5.Lcd.print("Wi-Fi scanner: " + String(pointerSize));
  M5.Lcd.setTextColor(LIGHTGREY);
  M5.Lcd.setTextSize(DEFAULT_FONT_SIZE);
  M5.Lcd.drawString("Wi-Fi scanner", 110, 110, DEFAULT_FONT);

  menu.setItems(mainMenu);
  menu.display();
  // DrawMenu();
}

// cppcheck-suppress unusedFunction
void loop() {
  if (M5.BtnA.wasPressed()) Show(-1);
  if (M5.BtnB.wasPressed()) Search();
  if (M5.BtnC.wasPressed()) Show(1);
  M5.update();
}
