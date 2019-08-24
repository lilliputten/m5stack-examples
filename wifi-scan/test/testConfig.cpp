/** @module testConfig
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#include <iostream>
using namespace std;

// #include <cstdlib>
// #include <string>

#include "../Config.cpp"

int main() {
  const Config* config = Config::getConfig();
  cout << "config: " << config << std::endl;
  int menuColor = config->menuColor;
  cout << "menuColor: " << menuColor << std::endl;
  return 0;
}

// vim: ft=arduino
