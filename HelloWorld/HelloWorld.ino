#include <M5Stack.h>

// the setup routine runs once when M5Stack starts up
// cppcheck-suppress unusedFunction
void setup() {

  // Initialize the M5Stack object
  M5.begin();

  // LCD display
  M5.Lcd.print("Hello World");

}

// the loop routine runs over and over again forever
// cppcheck-suppress unusedFunction
void loop() {
}
