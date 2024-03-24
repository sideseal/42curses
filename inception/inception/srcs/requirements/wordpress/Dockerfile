# syntax=docker/dockerfile:1

FROM alpine:3.18.6

RUN apk add --no-cache \
    php81=8.1.27-r0 \
    php81-pecl-apcu=5.1.22-r0 \
    php81-fpm=8.1.27-r0 \
    php81-ctype=8.1.27-r0 \
    php81-curl=8.1.27-r0 \
    php81-posix=8.1.27-r0 \
    php81-tokenizer=8.1.27-r0 \
    php81-iconv=8.1.27-r0 \
    php81-intl=8.1.27-r0 \
    php81-mbstring=8.1.27-r0 \
    php81-openssl=8.1.27-r0 \
    php81-pcntl=8.1.27-r0 \
    php81-pdo=8.1.27-r0 \
    php81-pdo_mysql=8.1.27-r0 \
    php81-mysqli=8.1.27-r0 \
    php81-phar=8.1.27-r0 \
    php81-session=8.1.27-r0 \
    php81-zip=8.1.27-r0 \
    mariadb-client=10.11.6-r0 \
    curl=8.5.0-r0 \ 
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && adduser -D -u 8282 -s /sbin/nologin www \
    && mkdir -p /var/www/html \
    && chown -R www:www /var/www/html

ADD https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp-cli.phar
COPY tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY conf/my.conf /etc/php81/php-fpm.d/www.conf

RUN chmod +x /scripts/docker-entrypoint.sh \
    && chmod +x /usr/local/bin/wp-cli.phar \
    && ln -s /usr/local/bin/wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

VOLUME ["/var/www/html"]

STOPSIGNAL SIGQUIT

EXPOSE 9000

HEALTHCHECK --interval=3s --timeout=5s --start-period=3s --retries=3 \
    CMD true