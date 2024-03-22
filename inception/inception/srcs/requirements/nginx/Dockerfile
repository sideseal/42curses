# syntax=docker/dockerfile:1

FROM alpine:3.18.6

RUN apk add --no-cache nginx=1.24.0-r7 \
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && mkdir -p /var/www/html \
    && chown -R nginx:nginx /var/www/html \
    && sed -i \
        -e 's|access_log /var/log/nginx/access.log main;|access_log /dev/stdout main;|' \
        -e 's|error_log /var/log/nginx/error.log warn;|error_log /dev/stderr notice;|' \
        -e 's|ssl_protocols TLSv1.1 TLSv1.2 TLSv1.3;|ssl_protocols TLSv1.2;|' \
        /etc/nginx/nginx.conf

COPY tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY conf/my.conf /etc/nginx/http.d/default.conf

RUN chmod +x /scripts/docker-entrypoint.sh

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

VOLUME ["/var/www/html"]

EXPOSE 80 443

STOPSIGNAL SIGQUIT
