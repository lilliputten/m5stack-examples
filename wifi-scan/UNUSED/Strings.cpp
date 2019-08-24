/** @module Strings_cpp
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Strings_cpp_
#define _Strings_cpp_

#include "Strings.h"

// Uninitialized singleton instance reference
Strings* Strings::_strings = 0;

// Get or create singleton instance reference
Strings* Strings::singleton() {
  if (Strings::_strings == 0) {
    Strings::_strings = new Strings();
  }
  return Strings::_strings;
}

Strings::Strings(void) {
  // cout << "Object is being created" << endl;
}

#endif // _Strings_cpp_
// vim: ft=arduino
