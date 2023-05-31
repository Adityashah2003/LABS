#!/bin/bash 

result=`find . -name "*.txt"`
for i in $result 
do
    mv $i ${i%.txt}.text
done
