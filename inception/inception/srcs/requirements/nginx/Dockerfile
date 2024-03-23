# syntax=docker/dockerfile:1

FROM alpine:3.18.6 AS cert-generator

ARG CERT_PATH
ARG DOMAIN_NAME

RUN apk add --no-cache openssl=3.1.4-r5 \
    && rm -f /var/cache/apk/* \
    && mkdir -p /certs

RUN if [ -f $CERT_PATH/$DOMAIN_NAME.pem ] && [ -f $CERT_PATH/$DOMAIN_NAME.key ]; then \
        cp $CERT_PATH/$DOMAIN_NAME.pem /certs/inception.pem; \
        cp $CERT_PATH/$DOMAIN_NAME.key /certs/inception.key; \
    else \
        openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /certs/inception.key -out /certs/inception.pem \
        -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=$DOMAIN_NAME"; \
    fi

FROM alpine:3.18.6

RUN apk add --no-cache nginx=1.24.0-r7 \
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && mkdir -p /var/www/html \
    && chown -R nginx:nginx /var/www/html \
    && mkdir -p /etc/nginx/certs

COPY --from=cert-generator /certs/inception.pem /etc/nginx/certs/inception.pem
COPY --from=cert-generator /certs/inception.key /etc/nginx/certs/inception.key
COPY tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY conf/my.conf /etc/nginx/http.d/default.conf

RUN chmod +x /scripts/docker-entrypoint.sh

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

VOLUME ["/var/www/html"]

EXPOSE 443

STOPSIGNAL SIGQUIT
