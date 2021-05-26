# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 14:51:49 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/03/31 19:21:36 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TIME =   $(shell date +'%d/%m/%Y %H:%M:%S')
M =
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c ft_gnl.c \
	ft_strcmp.c ft_atod.c ft_lstfirst.c
OBJS_SOURCE = $(SOURCE:.c=.o)
LIBS = libft.h
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS_SOURCE) $(OBJS_BONUS)
	ar -cr $(NAME) $(OBJS_SOURCE) $(OBJS_BONUS)

clean:
	rm -f $(OBJS_SOURCE) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS) $(OBJS_SOURCE)
	ar -cr $(NAME) $(OBJS_SOURCE) $(OBJS_BONUS)

update: fclean
	git add .
	git commit -am "$(TIME) - $(M)"
	git push origin master
