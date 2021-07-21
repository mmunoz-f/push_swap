# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:48:42 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/07/21 20:40:19 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SOURCE = stack_utils.c push_swap_operations.c \
	push_swap_utils.c utils.c
OBJS_SOURCE = $(SOURCE:.c=.o)

NAME = push_swap
PS_SOURCE = push_swap.c push_swap_solve.c sort_greater.c sort_three.c \
	sort_great_utils.c solve_six.c simple_sort.c
PS_OBJS = $(PS_SOURCE:.c=.o)

CHECKER = checker
CHECKER_SOURCE = checker.c
CHECKER_OBJS = $(CHECKER_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(PS_OBJS) $(OBJS_SOURCE) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

libft/libft.a:
	make -C ./libft

bonus: all $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(OBJS_SOURCE) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS_SOURCE) $(PS_OBJS) $(CHECKER_OBJS)
	make fclean -C ./libft

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

push: fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re bonus push
