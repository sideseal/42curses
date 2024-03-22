#!/bin/sh

set -ex

echo 'Starting Nginx Container...'

exec nginx -g 'daemon off;' $@