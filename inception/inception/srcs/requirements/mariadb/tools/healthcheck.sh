#!/bin/sh

set -ex

mariadb-admin ping -h localhost -uroot -p${MYSQL_ROOT_PASSWORD} || exit 1