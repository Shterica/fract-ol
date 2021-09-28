#include "fractol.h"

t_complex	c_sin(t_complex c)
{
	return (complex(sin(c.x) * cosh(c.y), cos(c.x) * sinh(c.y)));
}

t_complex	c_div(t_complex a, t_complex b)
{
	double	mod;

	mod = sqr_modul(b);
	return (complex((a.x * b.x + a.y * b.y) / mod, \
	(a.y * b.x - a.x * b.y) / mod));
}
