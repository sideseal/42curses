#!/bin/sh

set -ex

WP_PATH="/var/www/html"

WORDPRESS_DB_NAME=${WORDPRESS_DB_NAME:-""}
WORDPRESS_DB_USER=${WORDPRESS_DB_USER:-""}
WORDPRESS_DB_PASSWORD=${WORDPRESS_DB_PASSWORD:-""}
WORDPRESS_DB_HOST=${WORDPRESS_DB_HOST:-"mariadb"}

WORDPRESS_ADMIN_USER=${WORDPRESS_ADMIN_USER:-""}
WORDPRESS_ADMIN_PASSWORD=${WORDPRESS_ADMIN_PASSWORD:-""}
WORDPRESS_ADMIN_EMAIL=${WORDPRESS_ADMIN_EMAIL:-""}

WORDPRESS_USER=${WORDPRESS_USER:-"user"}
WORDPRESS_USER_EMAIL=${WORDPRESS_USER_EMAIL:-""}
WORDPRESS_USER_PASSWORD=${WORDPRESS_USER_PASSWORD:-"user"}

error=0
case "$WORDPRESS_ADMIN_USER" in
    *admin*|*Admin*|'')
        error=1
        ;;
esac

case "$WORDPRESS_ADMIN_PASSWORD" in
    *admin*|*Admin*|'')
        error=1
        ;;
esac

if [ $error -eq 1 ]; then
    echo >&2 'error: WORDPRESS_ADMIN_USER and WORDPRESS_ADMIN_PASSWORD must not contain "admin" or be empty'
    return 1
fi

mariadb-admin ping -h 172.21.42.40 -u${WORDPRESS_DB_USER} -p${WORDPRESS_DB_PASSWORD} || return 1

if [ ! -e $WP_PATH/wp-config.php ]; then
    echo "Creating WordPress..."

    wp core download \
        --path=$WP_PATH \
        --allow-root \
        --version='nightly'

    wp config create \
        --path=$WP_PATH \
        --allow-root \
        --dbname=$WORDPRESS_DB_NAME \
        --dbuser=$WORDPRESS_DB_USER \
        --dbpass=$WORDPRESS_DB_PASSWORD \
        --dbhost=$WORDPRESS_DB_HOST
fi

if ! wp core is-installed --path=$WP_PATH --allow-root; then
    echo "Installing WordPress..."

    wp core install \
        --path=$WP_PATH \
        --allow-root \
        --url=https://$DOMAIN_NAME \
        --title="Inception" \
        --admin_user=$WORDPRESS_ADMIN_USER \
        --admin_password=$WORDPRESS_ADMIN_PASSWORD \
        --admin_email=$WORDPRESS_ADMIN_EMAIL

    wp user create \
        $WORDPRESS_USER \
        $WORDPRESS_USER_EMAIL \
        --path=$WP_PATH \
        --allow-root \
        --user_pass=$WORDPRESS_USER_PASSWORD

    wp cache flush --allow-root --path=$WP_PATH
fi

echo "Starting Wordpress Container..."

exec php-fpm81 -F
