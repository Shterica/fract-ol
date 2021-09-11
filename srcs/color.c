#include "fractol.h"

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
