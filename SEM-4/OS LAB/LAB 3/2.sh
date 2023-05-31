#!/bin/bash

echo "Enter pattern"
read pattern

echo "Enter location"
read location

echo `grep -L $pattern $location`