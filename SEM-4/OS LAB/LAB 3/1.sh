#!/bin/bash

arg=$1

if [ -d "${arg}" ]; then 
    echo "It is directory"
else 
    if [ -f "${arg}" ]; then 
        echo "It is a file"
    else
        echo "It is not a file"
        exit 1
    fi
fi 