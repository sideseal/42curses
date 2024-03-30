#!/bin/sh

set -ex

mariadb-admin ping -h 172.21.42.40 -u${WORDPRESS_DB_USER} -p${WORDPRESS_DB_PASSWORD} || exit 1