#include "fractol.h"

void	init_vars_mandel(t_vars *vars)
{
	vars->x0 = vars->c.x - 0.0002;
	vars->x1 = vars->c.x + 0.0002;
	vars->y0 = vars->c.y - 0.00015;
	vars->y1 = vars->c.y + 0.00015;
	vars->window_width = 240 * 4;
	vars->window_height = 240 * 3;
	vars->max_i = 1000;
	vars->col_hz = 1;
	create_palette(vars);
}

void	init_vars_default_mandel(t_vars *vars)
{
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -1.5;
	vars->y1 = 1.5;
	vars->window_width = 240 * 4;
	vars->window_height = 240 * 3;
	vars->max_i = 1000;
	vars->col_hz = 1;
	create_palette(vars);
}

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