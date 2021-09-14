#include "fractol.h"

void	init_list(t_vars *vars)
{
	//double	cx;
	//double	cy;

	//cx = 0.001643721971153;
	//cy = 0.822467633298876;
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -2;
	vars->y1 = 2;
	vars->window_width = 200 * 4;
	vars->window_height = 200 * 4;
}
