#!/bin/bash

file=$1
pattern=$2

# for ((value=2; value<=$#; value++))
# do
#     pattern+="\|${!value}"
# done

while (true)
do
    echo "1. Search the patterns within the file"
    echo "2. Delete the patterns from the file"
    echo "3. Exit"
    read choice
    case $choice in
        1) grep -i $pattern $file ;;
        2) for i
           do   
               sed -e s/$i//g $file > text.txt
               mv text.txt $file
           done;;
        3) exit 0;;
    esac
done