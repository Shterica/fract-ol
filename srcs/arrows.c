#include "fractol.h"

void	move_left(t_vars *vars)
{
	double	x_length;

	x_length = vars->x1 - vars->x0;
	vars->x1 -= x_length * 0.05;
	vars->x0 -= x_length * 0.05;
	pain_ting(vars);
}

void	move_up(t_vars *vars)
{
	double	y_length;

	y_length = vars->y1 - vars->y0;
	vars->y1 += y_length * 0.05;
	vars->y0 += y_length * 0.05;
	pain_ting(vars);
}

void	move_right(t_vars *vars)
{
	double	x_length;

	x_length = vars->x1 - vars->x0;
	vars->x1 += x_length * 0.05;
	vars->x0 += x_length * 0.05;
	pain_ting(vars);
}

void	move_down(t_vars *vars)
{
	double	y_length;

	y_length = vars->y1 - vars->y0;
	vars->y1 -= y_length * 0.05;
	vars->y0 -= y_length * 0.05;
	pain_ting(vars);
}