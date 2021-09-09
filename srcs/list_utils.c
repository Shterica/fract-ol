#include "fractol.h"

void	init_list(t_vars *vars)
{
	double	cx = 0.001643721971153;
	double	cy = 0.822467633298876;
	vars->x0 = cx - 0.0001;
	vars->x1 = cx + 0.0001;
	vars->y0 = cy - 0.0001;
	vars->y1 = cy + 0.0001;

	vars->window_width = 200 * 4;
	vars->window_height = 200 * 4;
}