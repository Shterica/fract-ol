#include "fractol.h"

int	closing(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_pnt, vars->img);
	mlx_destroy_window(vars->mlx_pnt, vars->window_pnt);
	mlx_destroy_display(vars->mlx_pnt);
	free(vars->mlx_pnt);
	free(vars);
	exit(0);
}

void	color_shift_up(t_vars *vars)
{
	vars->color_id += 1;
	vars->color_id %= 6;
	pain_ting(vars);
}

void	color_shift_down(t_vars *vars)
{
	vars->color_id -= 1;
	if (vars->color_id == -1)
		vars->color_id = 5;
	pain_ting(vars);
}

void	ft_reset(t_vars *vars)
{
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -1.5;
	vars->y1 = 1.5;
	pain_ting(vars);
}
