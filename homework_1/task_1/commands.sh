#!/bin/bash

#Prints the number of lines in a file
wc -l ./data.dat

#prints the number of line contian "", "" in a file
grep -E "dolor|dalor" ./data.dat

#prints the number of words in a file
wc -w ./data.dat


#print the number of word starting with "mol" in file
grep -c mol ./data.dat


