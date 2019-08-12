#include "Module.h"

int subTest() {
  return 10;
};

int Module::test() {
  int subResult = subTest(); // this->subTest();
  int result = subResult + 5;
  return result;
};

// Module module;
