#!/bin/sh

set -ex

MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD:-""}
MYSQL_DATABASE=${MYSQL_DATABASE:-""}
MYSQL_USER=${MYSQL_USER:-""}
MYSQL_PASSWORD=${MYSQL_PASSWORD:-""}

if [ "$MYSQL_ROOT_PASSWORD" = "" ]; then
    echo >&2 'error: MYSQL_ROOT_PASSWORD is not set'
    return 1
fi

tmpfile=`mktemp`
if [ ! -f $tmpfile ]; then
    echo >&2 'error: mktemp failed'
    return 1
fi

createDatabase=
createUser=
grantPrivileges=

if [ "$MYSQL_DATABASE" != "" ]; then
    createDatabase="CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
fi

if [ "$MYSQL_USER" != "" ]; then
    if [ "$MYSQL_PASSWORD" = "" ]; then
        echo >&2 'error: MYSQL_USER is specified but MYSQL_PASSWORD is not set'
        return 1
    else
        createUser="CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
        ALTER USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    fi
fi

if [ "$MYSQL_DATABASE" != "" ] && [ "$MYSQL_USER" != "" ]; then
    grantPrivileges="GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;"
fi

cat <<-EOF > $tmpfile  
    FLUSH PRIVILEGES;
    ALTER USER root@localhost IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    GRANT ALL ON *.* TO root@localhost IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
    DROP DATABASE IF EXISTS test;
    $createDatabase
    $createUser
    $grantPrivileges
    FLUSH PRIVILEGES;
EOF

/usr/bin/mariadbd --user=mysql --bootstrap < $tmpfile
rm -f $tmpfile

echo 'Starting MariaDB Container...'

exec /usr/bin/mariadbd --user=mysql --console $@