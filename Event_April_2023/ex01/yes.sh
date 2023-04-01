#!/usr/bin/env bash

YES=true

while [ $YES ]
do
	ls . | grep '^yes.sh$' | cut -d '.' -f 1
done
