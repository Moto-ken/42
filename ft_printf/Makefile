# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 20:49:26 by kemotoha          #+#    #+#              #
#    Updated: 2025/05/19 18:39:47 by kemotoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c \
	   ft_putnbr_fd.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_puthex_fd.c \
	   ft_unsigned_putnbr_fd.c \
	   ft_long_puthex_fd.c \
	   ft_format_judge.c

OBJS = $(SRCS:.c=.o)
INC_DIR = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
