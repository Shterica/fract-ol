#include "fractol.h"

int		fractal_point_color(t_vars *vars, t_complex p)
{
	int color;
	
	vars->init(vars, p);
	color = 0x0;
	while (vars->i < vars->max_i)
	{
		if (sqr_modul(vars->der) < 0.00002)
			break ;
		else if (sqr_modul(vars->z) > (1 << 16))
		{
			color = vars->palet[vars->i];
			break ;
		}
		vars->next_der(vars);
		vars->next_z(vars);
		vars->i++;
	}
	return (color);
}

void	ft_fractol(t_vars *vars)
{
	vars->mlx_pnt = mlx_init();
	vars->window_pnt = mlx_new_window(vars->mlx_pnt, vars->window_width, vars->window_height, "fractol");
	vars->img = mlx_new_image(vars->mlx_pnt, vars->window_width, vars->window_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	pain_ting(vars);
	mlx_hook(vars->window_pnt, 17, 1L<<3, closing, vars);
	mlx_key_hook(vars->window_pnt, ft_button, vars);
	mlx_mouse_hook(vars->window_pnt, ft_mouse, vars);
	mlx_loop(vars->mlx_pnt);
}
