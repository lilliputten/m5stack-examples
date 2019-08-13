#include <iostream>
using namespace std;

// #include <cstdlib>
// #include <string>

#include "../Module.cpp"

Module module;

int main() {
  int test = module.test();
  // string sTest = to_string(test);
  cout << "Test: " << test;
  return 0;
}
