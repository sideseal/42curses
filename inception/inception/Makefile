# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 20:58:04 by gychoi            #+#    #+#              #
#    Updated: 2024/01/30 20:58:07 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

DOCKER = docker
DOCKER_COMPOSE = $(DOCKER) compose
SRCS = srcs/docker-compose.yml

.PHONY: up down start stop

up:
	@$(DOCKER_COMPOSE) -f $(SRCS) up -d

down:
	@$(DOCKER_COMPOSE) -f $(SRCS) down

start:
	@$(DOCKER_COMPOSE) -f $(SRCS) start

stop:
	@$(DOCKER_COMPOSE) -f $(SRCS) stop

.PHONY: all clean fclean re

# need to change path
export PWD = $(shell pwd)
export MARIADB_PATH = ${PWD}/data/mariadb
export WORDPRESS_PATH = ${PWD}/data/wordpress

all:
	@mkdir -p ${MARIADB_PATH}	
	@mkdir -p ${WORDPRESS_PATH}
	@$(DOCKER_COMPOSE) -f $(SRCS) up --build -d

clean:
	@$(DOCKER_COMPOSE) -f $(SRCS) down --volumes
	@rm -rf $(PWD)/data

fclean: clean
# docker rmi $(docker images --filter "label=com.example.description" -q)
	@$(DOCKER_COMPOSE) -f $(SRCS) down --rmi all

re: fclean
	$(MAKE) all