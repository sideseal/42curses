#!/bin/sh

echo "Cleaning data..."

rm -rf ./blog/mariadb
rm -rf ./blog/wordpress

mkdir -p ./blog/mariadb
mkdir -p ./blog/wordpress && chmod 777 ./blog/wordpress

echo "Finish!"
