#include "fractol.h"

void	next_der_collatz(t_vars *vars)
{
	t_complex first;
	t_complex sinus;
	t_complex cosinus;

	first = complex(5 * vars->z.x + 2, 5 * vars->z.y);
	first = complex(first.x * PI, first.y * PI);
	sinus = c_sin(complex(vars->z.x * PI, vars->z.y * PI));
	first = c_mult(first, sinus);
	cosinus = c_cos(complex(vars->z.x * PI, vars->z.y * PI));
	cosinus = complex(5 * cosinus.x, 5 * cosinus.y * 5);
	first = c_sub(first, cosinus);
	first = complex((first.x + 7) / 4, first.y / 4);
	vars->der = c_mult(vars->der, first);
}

void	init_collatz(t_vars *vars, t_complex p)
{
	vars->z = p;
	vars->i = 0;
	vars->der = complex(1, 0);
}

void	init_vars_default_collatz(t_vars *vars)
{
	vars->x0 = -2;
	vars->x1 = 2;
	vars->y0 = -1.5;
	vars->y1 = 1.5;
	vars->window_width = 240 * 4;
	vars->window_height = 240 * 3;
	vars->max_i = 300;
	vars->col_hz = 2;
	create_palette(vars);
}

void	next_z_collatz(t_vars *vars)
{
	t_complex first;
	t_complex second;
	t_complex cosinus;

	first = complex(7 * vars->z.x + 2, 7 * vars->z.y);
	second = complex(5 * vars->z.x + 2, 5 * vars->z.y);
	cosinus = c_cos(complex(vars->z.x * PI, vars->z.y * PI));
	cosinus = c_mult(cosinus, second);
	first = c_sub(first, cosinus);
	vars->z = complex(first.x / 4, first.y / 4);
}