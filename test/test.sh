#!/usr/bin/env bash

if [ "$1" == "" ]; then
	echo "Add input filename as parameter"
	exit 1
fi


APP=./sorter/sorter
INPUT=$1
ALGORITHMS=("bubble" "selection" "insertion" "shell" "quick-right" "quick-rand" "merge" "heap" "counting")

for algorithm in ${ALGORITHMS[*]}; do
	echo "$algorithm:"
	cat $INPUT | $APP $algorithm
	echo ""
done

