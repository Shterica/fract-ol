#include "fractol.h"

t_complex		c_sin(t_complex c)
{
	return (complex(sin(c.x) * cosh(c.y), cos(c.x) * sinh(c.y)));
}