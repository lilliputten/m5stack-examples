/** @module Config.cpp
 *  @since 2019.08.23, 21:31
 *  @changed 2019.08.23, 21:31
 */

#include "Config.h"

// Uninitialized singleton instance reference
Config* Config::config = 0;

// Get or create singleton instance reference
Config* Config::getConfig() {
  if (Config::config == 0) {
    Config::config = new Config();
  }
  return Config::config;
}

// Config::Config(void) {
//  // cout << "Object is being created" << endl;
// }
