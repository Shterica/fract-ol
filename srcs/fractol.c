#include "fractol.h"

void	fractol(void)
{
	t_vars		vars;

	init_list(&vars);
	vars.mlx_pnt = mlx_init();
	vars.window_pnt = mlx_new_window(vars.mlx_pnt, vars.window_width, vars.window_height, "fractol");
	vars.img = mlx_new_image(vars.mlx_pnt, vars.window_width, vars.window_height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	pain_ting(&vars);
	mlx_key_hook(vars.window_pnt, button_pars, &vars);
	mlx_mouse_hook(vars.window_pnt, mouse_pars, &vars);
	mlx_loop(vars.mlx_pnt);
}
