# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 17:03:21 by kemotoha          #+#    #+#              #
#    Updated: 2025/10/10 16:22:04 by kemotoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := pipex
CC          := cc

LIBFT_DIR   := ./libft
CFLAGS      := -Wall -Wextra -Werror -I$(LIBFT_DIR)

SRCS     = pipex.c \
           cmd_validation.c \
		   utile.c \
		   command_handler.c \
		   child_process.c \
		   split_quotes.c \
		   utile_split_quotes.c

OBJS        := $(SRCS:.c=.o)

LIBFT       := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
