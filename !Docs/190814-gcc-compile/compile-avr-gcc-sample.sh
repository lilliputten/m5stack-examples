#!/bin/sh
avr-g++ -mmcu=atmega328p -DARDUINO=105 -DF_CPU=16000000L \
    -I/usr/share/arduino/hardware/arduino/cores/arduino \
    -I/usr/share/arduino/hardware/arduino/variants/standard \
    -Os -fno-exceptions -ffunction-sections -fdata-sections \
    -Wl,--gc-sections -g -Wall -Wextra \
    -x c++ -include Arduino.h \
    /usr/share/arduino/examples/01.Basics/Blink/Blink.ino \
    -x none /usr/local/lib/arduino/uno/libcore.a -lm \
    -o Blink.elf