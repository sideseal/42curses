# syntax=docker/dockerfile:1

FROM alpine:3.18.6 AS cert-generator

ARG CERT_PATH
ARG DOMAIN_NAME

RUN apk add --no-cache openssl=3.1.4-r5 \
    && rm -f /var/cache/apk/* \
    && mkdir -p /certs

COPY $CERT_PATH/$DOMAIN_NAME* /certs

RUN if [ ! -f /certs/$DOMAIN_NAME.pem ] || [ ! -f /certs/$DOMAIN_NAME.key ]; then \
        openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /certs/$DOMAIN_NAME.key -out /certs/$DOMAIN_NAME.pem \
        -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=$DOMAIN_NAME"; \
    fi

FROM alpine:3.18.6

ARG DOMAIN_NAME

RUN apk add --no-cache nginx=1.24.0-r7 \
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && adduser -D -u 8282 -s /sbin/nologin www \
    && mkdir -p /var/www/html \
    && chown -R www:www /var/www/html \
    && mkdir -p /etc/nginx/certs

COPY --from=cert-generator /certs/$DOMAIN_NAME.pem /etc/nginx/certs/inception.pem
COPY --from=cert-generator /certs/$DOMAIN_NAME.key /etc/nginx/certs/inception.key
COPY --chmod=755 tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY --chown=nginx:nginx conf/my.conf /etc/nginx/http.d/default.conf

ENTRYPOINT /scripts/docker-entrypoint.sh

VOLUME /var/www/html

EXPOSE 443

STOPSIGNAL SIGQUIT

HEALTHCHECK --interval=3s --timeout=5s --start-period=3s --retries=3 \
    CMD wget --quiet --tries=1 --spider --no-check-certificate https://localhost/health || exit 1