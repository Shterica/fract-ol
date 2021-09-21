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

double	lin_inter(double c1, double c2, double i)
{
	return (c1 + i * (c2 - c1));
}
