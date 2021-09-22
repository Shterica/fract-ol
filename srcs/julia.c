#include "fractol.h"

void	init_julia(t_vars *vars, t_complex p)
{
	vars->z = p;
	vars->i = 0;
	vars->der = complex(1, 0);
}