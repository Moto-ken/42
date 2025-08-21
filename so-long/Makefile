# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 14:53:15 by kemotoha          #+#    #+#              #
#    Updated: 2025/08/21 19:06:22 by kemotoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long

SRC_DIR     = .
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux
GNL_DIR 	= get_next_line

SRC_FILES   = \
              main.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c \
			  check_map.c \
			  event.c \
			  map.c \
			  player.c \
			  check_flood.c \
			  check_closed.c \
			  display.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
