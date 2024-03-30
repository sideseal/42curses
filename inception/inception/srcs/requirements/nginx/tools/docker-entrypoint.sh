#!/bin/sh

set -ex

sed -i.bak \
    -e 's|access_log /var/log/nginx/access.log main;|access_log /dev/stdout main;|g' \
    -e 's|error_log /var/log/nginx/error.log warn;|error_log /dev/stderr notice;|g' \
    -e 's|ssl_protocols TLSv1.1 TLSv1.2 TLSv1.3;|ssl_protocols TLSv1.2 TLSv1.3;|g' \
    /etc/nginx/nginx.conf

echo 'Starting Nginx Container...'

exec nginx -g 'daemon off;' $@