# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx -Iincludes -I$(LIBFT)
LIBS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

# Directories

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_DIR = includes/

# Files

SRCS = fractol.c render.c mandelbrot.c julia.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
INCLUDES = $(wildcard $(INCLUDES_DIR)*.h)
LIBFT = libft

NAME = fractol

# Targets

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o fractol

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
