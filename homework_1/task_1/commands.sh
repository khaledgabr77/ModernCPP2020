#!/bin/bash

#Prints the number of lines in a file
#wc -l ./data.dat
cat data.dat | wc -l

#prints the number of line contian "", "" in a file
#grep -E "dolor|dalor" ./data.dat
((grep dolor data.dat) || (grep dalor data.dat)) | wc -l

#prints the number of words in a file
#wc -w ./data.dat
cat data.dat | wc -w

#print the number of word starting with "mol" in file
#grep -c mol ./data.dat
cat -n data.dat | grep mol | wc -w 

