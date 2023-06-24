#!/bin/bash

if [ $# -eq 0 ];
then
  echo "$0: Missing arguments"
  exit 1
elif [ $# -gt 2 ];
then
  echo "$0: Too many arguments: $@"
  exit 1
elif [ ! -d $1 ];
then
  echo "$1 directory does not exist"
  exit 1
else
	echo "The number of files are $(grep -Rl "$1" -e "$2" | wc -l) and the number of matching lines are $(grep -R "$1" -e "$2" | wc -l)"
fi
