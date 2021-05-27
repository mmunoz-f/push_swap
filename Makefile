# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:48:42 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/05/27 19:57:42 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SOURCE = push_swap.c stack_utils.c push_swap_operations.c
OBJS_SOURCE = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_SOURCE) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

libft/libft.a:
	make -C ./libft

clean:
	rm -f $(OBJS_SOURCE) $(OBJS_BONUS)
	make fclean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re bonus push
