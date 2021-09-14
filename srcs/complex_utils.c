#include "fractol.h"

t_complex	complex(double x, double y)
{
	t_complex c;

	c.x = x;
	c.y = y;
	return (c);
}

double		sqr_modul(t_complex c)
{
	return (c.x * c.x + c.y * c.y);
}
