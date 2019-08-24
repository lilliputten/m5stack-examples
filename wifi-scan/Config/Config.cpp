/** @module Config_cpp
 *  @since 2019.08.23, 21:31
 *  @changed 2019.08.23, 21:31
 */

#ifndef _Config_cpp_
#define _Config_cpp_

#include "Config.h"

Config* Config::__singleton = 0;
Config Config::singleton() { // Singleton...
  if (Config::__singleton == 0) Config::__singleton = new Config();
  return *Config::__singleton;
}

#endif // _Config_cpp_
