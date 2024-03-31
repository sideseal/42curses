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

USER := gychoi
NAME := inception
DOCKER := docker
COMPOSE := $(DOCKER) compose
SRCS := srcs/docker-compose.yml
COMMAND = @$(COMPOSE) -f $(SRCS) -p $(NAME)

.PHONY: up down start stop logs clear rebuild

up:
	$(COMMAND) up

down:
	$(COMMAND) down

start:
	$(COMMAND) start

stop:
	$(COMMAND) stop

logs:
	$(COMMAND) logs

logs-all:
	${COMPOSE} -f ${SRCS} logs -f

kill:
	$(COMMAND) kill

clear:
	@echo "Removing dangling images..."
	@dangling_images=$$($(DOCKER) images -q -f dangling=true); \
    if [ -n "$$dangling_images" ]; then \
        $(DOCKER) rmi $$dangling_images; \
    fi
	@echo "Removing build cache..."
	$(DOCKER) builder prune -af

rebuild: clear
	$(COMMAND) up --build --force-recreate --detach

.PHONY: all clean fclean re

# need to change path
export USER_PATH = /home/${USER}
export MARIADB_PATH = ${USER_PATH}/data/mariadb
export WORDPRESS_PATH = ${USER_PATH}/data/wordpress

all:
	@mkdir -p ${MARIADB_PATH} ${WORDPRESS_PATH}
	$(COMMAND) up --build --detach

clean: clear
	$(COMMAND) down --volumes
	@echo "Container '$(NAME)' is stopped and removed."

fclean: clear
	$(COMMAND) down --volumes --rmi all
	@sudo rm -rf $(USER_PATH)/data
	@echo "Container '$(NAME)' is stopped and removed."
	@echo "Volumes and images are removed."

re: fclean
	$(MAKE) all
