#!/bin/sh
# This is a comment!
echo ---- Build the framework and link it against the application, start the gtest and execute the application.
#cmake . -G "Visual Studio 10 Win64"
rm fw/build/runTests
rm app/build/application
cmake .
make
cd fw/build
./runTests
cd ../../app/build
./application

