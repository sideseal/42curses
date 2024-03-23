# syntax=docker/dockerfile:1

FROM alpine:3.18.6

RUN apk add --no-cache mariadb=10.11.6-r0 mariadb-client=10.11.6-r0 \ 
    && rm -f /var/cache/apk/* \
    && mkdir -p /scripts \
    && chmod -R 755 /scripts \
    && mkdir -p /run/mysqld \
    && chown -R mysql:mysql /run/mysqld \
    && chown -R mysql:mysql /var/lib/mysql \
    && mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

COPY tools/healthcheck.sh /scripts/healthcheck.sh
COPY tools/docker-entrypoint.sh /scripts/docker-entrypoint.sh
COPY conf/my.cnf /etc/my.cnf.d/my.cnf

RUN chmod +x /scripts/docker-entrypoint.sh /scripts/healthcheck.sh

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

HEALTHCHECK --interval=3s --timeout=5s --start-period=3s --retries=3 \
    CMD ["/scripts/healthcheck.sh"]