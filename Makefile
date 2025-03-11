# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Iincludes -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm

# Directories

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_DIR = includes/

# Files

SRCS = render.c mandelbrot.c julia.c
OBJS = $(SRC:.c=.o)
INCLUDES = $(wildcard $(INCLUDES_DIR)*.h)

NAME = all

# Targets

all: render mandelbrot julia

render: $(addprefix $(SRC_DIR), render.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), render.c) -o render $(CFLAGS) 

mandelbrot: $(addprefix $(SRC_DIR), mandelbrot.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), mandelbrot.c) -o mandelbrot $(CFLAGS) 

julia: $(addprefix $(SRC_DIR), julia.c) $(INCLUDES)
	$(CC) $(addprefix $(SRC_DIR), julia.c) -o julia $(CFLAGS) 
