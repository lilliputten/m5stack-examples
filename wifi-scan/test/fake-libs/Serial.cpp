/** @module Serial_cpp
 *  @since 2019.08.24, 03:30
 *  @changed 2019.08.24, 03:30
 */

#ifndef _Serial_cpp_
#define _Serial_cpp_

#include <iostream>
#include <string>

using namespace std;

#include "Serial.h"

void SERIAL::begin(int speed) {
  // noop
}

void SERIAL::print(String str) {
  cout << str.c_str();
}
void SERIAL::println(String str) {
  cout << str.c_str() << endl;
}

#endif // _Serial_cpp_
