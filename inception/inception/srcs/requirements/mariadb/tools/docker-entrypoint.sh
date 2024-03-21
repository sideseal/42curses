#!/bin/sh

set -ex

MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD:-""}
MYSQL_DATABASE=${MYSQL_DATABASE:-""}
MYSQL_USER=${MYSQL_USER:-""}
MYSQL_PASSWORD=${MYSQL_PASSWORD:-""}

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

if [ "$MYSQL_ROOT_PASSWORD" = "" ]; then
    echo >&2 'error: MYSQL_ROOT_PASSWORD not set'
    return 1
fi

tmpfile=`mktemp`
if [ ! -f $tmpfile ]; then
    echo >&2 'error: mktemp failed'
    return 1
fi

cat << EOF > $tmpfile
    USE mysql;
    FLUSH PRIVILEGES;
    ALTER USER root@localhost IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    GRANT ALL ON *.* TO root@localhost IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
    DROP DATABASE IF EXISTS test;
    
    CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
    
    CREATE USER IF NOT EXISTS $MYSQL_USER@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
    ALTER USER $MYSQL_USER@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
    GRANT ALL ON $MYSQL_DATABASE.* TO $MYSQL_USER@'%' IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;
    FLUSH PRIVILEGES;
EOF

/usr/bin/mariadbd --user=mysql --datadir=/var/lib/mysql --bootstrap < $tmpfile
rm -f $tmpfile

echo 'Starting MariaDB Container...'

exec /usr/bin/mariadbd --user=mysql --datadir=/var/lib/mysql --console $@