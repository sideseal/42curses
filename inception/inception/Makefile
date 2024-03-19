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

NAME := inception
DOCKER := docker
COMPOSE := $(DOCKER) compose
SRCS := srcs/docker-compose.yml
COMMAND = @$(COMPOSE) -f $(SRCS) -p $(NAME)

.PHONY: up down start stop rm

up:
	$(COMMAND) up -d

down:
	$(COMMAND) down

start:
	$(COMMAND) start

stop:
	$(COMMAND) stop

.PHONY: all clean fclean re

# need to change path
export PWD = $(shell pwd)
export MARIADB_PATH = ${PWD}/data/mariadb
export WORDPRESS_PATH = ${PWD}/data/wordpress

all:
	@mkdir -p ${MARIADB_PATH} ${WORDPRESS_PATH}
	$(COMMAND) up --build -d

clean: down
	@echo "Container '$(NAME)' is stopped and removed."

fclean:
	$(COMMAND) down --volumes --rmi all
	@rm -rf $(PWD)/data
	@echo "Container '$(NAME)' is stopped and removed."
	@echo "Volumes and images are removed."

re: fclean
	$(MAKE) all