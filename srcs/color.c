#include "fractol.h"

int	rgb_to_int(int r, int g, int b)
{
	return (b + 256 * g + 256 * 256 * r);
}

void	create_palette(t_vars *vars)
{
	int x;
	int red;
	int green;
	int blue;

	x = 0;

	while (x < vars->max_i)
	{
		red = (int)(128.0 + 128 * sin(3.1415 * x / 16.0));
		green = (int)(128.0 + 128 * sin(3.1415 * x / 32.0));
		blue = (int)(128.0 + 128 * sin(3.1415 * x / 64.0));
		vars->palet[x] = rgb_to_int(red, green, blue);
		x++;
	}
}

int	palette(int	iter, int max_iter)
{
	int		c1;
	int		c2;
	double	max_iter_d;

	max_iter_d = (double)max_iter;
	c1 = 0x000000FF;
	c2 = 0x00FF0000;
	return (iter * ((c2 - c1) / max_iter_d));
}

int	smooth_color(t_vars *vars)
{
	double	log_zn;
	double	nu;
	int	color1;
	int	color2;
	
	log_zn = log(sqr_modul(vars->z)) / 2.;
	nu = log(log_zn / log(2.)) / log(2.);
	color1 = vars->palet[vars->i];
	//return color1;
	color2 = vars->palet[vars->i + 1];
	//return (lin_inter(color1, color2, fmod(vars->i, 1)));
	return (lin_inter(color1, color2, fmod(vars->i + 1 - nu, 1.)));
}

double	lin_inter(double c1, double c2, double i)
{
	return (c1 + i * (c2 - c1));
}
