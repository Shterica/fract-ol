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

t_complex		c_mult(t_complex a, t_complex b)
{
	return (complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x));
}

t_complex		c_sub(t_complex a, t_complex b)
{
	return (complex(a.x - b.x, a.y - b.y));
}

t_complex		c_cos(t_complex c)
{
	return (complex(cos(c.x) * cosh(c.y), -sin(c.x) * sinh(c.y)));
}
