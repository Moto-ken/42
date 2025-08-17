# **************************************************************************** #
#                                Makefile                                      #
# **************************************************************************** #

NAME        = so_long

# Directories
SRC_DIR     = .
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux
GNL_DIR 	= get_next_line

# Source Files
SRC_FILES   = \
              main.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c \
			  check_map.c \
			  event.c \
			  map.c \
			  player.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:.c=.o)

# Includes
INCLUDES    = -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# Compiler
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# MinilibX flags for Linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Build Libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build MinilibX
$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

# Clean all
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Bonus rules if needed
.PHONY: all clean fclean re
