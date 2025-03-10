# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -I minilibx-linux -I includes -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext

# Directories

SRC_DIR = src/
SRCS = render.c mandelbrot.c julia.c

INCLUDES_DIR = includes/
INCLUDES = $(wildcard *.h)

# Targets

render: $(addprefix $(SRC_DIR), render.c) $(addprefix $(INCLUDES_DIR), $(INCLUDES))
	$(CC) $(addprefix $(SRC_DIR), render.c) -o render $(CFLAGS) 

mandelbrot: $(addprefix $(SRC_DIR), mandelbrot.c) $(addprefix $(INCLUDES_DIR), $(INCLUDES))
	$(CC) $(addprefix $(SRC_DIR), mandelbrot.c) -o mandelbrot $(CFLAGS) 

julia: $(addprefix $(SRC_DIR), julia.c) $(addprefix $(INCLUDES_DIR), $(INCLUDES))
	$(CC) $(addprefix $(SRC_DIR), julia.c) -o julia $(CFLAGS) 
