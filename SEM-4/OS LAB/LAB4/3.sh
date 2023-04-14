#!/bin/bash

n=$#
arr=($*)
echo "Array Before sorting: "${arr[*]}
for ((i=0;i<$n;i++))
do
    for ((j=0;j<n-i;j++))
    do
        if [[ ${arr[j]} > ${arr[$((j+1))]} ]]
        then
            temp=${arr[j]}
            arr[j]=${arr[$((j+1))]}
            arr[$((j+1))]=$temp
        fi
    done
done
echo "Array after sorting: "${arr[*]}
