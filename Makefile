NAME		= fractol

SRCS_PATH	= srcs/

HEADERS		= -I includes/ -I/usr/local/include -I/usr/include

MLX_PATH	= mlx_linux/

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

CFLAGS		= -Wall -Werror -Wextra
LIBFLAGS	= -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz

all: $(NAME)
	
$(NAME): $(OBJS) mlxmake
	$(CC) $(OBJS) -L ./mlx_linux/ -l mlx -lXext -lX11 -lm -o $(NAME)

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -L ./mlx_linux/ -l mlx -lXext -lX11 -I ./includes/ -o $@ -c $<

mlxmake:
	make -C $(MLX_PATH)

clean: 
		rm -rf $(OBJS)

fclean: clean

re: fclean all