#!/bin/sh
# @version 2019.05.08, 20:08

PACKAGESPATH="$USERPROFILE/AppData/Local/Arduino15/packages"
echo $PACKAGESPATH
# exit

ESP32TOOLSPATH="$PACKAGESPATH/esp32/tools"
ARDUINOPATH="C:/Arduino"
BUILDER="$ARDUINOPATH/arduino-builder"
LIBS="D:/Work/M5Stack/Projects/libraries"

BUILDPATH="./build"
CACHEPATH="$BUILDPATH"

mkdir -p "$CACHEPATH"
mkdir -p "$BUILDPATH"

echo "Cache path: $CACHEPATH"
echo "Build path: $BUILDPATH"

# $BUILDER -dump-prefs -logger=machine -hardware $ARDUINOPATH/hardware -hardware $PACKAGESPATH -tools $ARDUINOPATH/tools-builder -tools $ARDUINOPATH/hardware/tools/avr -tools $PACKAGESPATH -built-in-libraries $ARDUINOPATH/libraries -libraries $LIBS -fqbn=esp32:esp32:m5stack-core-esp32:FlashMode=qio,FlashFreq=80,PartitionScheme=default,UploadSpeed=921600,DebugLevel=none -vid-pid=10C4_EA60 -ide-version=10809 -build-path "$BUILDPATH" -warnings=none -build-cache "$CACHEPATH" -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.xtensa-esp32-elf-gcc.path=$ESP32TOOLSPATH/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.xtensa-esp32-elf-gcc-1.22.0-80-g6c4433a-5.2.0.path=$ESP32TOOLSPATH/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.esptool_py.path=$ESP32TOOLSPATH/esptool_py/2.6.1 -prefs=runtime.tools.esptool_py-2.6.1.path=$ESP32TOOLSPATH/esptool_py/2.6.1 -prefs=runtime.tools.mkspiffs.path=$ESP32TOOLSPATH/mkspiffs/0.2.3 -prefs=runtime.tools.mkspiffs-0.2.3.path=$ESP32TOOLSPATH/mkspiffs/0.2.3 -verbose $1

$BUILDER -compile -logger=machine -hardware $ARDUINOPATH/hardware -hardware $PACKAGESPATH -tools $ARDUINOPATH/tools-builder -tools $ARDUINOPATH/hardware/tools/avr -tools $PACKAGESPATH -built-in-libraries $ARDUINOPATH/libraries -libraries $LIBS -fqbn=esp32:esp32:m5stack-core-esp32:FlashMode=qio,FlashFreq=80,PartitionScheme=default,UploadSpeed=921600,DebugLevel=none -vid-pid=10C4_EA60 -ide-version=10809 -build-path "$BUILDPATH" -warnings=none -build-cache "$CACHEPATH" -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.xtensa-esp32-elf-gcc.path=$ESP32TOOLSPATH/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.xtensa-esp32-elf-gcc-1.22.0-80-g6c4433a-5.2.0.path=$ESP32TOOLSPATH/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.esptool_py.path=$ESP32TOOLSPATH/esptool_py/2.6.1 -prefs=runtime.tools.esptool_py-2.6.1.path=$ESP32TOOLSPATH/esptool_py/2.6.1 -prefs=runtime.tools.mkspiffs.path=$ESP32TOOLSPATH/mkspiffs/0.2.3 -prefs=runtime.tools.mkspiffs-0.2.3.path=$ESP32TOOLSPATH/mkspiffs/0.2.3 -verbose $1

