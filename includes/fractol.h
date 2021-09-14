#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>

# include <stdio.h>
# include <stdlib.h>

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

typedef	struct s_vars
{
	void	*mlx_pnt;
	void	*window_pnt;
	int		window_width;
	int		window_height;
	
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	
	t_complex z;
	t_complex c;
	t_complex der;
	int		i;
	int		max_i;
}				t_vars;

/* s_vars initialization with window params
	and visible area params | list_init.c */
void	init_list(t_vars *vars);

/* utilities for complex numbers | complex_utils.c */
t_complex	complex(double x, double y);
double		sqr_modul(t_complex c);

/* creating a palette for coloring | color.c */
int		palette(int	iter, int max_iter);
double	lin_inter(double c1, double c2, double i);

/* pixel color computation for Mandelbrot fractal | mandelbrot.c */
int		mandelbrot(t_vars *vars);

/* pixel color computation for Julia fractal | julia.c */
int		julia(t_complex z, t_complex c);

/* handling various events | events.c */
int	closing(t_vars *vars);

/* painting and output of a fractal image | image_output.c */
void	pain_ting(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

/* zoom and movement handling | zoom.c and arrows.c */
void	zoom_in(int x, int y, t_vars *vars);
void	zoom_out(int x, int y, t_vars *vars);
void	move_left(t_vars *vars);
void	move_up(t_vars *vars);
void	move_right(t_vars *vars);
void	move_down(t_vars *vars);

/* parsers of a pressed key/mouse button | parser.c */
int	button_pars(int keycode, t_vars *vars);
int	mouse_pars(int button, int x, int y, t_vars *vars);

/* main func | fractol.c*/
void	fractol(void);

#endif