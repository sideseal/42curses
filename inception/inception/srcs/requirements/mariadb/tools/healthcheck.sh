#!/bin/sh

set -ex

# 그냥 밖으로 빼도 괜찮을 것 같은데 일단 나중에...
mariadb-admin ping -h localhost -uroot -p${MYSQL_ROOT_PASSWORD} || exit 1