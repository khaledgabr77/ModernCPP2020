#!/bin/bash


clang++ -c -I include/ src/sum.cpp -o build/sum.o 
clang++ -c -I include/ src/subtract.cpp -o build/subtract.o

cd /home/khaled/Desktop/ModernCPP2020/homework_1/task_2/build


ar rcs libipb_arithmetic.a sum.o subtract.o

clang++ ../src/main.cpp -L . - libipb_arithmetic.a -o main

