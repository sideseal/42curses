# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 00:12:22 by gychoi            #+#    #+#              #
#    Updated: 2023/02/01 23:47:45 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
RM = rm
RMFLAGS = -rf

LFTDIR = ./libft/
MDTDIR = ./mandatory/
BNSDIR = ./bonus/

all: $(NAME)

$(NAME):
	@make -j4 -C $(MDTDIR)
	@cp $(MDTDIR)$(NAME) .

bonus:
	@make -j4 -C $(BNSDIR)
	@cp $(BNSDIR)$(NAME) .

clean:
	@make clean -C $(LFTDIR)
	@make clean -C $(MDTDIR)
	@make clean -c $(BNSDIR)

fclean:
	@make fclean -C $(LFTDIR)
	@make fclean -C $(MDTDIR)
	@make fclean -C $(BNSDIR)
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re bonus
