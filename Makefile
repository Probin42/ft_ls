# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rweiss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 12:08:33 by rweiss            #+#    #+#              #
#    Updated: 2017/06/05 12:04:41 by rweiss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ft_ls.h

SRC =	main.c \
	 	ft_sort_ft.c \
	 	ft_sort.c \
		ft_size_ls.c \
		ft_recursion.c \
		ft_put_file.c \
		ft_print_things.c \
		ft_print_right.c \
		ft_lst_function.c \
		ft_item.c \
		ft_get_time.c \
		ft_freefct.c \
		ft_error.c \
		ft_earth.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	@printf "\e[33;1mproject  \e[37;1m==>  \e[32;1mready\n"

.PHONY: clean fclean

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
