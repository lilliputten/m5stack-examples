// vim: set fdm=syntax

#include <M5Stack.h>

/** Info & docs:
 *
 * @see http://forum.m5stack.com/topic/51/lesson-4-2-1-io-ports-the-brightness-of-the-fire
 *
 * List 1. Analog functions for ESP32
 *
 *   - ledcSetup(uint8_t c, uint8_t f, uint8_t r); Sets the number of the channel c, frequency f (Hz) and resolution r (8 bits) for PWM
 *   - ledcAttachPin(uint8_t p, uint8_t c); Assigns the contact p to the channel c
 *   - ledcWrite(uint8_t C, uint8_t d); Sets the value of the filling signal d on channel c
 *   - ledcRead(uint8_t c); Gets the value of the PWM signal of the c channel
*/

int pwmChannel = 1;
int ledPin = 21;
int ledState = 0;
int ledIncrement = 5;
int delayValue = 500;

// cppcheck-suppress unusedFunction
void setup() {

  M5.begin();

  Serial.begin(9600);
  Serial.println("Start");

  M5.Lcd.setBrightness(10);

  ledcSetup(pwmChannel, 10000, 8);
  ledcAttachPin(ledPin, pwmChannel);
  pinMode(ledPin, OUTPUT);

  M5.Lcd.println("Ready");

}

// cppcheck-suppress unusedFunction
void loop() {

  // if (M5.BtnA.isPressed()) {
  if (digitalRead(BUTTON_A_PIN) == LOW) {
    ledState += ledIncrement;
    if (ledState > 255) {
      ledState = 255;
    }
    String s = "Button A -> " + String(ledState);
    M5.Lcd.println(s);
    Serial.println(s);
    ledcWrite(pwmChannel, ledState);
    delay(delayValue);
  }
  // if (M5.BtnB.isPressed()) {
  if (digitalRead(BUTTON_B_PIN) == LOW) {
    ledState -= ledIncrement;
    if (ledState < 1) {
      ledState = 0;
    }
    String s = "Button B -> " + String(ledState);
    M5.Lcd.println(s);
    Serial.println(s);
    ledcWrite(pwmChannel, ledState);
    delay(delayValue);
  }

  /* Simple test:
   * ledcWrite(pwmChannel, 0x55);
   * delay(250);
   * ledcWrite(pwmChannel, 0xaa);
   * delay(250);
   * ledcWrite(pwmChannel, 0xff);
   * delay(250);
   */

}
