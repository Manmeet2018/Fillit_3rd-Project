# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparmar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 01:27:24 by maparmar          #+#    #+#              #
#    Updated: 2019/03/28 21:02:38 by bchapman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	main.c \
		solve_map.c \
		free_function.c \
		helper.c \
		maker.c \
		parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ):
		@gcc -c -Wall -Werror -Wextra $(SRC)

$(NAME): LIB $(OBJ)
	@gcc $(OBJ) ./libft/libft.a -o $(NAME)

LIB:
	@$(MAKE) -C ./libft/

clean:
	/bin/rm -f $(OBJ)
	@$(MAKE) -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean

re: fclean all
