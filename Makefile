NAME		= fractol

OS			= $(shell uname)

SRCS_PATH	= srcs/

OBJS_PATH	= objs/

HEADERS		= -I ./includes

SRCS_FILES	= arrows.c \
				color.c \
				events.c \
				fractol.c \
				image_output.c \
				main.c \
				mandelbrot.c \
				julia.c \
				key_handler.c \
				complex_utils.c \
				complex_utils2.c \
				parser.c \
				parser_utils.c \
				collatz.c \
				zoom.c

OBJS_FILES	= $(SRCS_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS		:= $(addprefix $(OBJS_PATH), $(OBJS_FILES))

CC			= gcc

ifeq ($(OS), Linux)
	MLX			= ./mlx_linux
	MLX_FLAGS = -L $(MLX) -l mlx -lXext -lX11 -lz
else
	MLX			= ./mlx
	MLX_FLAGS = -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_NAME	= $(MLX)/libmlx.a

MLX_INC			= -I $(MLX)

CFLAGS		= -Wall -Werror -Wextra -O3

all: $(NAME)
	
$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(MLX_NAME) objs
	$(CC) $(CFLAGS) $(MLX_INC) $(HEADERS) -o $@ -c $<

$(MLX_NAME):
	make -C $(MLX)

objs:
	mkdir $(OBJS_PATH)

clean: 
	rm -rf $(OBJS_PATH)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all