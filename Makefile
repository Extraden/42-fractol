# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MINILIBX_DIR) -I$(INCLUDES_DIR) -I$(LIBFT_DIR)
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz

# Directories

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_DIR = include/
LIBFT_DIR = libft/
MINILIBX_DIR = minilibx-linux/

# Files

SRCS = fractol.c render.c mandelbrot.c burningship.c julia.c \
		mapping.c utils.c events.c mlx_utils.c parse.c color.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)
INCLUDES = $(INCLUDES_DIR)fractol.h
LIBFT = $(LIBFT_DIR)libft.a

NAME = fractol

# Targets

all: $(NAME)

libs:
	make -C $(MINILIBX_DIR)
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) | libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all libs clean fclean re
