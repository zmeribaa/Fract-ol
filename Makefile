# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 15:16:59 by zmeribaa          #+#    #+#              #
#    Updated: 2021/12/12 15:26:07 by zmeribaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fractol
CC		= 	gcc
SRC		=	*.c
LIB		=	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS	=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@clear
	@echo "\033[0;32mCompiled (｡•̀ᴗ-)✧\033[0m"
	@$(CC) -g $(SRC) $(LIB) $(FLAGS) -o $(NAME)


fclean:
	@(rm -rf $(NAME))
	@rm -rf *.dSYM
	@echo "\033[0;31mCleaned ʕ ಡ ﹏ ಡ\033[0m"

re:	fclean all

.PHONY : bonus clean fclean re