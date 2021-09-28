#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>

# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159265

# ifdef __APPLE__
#  define K_ESC 53
#  define K_LEFT_ARROW 123
#  define K_UP_ARROW 126
#  define K_RIGHT_ARROW 124
#  define K_DOWN_ARROW 125
# else
#  define K_ESC 65307
#  define K_LEFT_ARROW 65361
#  define K_UP_ARROW 65362
#  define K_RIGHT_ARROW 65363
#  define K_DOWN_ARROW 65364
#  define K_PLUS 61
#  define K_MINUS 45
#  define K_R 114
# endif

/*
	Structure s_complex
	-------------------
	Stores complex number

	x				real part of a complex number
	y				imaginary part of a complex number

*/

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/*
	Structure s_vars
	----------------
	Stores variables needed for mlx functions and 
	visible graph area

	mlx_pnt 	pointer to the initialized mlx instance
	window_pnt	pointer to the created mlx window
	img			pointer to a new image
	
	addr			|\
	bits_per_pixel	|-\_ needed for creation of a new image
	line_length		|-/
	endian			|/

	window_width	width of a created window in pixels
	window_height	height of a created window in pixels
	x0				starting width coordinate of a visible graph area
	x1				finishing width coordinate of a visible graph area
	y0				starting height coordinatre of a visible graph area
	y1				finishing height coordinate of a visible grapgh area
*/

typedef struct s_vars
{
	void		*mlx_pnt;
	void		*window_pnt;
	int			window_width;
	int			window_height;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	t_complex	z;
	t_complex	c;
	t_complex	der;
	int			i;
	int			max_i;
	int			(*point_color)(struct s_vars *, t_complex p);
	void		(*init)(struct s_vars *, t_complex p);
	void		(*next_z)(struct s_vars *);
	void		(*next_der)(struct s_vars *);
	int			col_hz;
	int			set_color[6];
	int			color_offset[6];
	int			color_id;
	int			palet[1000];
}				t_vars;

/* s_vars initialization with window params
	and visible area params | list_init.c */
void		init_vars_default(t_vars *vars);

/* argument parsing | parser.c */
t_vars		*argument_parser(int ac, char **av);
t_vars		*ft_error_handler(void);
t_vars		*ft_mandelbrot_parser(int ac, char **av);
t_vars		*ft_julia_parser(int ac, char **av);
t_vars		*ft_collatz_parser(int ac, char **av);

/* utilities for parsing | parser_utils.c */
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(char *s);
void		init_common_vars(t_vars *vars);

/* utilities for complex numbers | complex_utils.c complex_utils2.c*/
double		sqr_modul(t_complex c);
t_complex	complex(double x, double y);
t_complex	c_mult(t_complex a, t_complex b);
t_complex	c_cos(t_complex c);
t_complex	c_sub(t_complex a, t_complex b);
t_complex	c_sin(t_complex c);
t_complex	c_div(t_complex a, t_complex b);

/* creating a palette for coloring | color.c */
int			palette(int iter, int max_iter);
double		lin_inter(double c1, double c2, double i);
int			rgb_to_int(int r, int g, int b);
void		create_palette(t_vars *vars);
int			smooth_color(t_vars *vars);

/* pixel color computation for Mandelbrot fractal | mandelbrot.c */
void		next_der_mandel(t_vars *vars);
void		next_z_mandel(t_vars *vars);
void		init_mandel(t_vars *vars, t_complex p);
void		init_vars_mandel(t_vars *vars);
void		init_vars_default_mandel(t_vars *vars);

/* pixel color computation for Julia fractal | julia.c */
void		init_julia(t_vars *vars, t_complex p);
void		init_vars_julia(t_vars *vars);

/* pixel color computation for Collatz fractal | collatz.c */
void		init_collatz(t_vars *vars, t_complex p);
void		next_z_collatz(t_vars *vars);
void		next_der_collatz(t_vars *vars);
void		init_vars_default_collatz(t_vars *vars);

/* handling various events | events.c */
int			closing(t_vars *vars);
void		color_shift_down(t_vars *vars);
void		color_shift_up(t_vars *vars);
void		ft_reset(t_vars *vars);

/* painting and output of a fractal image | image_output.c */
void		pain_ting(t_vars *vars);
void		my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

/* zoom and movement handling | zoom.c and arrows.c */
void		zoom_in(int x, int y, t_vars *vars);
void		zoom_out(int x, int y, t_vars *vars);
void		move_left(t_vars *vars);
void		move_up(t_vars *vars);
void		move_right(t_vars *vars);
void		move_down(t_vars *vars);

/* parsers of a pressed key/mouse button | key_handler.c */
int			ft_button(int keycode, t_vars *vars);
int			ft_mouse(int button, int x, int y, t_vars *vars);

/* main func | fractol.c*/
void		ft_fractol(t_vars *vars);
int			fractal_point_color(t_vars *vars, t_complex p);
int			normal_map_color(t_vars *vars);

#endif