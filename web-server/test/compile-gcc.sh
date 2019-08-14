#!/bin/sh
rm -f a && c++ -v test-module.cpp && echo "-- DONE --" && ls -la && a
