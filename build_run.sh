#!/bin/bash

echo "Delete main.exe if it exists"
rm main

echo "Compile main (doubly_linked_list.cpp)"
g++ doubly_linked_list.cpp -o main 

echo "Running main (doubly_linked_list.cpp)"
echo "===================================="
./main