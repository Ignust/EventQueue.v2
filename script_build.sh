#!/bin/bash

rm -rf build/
mkdir build && cd build
cmake .. && make -j8

echo "start EventQueue.v2 ------------------------------------------------------------------" 
#mv EventQueue.v2 ../EventQueue.v2
./EventQueue.v2
