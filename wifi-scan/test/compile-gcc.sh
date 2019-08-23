#!/bin/sh
rm -f a \
  && c++ \
  -IC:/M5Stack/libraries/M5Stack/src \
  -v testConfig.cpp \
  && echo "-- DONE --" \
  && ls -la \
  && echo "-- RUN --" \
  && ./a.exe
  # && sleep 1 \
