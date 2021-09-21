#include "fractol.h"

int		julia(t_vars *vars)
{
	int		color;
	int		pow;
	double	V;

	vars->i = 0;
	vars->max_i = 15000;
	vars->der = complex(1, 0);
	color = 0x0;
	pow = 1;
	while (vars->i < vars->max_i)
	{
		if (sqr_modul(vars->der) < 0.0002)
			break ;
		if (sqr_modul(vars->z) > (1 << 16))
		{
			//color = smooth_color(vars);
			V = log(sqr_modul(vars->z)) / pow;
			color = lin_inter(0x000000FF, 0x00FF0000, V);
			break ;
		}
		next_der(vars);
		next_z(vars);
		pow *= 2;
		vars->i++;
	}
	return (color);
}