# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:48:42 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/07/22 23:13:55 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SOURCE = srcs/stack/stack_utils.c		\
	srcs/stack/operations.c				\
	srcs/stack/stack.c					\
	srcs/utils/utils.c
OBJS_SOURCE = $(SOURCE:.c=.o)

NAME = push_swap
PS_SOURCE = push_swap/srcs/push_swap.c	\
	push_swap/srcs/sort_greater.c		\
	push_swap/srcs/sort_three.c			\
	push_swap/srcs/simple_sort.c
PS_OBJS = $(PS_SOURCE:.c=.o)

CHECKER = checker
CHECKER_SOURCE = checker/srcs/checker.c
CHECKER_OBJS = $(CHECKER_SOURCE:.c=.o)

# $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -c $< -o $@

# OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBFT = srcs/libft/libft.a

all: $(NAME)

$(NAME): $(PS_OBJS) $(OBJS_SOURCE) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

libft/libft.a:
	make -C srcs/libft

bonus: all $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(OBJS_SOURCE) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS_SOURCE) $(PS_OBJS) $(CHECKER_OBJS)
	make fclean -C srcs/libft

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

push: #fclean
	git add .
	git commit -m "$(TIME) - $(M)"
	git push origin master

.PHONY: all clean fclean re bonus push
