#!/bin/sh
# This is a comment!
echo cmake is called followd by the make command and finally the compiled programm is executed        # This is a comment, too!
#cmake . -G "Visual Studio 10 Win64"
cmake .
make
cd build
./runTests 
