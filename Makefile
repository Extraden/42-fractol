# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Iincludes -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm

# Directories

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_DIR = includes/

# Files

SRCS = fractol.c render.c mandelbrot.c julia.c
OBJS = $(SRC_DIR)/$(SRCS:.c=.o)
INCLUDES = $(wildcard $(INCLUDES_DIR)*.h)

NAME = all

# Targets

all: fractol render mandelbrot julia

fractol: $(addprefix $(SRC_DIR), fractol.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), fractol.c) -o fractol $(CFLAGS) 

render: $(addprefix $(SRC_DIR), render.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), render.c) -o render $(CFLAGS) 

mandelbrot: $(addprefix $(SRC_DIR), mandelbrot.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), mandelbrot.c) -o mandelbrot $(CFLAGS) 

julia: $(addprefix $(SRC_DIR), julia.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), julia.c) -o julia $(CFLAGS) 
