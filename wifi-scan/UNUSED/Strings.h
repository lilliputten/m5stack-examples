/** @module Strings_h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Strings_h_
#define _Strings_h_

// #include <Arduino.h>
// #include <M5Stack.h>
#include <WString.h>

#include "Config.h"

// Singleton class
class Strings {

  private:

    // Singleton instance reference
    static Strings* _strings;

    // const char *items[];

  public:

    Strings();

    // Singleton getter
    static Strings* singleton();

    // void setItems(const char *pointer[]);

    // int wasClicked();

};

#endif // _Strings_h_
// vim: ft=arduino
