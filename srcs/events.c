#include "fractol.h"

int	close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_pnt, vars->img);
	mlx_destroy_window(vars->mlx_pnt, vars->window_pnt);
	//mlx_destroy_display(vars->mlx_pnt);
	free(vars->mlx_pnt);
	exit(0);
}
