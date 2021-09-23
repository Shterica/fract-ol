#include "fractol.h"

void	zoom_in(int x, int y, t_vars *vars)
{
	double	x_length;
	double	y_length;

	x_length = (vars->x1 - vars->x0) / vars->window_width;
	y_length = (vars->y1 - vars->y0) / vars->window_height;
	vars->x1 -= x_length * (vars->window_width - x) * 0.05;
	vars->x0 += x_length * x * 0.05;
	vars->y1 -= y_length * y * 0.05;
	vars->y0 += y_length * (vars->window_height - y) * 0.05;
	pain_ting(vars);
}

void	zoom_out(int x, int y, t_vars *vars)
{
	double	x_length;
	double	y_length;

	x_length = (vars->x1 - vars->x0) / vars->window_width;
	y_length = (vars->y1 - vars->y0) / vars->window_height;
	vars->x1 += x_length * (vars->window_width - x) * 0.05;
	vars->x0 -= x_length * x * 0.05;
	vars->y1 += y_length * y * 0.05;
	vars->y0 -= y_length * (vars->window_height - y) * 0.05;
	pain_ting(vars);
}
