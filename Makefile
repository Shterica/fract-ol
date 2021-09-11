NAME		= fractol

OS			= $(shell uname)

SRCS_PATH	= srcs/

HEADERS		= -I ./includes

SRCS_FILES	= arrows.c \
				color.c \
				events.c \
				fractol.c \
				image_output.c \
				list_utils.c \
				main.c \
				mandelbrot.c \
				parser.c \
				zoom.c

SRCS 		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS		:= $(SRCS:.c=.o)

CC			= gcc

ifeq ($(OS), Linux)
	MLX			= ./mlx_linux
	MLX_FLAGS = -L $(MLX) -l mlx -lXext -lX11
else
	MLX			= ./mlx
	MLX_FLAGS = -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC			= -I $(MLX)

CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)
	
$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME)

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c mlxmake
	$(CC) $(CFLAGS) $(MLX_INC) $(HEADERS) -o $@ -c $<

mlxmake:
	make -C $(MLX)

clean: 
	rm -rf $(OBJS)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all