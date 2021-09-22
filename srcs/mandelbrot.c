#include "fractol.h"

void	next_der_mandel(t_vars *vars)
{
	t_complex new_der;

	new_der.x = 2 * (vars->z.x * vars->der.x - vars->z.y * vars->der.y);
	new_der.y = 2 * (vars->z.x * vars->der.y + vars->z.y * vars->der.x);
	vars->der = new_der;
}

void	next_z_mandel(t_vars *vars)
{
	t_complex	z;
	t_complex	new_z;
	t_complex	c;

	z = vars->z;
	c = vars->c;
	new_z.y = (z.x + z.x) * z.y + c.y;
	new_z.x = z.x * z.x - z.y * z.y + c.x;
	vars->z = new_z;
}

void	init_mandel(t_vars *vars, t_complex p)
{
	vars->c = p;
	vars->z = vars->c;
	vars->der = complex(1, 0);
	vars->i = 1;
}