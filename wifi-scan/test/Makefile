# @module Makefile
# @since 2019.08.23, 21:47
# @changed 2019.08.23, 21:47
# @see [GNU make: Special Targets](https://www.gnu.org/software/make/manual/html_node/Special-Targets.html)

CXX ?= c++

# flags #
# COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g
COMPILE_FLAGS = -Wall -Wextra -g
INCLUDES =
# INCLUDES = -IC:/M5Stack/libraries/M5Stack/src \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/cores/esp32/
#   -IC:/Users/User/AppData/Local/Arduino15/packages/esp32/hardware/esp32/1.0.2/cores/esp32 \
#   -IC:/Users/User/AppData/Local/Arduino15/packages/esp32/hardware/esp32/1.0.2/variants/m5stack_core_esp32 \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/freertos/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/config/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/esp32/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/soc/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/heap/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/driver/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/tools/sdk/include/log/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/libraries/Wire/src/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/libraries/SPI/src/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/libraries/FS/src/ \
#   -IC:/ArduinoEsp32/hardware/esp32/1.0.2/libraries/SD/src/ \
#   \

# SRC_EXT = cpp
# DST_EXT = exe

SRC_PATH = .

# PROGS = \
#   testConfig

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%.exe,$(SRCS))

all: $(PROGS)

%.exe: %.cpp
	@echo "-- Compiling: $< -> $@ --"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@
	@echo "-- Running: $@ --"
	@./$@

# .DEFAULT_GOAL := default
# default:
#   @echo "default target"

clean :
	@echo "-- Cleaning... --"
	@rm -f *.exe

