#!/bin/sh

set -ex

WP_PATH="/var/www/html"

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
        --url=$DOMAIN_NAME \
        --title="Inception" \
        --admin_user=$WORDPRESS_ADMIN \
        --admin_password=$WORDPRESS_ADMIN_PASSWORD \
        --admin_email=$WORDPRESS_ADMIN_EMAIL

    wp user create \
        $WORDPRESS_USER \
        $WORDPRESS_USER_EMAIL \
        --path=$WP_PATH \
        --allow-root \
        --user_pass=$WORDPRESS_USER_PASSWORD
fi

chown -R www:www $WP_PATH
chmod -R 1777 $WP_PATH

echo "Starting Wordpress Container..."

exec php-fpm81 -F