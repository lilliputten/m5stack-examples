// Demo based on:
// UTFT_Demo_320x240 by Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
/*

 This sketch uses the GLCD and font 2 only.

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

#include <M5Stack.h>

// #define BUTTON_A_PIN 39
// #define BUTTON_B_PIN 38
// #define BUTTON_C_PIN 37

#define TFT_GREY 0x7BEF

unsigned long runTime = 0;
int demoDelay = 5000;
int buttonWaitingDelay = 100;

// cppcheck-suppress unusedFunction
void setup() {

  randomSeed(analogRead(0xA0));

  // Setup the LCD
  M5.begin();
  // M5.Lcd.setRotation(1);

  Serial.begin(9600);
  Serial.println("Start");

  Serial.println("BUTTON_A_PIN: " + String(BUTTON_A_PIN));

}

void printHeader(String str) {
  int bgColor = TFT_GREY;
  int fgColor = TFT_YELLOW;
  M5.Lcd.fillRect(0, 0, 319, 14, bgColor);
  M5.Lcd.setTextColor(fgColor, bgColor);
  M5.Lcd.drawCentreString(str, 160, 4, 1);
}

void printFooter(String str) {
  int bgColor = TFT_RED;
  int fgColor = TFT_BLACK;
  M5.Lcd.fillRect(0, 226, 319, 14, bgColor);
  M5.Lcd.setTextColor(fgColor, bgColor);
  M5.Lcd.drawCentreString(str, 160, 228, 1);
}
void printInfoAndWait(String str) {
  printHeader(str);
  printFooter("Press any button");
  // delay(demoDelay);
  waitForAnyButton();
}

/* // UNUSED
 * bool button(int contactNumber) {
 *   if (digitalRead(contactNumber) == LOW) {
 *     delay(10);
 *     if (digitalRead(contactNumber) == LOW) return true;
 *   }
 *   return false;
 * }
 * void waitForButton(int contactNumber) {
 *   while (true) {
 *     if (digitalRead(contactNumber) == LOW) {
 *       return;
 *     }
 *     delay(buttonWaitingDelay);
 *   }
 * }
 */

int waitForAnyButton() {
  int Buttons[] = {
    BUTTON_A_PIN,
    BUTTON_B_PIN,
    BUTTON_C_PIN
  };
  Serial.println("Buttons.size: " + String(sizeof(Buttons)));
  int pressed = 0;
  // Wait for button press
  while (!pressed) {
    for (int i = 0; i < 3 && !pressed; i++) {
      int test = Buttons[i];
      if (digitalRead(test) == LOW) {
        pressed = test;
        break;
      }
    }
    delay(buttonWaitingDelay);
  }
  // Wait for button release
  if (pressed) {
    while (true) {
      if (digitalRead(pressed) != LOW) {
        return pressed;
      }
      delay(buttonWaitingDelay);
    }
  }
  return 0;
}

// cppcheck-suppress unusedFunction
void loop() {
  randomSeed(millis());
  //randomSeed(1234); // This ensure test is repeatable with exact same draws each loop
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  runTime = millis();

  // Clear the screen and draw the frame
  M5.Lcd.fillScreen(TFT_BLACK);

  printHeader("TFT Demo");

  M5.Lcd.drawRect(0, 14, 319, 211, TFT_BLUE);

  // Draw crosshairs
  M5.Lcd.drawLine(159, 15, 159, 224,TFT_BLUE);
  M5.Lcd.drawLine(1, 119, 318, 119,TFT_BLUE);
  for (int i=9; i<310; i+=10)
    M5.Lcd.drawLine(i, 117, i, 121,TFT_BLUE);
  for (int i=19; i<220; i+=10)
    M5.Lcd.drawLine(157, i, 161, i,TFT_BLUE);

  // Draw sin-, cos- and tan-lines
  M5.Lcd.setTextColor(TFT_CYAN);
  M5.Lcd.drawString("Sin", 10, 20, 1);
  for (int i=1; i<318; i++) {
    M5.Lcd.drawPixel(i,119+(sin(((i*1.13)*3.14)/180)*95),TFT_CYAN);
  }
  M5.Lcd.setTextColor(TFT_RED);
  M5.Lcd.drawString("Cos", 10, 35, 1);
  for (int i=1; i<318; i++) {
    M5.Lcd.drawPixel(i,119+(cos(((i*1.13)*3.14)/180)*95),TFT_RED);
  }
  M5.Lcd.setTextColor(TFT_YELLOW);
  M5.Lcd.drawString("Tan", 10, 50, 1);
  for (int i=1; i<318; i++) {
    M5.Lcd.drawPixel(i,119+(tan(((i*1.13)*3.14)/180)),TFT_YELLOW);
  }

  printInfoAndWait("Sin, Cos, Tan");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  M5.Lcd.drawLine(159, 15, 159, 224,TFT_BLUE);
  M5.Lcd.drawLine(1, 119, 318, 119,TFT_BLUE);

  int col = 0;
  // Draw a moving sinewave
  x=1;
  for (int i=1; i<(317*20); i++) {
    x++;
    if (x==318)
      x=1;
    if (i>318) {
      if ((x==159)||(buf[x-1]==119))
        col = TFT_BLUE;
      else
        M5.Lcd.drawPixel(x,buf[x-1],TFT_BLACK);
    }
    y=119+(sin(((i*1.1)*3.14)/180)*(90-(i / 100)));
    M5.Lcd.drawPixel(x,y,TFT_BLUE);
    buf[x-1]=y;
  }

  printInfoAndWait("Moving sinewave");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some filled rectangles
  for (int i=1; i<6; i++) {
    switch (i)
    {
      case 1:
        col = TFT_MAGENTA;
        break;
      case 2:
        col = TFT_RED;
        break;
      case 3:
        col = TFT_GREEN;
        break;
      case 4:
        col = TFT_BLUE;
        break;
      case 5:
        col = TFT_YELLOW;
        break;
    }
    M5.Lcd.fillRect(70+(i*20), 30+(i*20), 60, 60,col);
  }

  printInfoAndWait("Filled rectangles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some filled, rounded rectangles
  for (int i=1; i<6; i++) {
    switch (i)
    {
      case 1:
        col = TFT_MAGENTA;
        break;
      case 2:
        col = TFT_RED;
        break;
      case 3:
        col = TFT_GREEN;
        break;
      case 4:
        col = TFT_BLUE;
        break;
      case 5:
        col = TFT_YELLOW;
        break;
    }
    M5.Lcd.fillRoundRect(190-(i*20), 30+(i*20), 60,60, 3,col);
  }

  printInfoAndWait("Filled rounded rectangles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some filled circles
  for (int i=1; i<6; i++) {
    switch (i)
    {
      case 1:
        col = TFT_MAGENTA;
        break;
      case 2:
        col = TFT_RED;
        break;
      case 3:
        col = TFT_GREEN;
        break;
      case 4:
        col = TFT_BLUE;
        break;
      case 5:
        col = TFT_YELLOW;
        break;
    }
    M5.Lcd.fillCircle(100+(i*20),60+(i*20), 30,col);
  }

  printInfoAndWait("Filled circles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some lines in a pattern

  for (int i=15; i<224; i+=5) {
    M5.Lcd.drawLine(1, i, (i*1.44)-10, 223,TFT_RED);
  }

  for (int i=223; i>15; i-=5) {
    M5.Lcd.drawLine(317, i, (i*1.44)-11, 15,TFT_RED);
  }

  for (int i=223; i>15; i-=5) {
    M5.Lcd.drawLine(1, i, 331-(i*1.44), 15,TFT_CYAN);
  }

  for (int i=15; i<224; i+=5) {
    M5.Lcd.drawLine(317, i, 330-(i*1.44), 223,TFT_CYAN);
  }

  printInfoAndWait("Lines in a pattern");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some random circles
  for (int i=0; i<100; i++) {
    x=32+random(256);
    y=45+random(146);
    r=random(30);
    M5.Lcd.drawCircle(x, y, r,random(0xFFFF));
  }

  printInfoAndWait("Random circles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some random rectangles
  for (int i=0; i<100; i++) {
    x=2+random(316);
    y=16+random(207);
    x2=2+random(316);
    y2=16+random(207);
    if (x2<x) {
      r=x;x=x2;x2=r;
    }
    if (y2<y) {
      r=y;y=y2;y2=r;
    }
    M5.Lcd.drawRect(x, y, x2-x, y2-y,random(0xFFFF));
  }

  printInfoAndWait("Random rectangles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // Draw some random rounded rectangles
  for (int i=0; i<100; i++) {
    x=2+random(316);
    y=16+random(207);
    x2=2+random(316);
    y2=16+random(207);
    // We need to get the width and height and do some window checking
    if (x2<x) {
      r=x;x=x2;x2=r;
    }
    if (y2<y) {
      r=y;y=y2;y2=r;
    }
    // We need a minimum size of 6
    if((x2-x)<6) x2=x+6;
    if((y2-y)<6) y2=y+6;
    M5.Lcd.drawRoundRect(x, y, x2-x,y2-y, 3,random(0xFFFF));
  }

  printInfoAndWait("Random rounded rectangles");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

 //randomSeed(1234);
 for (int i=0; i<100; i++) {
    x = 2+random(316);
    y = 16+random(209);
    x2 = 2+random(316);
    y2 = 16+random(209);
    int colour = random(0xFFFF);
    M5.Lcd.drawLine(x, y, x2, y2, colour);
  }

  printInfoAndWait("Random lines");

  M5.Lcd.fillRect(1,15,317,209,TFT_BLACK);

  // This test has been modified as it takes more time to calculate the random numbers
  // than to draw the pixels (3 seconds to produce 30,000 randoms)!
  for (int i=0; i<10000; i++) {
    M5.Lcd.drawPixel(2+random(316), 16+random(209),random(0xFFFF));
  }

  // Draw 10,000 pixels to fill a 100x100 pixel box
  // use the coords as the colour to produce the banding
  //byte i = 100;
  //while (i--) {
  //  byte j = 100;
  //  while (j--) M5.Lcd.drawPixel(i+110,j+70,i+j);
  //  //while (j--) M5.Lcd.drawPixel(i+110,j+70,0xFFFF);
  //}

  printInfoAndWait("Random points");

  M5.Lcd.fillScreen(TFT_BLUE);
  M5.Lcd.fillRoundRect(80, 70, 239-80,169-70, 3,TFT_RED);

  M5.Lcd.setTextColor(TFT_WHITE,TFT_RED);
  M5.Lcd.drawCentreString("That's all!", 160, 93, 2);
  M5.Lcd.drawCentreString("Press any button", 160, 119, 2);
  M5.Lcd.drawCentreString("to repeat", 160, 132, 2);
  // M5.Lcd.drawCentreString("Restarting in a", 160, 119,2);
  // M5.Lcd.drawCentreString("few seconds...", 160, 132,2);

  runTime = millis() - runTime;
  M5.Lcd.setTextColor(TFT_GREEN,TFT_BLUE);
  M5.Lcd.drawCentreString("Runtime: " + String(runTime) + " ms", 160, 290, 3);
  // M5.Lcd.setTextDatum(TC_DATUM);
  // M5.Lcd.drawNumber(runTime, 160, 225,2);

  printInfoAndWait("Done");

  // delay(demoDelay);

}
