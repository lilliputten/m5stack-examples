/** @module wifi-scan
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.24, 04:39
 */

#define DEBUG // Display debug info to Serial line

#define INTERACTIVE_LOOP_DELAY 100 // Buttons polling interval (ms; ie -- buttons responsibility)

#include <M5Stack.h>
#include <WiFi.h>
// #include <String.h>

// Icons...
#include "Icons/IconClock60w.c";
#include "Icons/IconWifi60w.c";
#include "Icons/IconCounterSm60w.c";

#include "Config/Config.cpp"
#include "Menu/Menu.cpp"

#include "Interactive/Interactive.cpp"
#include "InteractiveStack/InteractiveStack.cpp"

// Global variables (TO REFACTOR!)

int networksCount;
int ssidLength = 12;
int thisPage = 0;
const int pageSize = 8;
bool showMenu = false; // Show full menu flag
bool leftLocked = false;
bool rightLocked = false;

// XXX STOPPED 2019.08.24, 05:25 -- Process menu buttons (wasPressed?) + Parse menu item id's.

Config config = Config::singleton();

InteractiveStack interactiveStack = InteractiveStack::singleton();

const String mainMenuId = "mainMenu";
const String mainMenuButtons = "Scan|Duo|Tri|Four";

Menu* mainMenu = new Menu(mainMenuId, mainMenuButtons);

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
  showMenu = true; // Display full menu
  LCD_Clear();
  M5.Lcd.drawBitmap(30, 85, 60, 60, (uint16_t *)IconClock60w);
  M5.Lcd.setCursor(110, 95);
  M5.Lcd.printf("Please, wait.");
  M5.Lcd.setCursor(110, 125);
  M5.Lcd.printf("Searching...");
  networksCount = WiFi.scanNetworks();
  thisPage = 0; // Reset page
  Show();
}

// cppcheck-suppress unusedFunction
void setup() {

  M5.begin();
  Serial.begin(9600);
  // Serial.begin(115200);
  Serial.println("Start");

  try {

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

    interactiveStack.push(mainMenu);
    interactiveStack.lastRender();
    interactiveStack.lastPollButtons();

  }
  catch (const std::overflow_error& error) { // this executes if f() throws std::overflow_error (same type rule)
    Serial.println("Overflow error: " + String(error.what()));
  }
  catch (const std::runtime_error& error) { // this executes if f() throws std::underflow_error (base class rule)
    Serial.println("Runtime error: " + String(error.what()));
  }
  catch (const std::exception& error) { // this executes if f() throws std::logic_error (base class rule)
    Serial.println("Exception error: " + String(error.what()));
  }
  catch (const String& error) { // this executes if f() throws std::logic_error (base class rule)
    Serial.println("Error: " + error);
  }
  catch (...) { // this executes if f() throws std::string or int or any other unrelated type
    Serial.println("Unknown error ");
  }

  // menu.setItems(mainMenuButtons);
  // menu.render();
  DrawMenu();
}

// cppcheck-suppress unusedFunction
void loop() {

  try {
    // int size = interactiveStack.getSize();
    // Serial.println("stack size: " + String(size));
    // Interactive* last = interactiveStack.getLast();
    // unsigned long lastAddr = (unsigned long) last;
    // Serial.println("lastAddr: " + String(lastAddr, 16));
    // unsigned long menuAddr = (unsigned long) mainMenu;
    // Serial.println("menuAddr: " + String(menuAddr, 16));
    // String menuId = mainMenu->getId();
    // Serial.println("mainMenuId: " + menuId);
    // String lastId = last->getId();
    // Serial.println("lastId: " + lastId);
    mainMenu->pollButtons();
    // interactiveStack.lastPollButtons();
  }
  catch (const std::overflow_error& error) { // this executes if f() throws std::overflow_error (same type rule)
    Serial.println("Overflow error: " + String(error.what()));
  }
  catch (const std::runtime_error& error) { // this executes if f() throws std::underflow_error (base class rule)
    Serial.println("Runtime error: " + String(error.what()));
  }
  catch (const std::exception& error) { // this executes if f() throws std::logic_error (base class rule)
    Serial.println("Exception error: " + String(error.what()));
  }
  catch (const String& error) { // this executes if f() throws std::logic_error (base class rule)
    Serial.println("Error: " + error);
  }
  catch (...) { // this executes if f() throws std::string or int or any other unrelated type
    Serial.println("Unknown error");
  }

  delay(INTERACTIVE_LOOP_DELAY);

  // TODO 2019.08.26, 23:35 -- Test buttons, try w/o delay...

  /*
   * if (M5.BtnA.wasPressed()) {
   *   Serial.println("Test: A button pressed");
   * }
   */
  if (M5.BtnA.wasPressed()) Show(-1);
  if (M5.BtnB.wasPressed()) Search();
  if (M5.BtnC.wasPressed()) Show(1);

  M5.update();
}
