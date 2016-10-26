#!/bin/sh
# This is a comment!
echo cmake is called followd by the make command and finally the compiled programm is executed        # This is a comment, too!
cmake .
make
cd build
./runTests 
