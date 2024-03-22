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

RUN chmod +x /scripts/docker-entrypoint.sh /scripts/healthcheck.sh

ENTRYPOINT ["/scripts/docker-entrypoint.sh"]

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

HEALTHCHECK --interval=10s --timeout=3s --start-period=10s --retries=3 \
    CMD ["/scripts/healthcheck.sh"]