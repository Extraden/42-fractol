# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Iincludes -I$(LIBFT)
LIBS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
# Directories

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_DIR = includes/

# Files

SRCS = fractol.c render.c mandelbrot.c julia.c mapping.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
INCLUDES = $(wildcard $(INCLUDES_DIR)*.h)
LIBFT = libft

NAME = fractol

# Targets

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	make -s -C $(LIBFT)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
