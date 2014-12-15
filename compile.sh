#!/bin/bash
# This script contains the g++ command to compile this c++ string project. Do not move this script from the projects directory.
# Compiling does not include the warning messages. You will need g++ in order to compile this project.

echo "Starting to compile the project. Wait..."
g++ -w main.cpp mystring.h mystring.cpp testclass.h testclass.cpp -o mystringtest
echo "Project compiled. Now you can run the program with command ./mystringtest."
