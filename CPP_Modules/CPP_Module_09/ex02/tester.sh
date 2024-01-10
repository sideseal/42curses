#!/bin/bash

if ! command -v ./PmergeMe &> /dev/null
then
	echo "error: Program(PmergeMe) not exist" >&2
	exit 1
fi

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

for ((a = 1, c = 1; a <= 3000;)); do
	if [ "$c" -gt 100000 ]; then
		c=100000
	fi

	args=$(jot -r $a 1 $c | tr '\n' ' ')

	result=$(./PmergeMe $args 1>/dev/null)

	if [ "$?" -eq 1 ]; then
		echo "$args"
		echo "${RED}KO${RESET}"
		exit 1
	else
		echo "[jot -r $a 1 $c]: ${GREEN}OK${RESET}"
	fi

	if [ "$a" -le 999 ]; then
		((a++))
		((c+=1))
	else
		((a+=10))
		((c+=a))
	fi
done

echo "${GREEN}Test done!${RESET}"
