NAME		= fractol

SRCS_PATH	= srcs/

HEADERS		= -I includes/ -I minilibx/

MLX_PATH	= minilibx/

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

CFLAGS		= -Wall -Werror -Wextra -Iminilibx -lXext -lX11 -lm

all: $(NAME)
	
$(NAME): $(OBJS) mlxmake
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADERS)

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

mlxmake:
	make -C $(MLX_PATH)

clean: 
		rm -rf $(OBJS)

fclean: clean

re: fclean all