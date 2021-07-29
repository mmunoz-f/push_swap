# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:48:42 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/07/29 19:57:18 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =

CC = clang
CFLAGS = -Wall -Wextra -Werror

I = inc/

SOURCE = srcs/stack/stack_utils.c		\
	srcs/stack/operations.c				\
	srcs/stack/stack.c					\
	srcs/utils/utils.c
OBJS_SOURCE = $(SOURCE:.c=.o)

NAME = push_swap
PS_SOURCE = srcs/push_swap/push_swap.c	\
	srcs/push_swap/sort_greater.c		\
	srcs/push_swap/sort_three.c			\
	srcs/push_swap/sort_up_to_six.c		\
	srcs/push_swap/pass_nnumber.c		\
	srcs/push_swap/pass_chunks.c		\
	srcs/push_swap/sort_utils.c
PS_OBJS = $(PS_SOURCE:.c=.o)

CHECKER = checker
CHECKER_SOURCE = srcs/checker/checker.c
CHECKER_OBJS = $(CHECKER_SOURCE:.c=.o)

FTA = srcs/libft/libft.a
FT = srcs/libft/

%.o: %.c
	$(CC) $(CFLAGS) -I $I -I $(FT) -c $< -o $@

all: $(NAME)

$(NAME): $(PS_OBJS) $(OBJS_SOURCE) $(FTA)
	$(CC) $(CFLAGS) -I $I -I $(FT) -o $@ $^

$(FTA):
	make -C srcs/libft

bonus: all $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(OBJS_SOURCE) $(FTA)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS_SOURCE) $(PS_OBJS) $(CHECKER_OBJS)
	make fclean -C $(FT)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

push: fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re bonus push
