#!/bin/bash 

echo "Enter extension"
read ext

echo "Enter folder"
read fol

#result=`find . -name "$ext"`
result=`find . -maxdepth 1 -name "*$ext"`
mkdir $fol

for i in $result
do 
    mv $i $fol
done
