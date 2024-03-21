# syntax=docker/dockerfile:1

FROM alpine:3.18.6

RUN apk add --no-cache mariadb=10.11.6-r0 mariadb-client=10.11.6-r0 \ 
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && mysql_install_db --user=mysql --datadir=/var/lib/mysql

COPY tools/healthcheck.sh /scripts/healthcheck.sh
COPY tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY conf/my.cnf /etc/my.cnf.d/my.cnf

RUN chmod +x /scripts/docker-entrypoint.sh \
    && chmod +x /scripts/healthcheck.sh

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

HEALTHCHECK --interval=30s --timeout=3s --start-period=30s --retries=3 \
    CMD ["/scripts/healthcheck.sh"]