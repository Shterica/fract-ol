#include "fractol.h"

int		normal_map_color(t_vars *vars)
{
	double h2;
	double phi;
	t_complex v;
	t_complex u;
	double abs_u;
	double t;

	h2 = 1.5;
	phi = 45 * 2 * PI / 360;
	v = complex(cos(phi), sin(phi));
	u = c_div(vars->z, vars->der);
	abs_u = sqrt(sqr_modul(u));
	u = complex(u.x / abs_u, u.y / abs_u);
	t = u.x * v.x + u.y * v.y + h2;
	t = t / (1 + h2);
	if (t < 0)
		t = 0;
	return (rgb_to_int(t * 255, t * vars->color_offset[vars->color_id], t * 255));
}

int		fractal_point_color(t_vars *vars, t_complex p)
{
	int color;
	
	vars->init(vars, p);
	color = vars->set_color[vars->color_id];
	while (vars->i < vars->max_i)
	{
		if (sqr_modul(vars->der) < 0.00002)
			break ;
		else if (sqr_modul(vars->z) > (1 << 16))
		{
			vars->i = vars->i + vars->color_offset[vars->color_id];
			if (vars->color_id >= 4)
				color = normal_map_color(vars);
			else
				color = smooth_color(vars);
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
