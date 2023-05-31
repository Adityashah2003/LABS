#!/bin/bash 

echo "Enter basics"
read basic

echo "Enter TA"
read ta

echo `echo "$basic + $ta + $basic*0.1" | bc -l`

