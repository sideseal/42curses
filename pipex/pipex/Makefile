# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 00:12:22 by gychoi            #+#    #+#              #
#    Updated: 2023/02/02 14:43:48 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
RM = rm
RMFLAGS = -rf

LFTDIR = ./libft/
MDTDIR = ./mandatory/
BNSDIR = ./bonus/

MDTBLD = ./build/
BNSBLD = ./build_bonus/

ifdef WITH_BONUS
	BLDDIR = $(BNSBLD)
	CMPDIR = $(BNSDIR)
else
	BLDDIR = $(MDTBLD)
	CMPDIR = $(MDTDIR)
endif

all:
	@$(RM) $(RMFLAGS) $(BNSBLD)
	@make $(NAME)

bonus:
	@$(RM) $(RMFLAGS) $(MDTBLD)
	@make $(NAME) WITH_BONUS=1

dummy:

$(NAME): dummy | $(BLDDIR)
	@make -j4 -C $(CMPDIR)
	@cp $(CMPDIR)$(NAME) .

$(BLDDIR):
	@mkdir -p $(BLDDIR)

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

.PHONY: all clean fclean re bonus dummy
