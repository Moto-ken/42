# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 12:02:53 by kemotoha          #+#    #+#              #
#    Updated: 2025/09/23 19:04:19 by kemotoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

NAME    = push_swap

SRC_DIR = .
OP_DIR  = operations

SRCS = \
	$(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/stack.c \
	$(SRC_DIR)/util.c \
	$(SRC_DIR)/radix_sort.c \
	$(SRC_DIR)/min_sort.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/argument_judge.c \
	$(SRC_DIR)/conversion_number.c \
	$(OP_DIR)/push_stack.c \
	$(OP_DIR)/swap_stack.c \
	$(OP_DIR)/rotate_stack.c \
	$(OP_DIR)/reverse_rotate.c \
	$(OP_DIR)/double_operations.c

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
