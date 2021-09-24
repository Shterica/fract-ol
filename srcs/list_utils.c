#include "fractol.h"

void	init_vars_default(t_vars *vars)
{
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -1.5;
	vars->y1 = 1.5;
	vars->window_width = 240 * 4;
	vars->window_height = 240 * 3;
	vars->max_i = 1000;
	create_palette(vars);
}
