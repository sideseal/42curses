#!/bin/bash

if [ "$1" = "jot" ]; then
	generate="1"
elif [ "$1" = "seq" ]; then
	generate="2"
else
	echo "Usage: ./tester.sh <jot | seq>" >&2
	exit 1
fi

if ! command -v ./PmergeMe &> /dev/null
then
	echo "error: Program(PmergeMe) not exist" >&2
	exit 1
fi

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

for ((a = 1, c = 1; a <= 3002;)); do
	if [ "$c" -gt 100000 ]; then
		c=100000
	fi

	if [ "$a" -gt 3000 ]; then
		a=3000
	fi

	if [ "$generate" -eq 1 ]; then
		args=$(jot -r $a 1 $c | tr '\n' ' ')
	elif [ "$generate" -eq 2 ]; then
		args=$(seq 1 $a | sort -R)
	fi

	result=$(./PmergeMe $args 1>/dev/null)

	if [ "$?" -eq 1 ]; then
		echo "$args"
		echo "${RED}KO${RESET}"
		exit 1
	else
		if [ "$generate" -eq 1 ]; then
			echo "[jot -r $a 1 $c]: ${GREEN}OK${RESET}"
		elif [ "$generate" -eq 2 ]; then
			echo "[seq 1 $a | sort -R]: ${GREEN}OK${RESET}"
		fi
	fi

	if [ "$a" -eq 3000 ]; then
		./PmergeMe $args
		break
	fi

	if [ "$a" -le 999 ]; then
		((a++))
		if [ "$generate" -eq 1 ]; then
			((c+=1))
		fi
	else
		((a+=11))
		if [ "$generate" -eq 1 ]; then
			((c+=a))
		fi
	fi
done

echo "${GREEN}Test done!${RESET}"
