#include "fractol.h"

void	init_vars_julia(t_vars *vars)
{
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -1.5;
	vars->y1 = 1.5;
	vars->window_width = 240 * 4;
	vars->window_height = 240 * 3;
	vars->max_i = 1000;
	vars->col_hz = 3;
	create_palette(vars);
}

void	init_julia(t_vars *vars, t_complex p)
{
	vars->z = p;
	vars->i = 0;
	vars->der = complex(1, 0);
}
