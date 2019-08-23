CXX ?= c++

# flags #
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g
INCLUDES = -IC:/M5Stack/libraries/M5Stack/src

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

