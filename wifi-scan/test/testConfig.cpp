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
