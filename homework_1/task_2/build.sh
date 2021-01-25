#!/usr/bin/env bash

clang++ -c -Iinclude/ src/sum.cpp -o build/sum.o 
clang++ -c -Iinclude/ src/subtract.cpp -o build/subtract.o

ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

clang++ -Iinclude/ src/main.cpp -o main -Lbuild/ -lipb_arithmetic 

mv main results/bin/ 