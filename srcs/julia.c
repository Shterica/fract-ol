#include "fractol.h"

int		julia(t_vars *vars)
{
	int		color;
	//int		pow;
	//double	V;

	vars->i = 0;
	vars->der = complex(1, 0);
	color = 0x00;
	//pow = 1;
	while (vars->i < vars->max_i)
	{
		if (sqr_modul(vars->der) < 0.0000002)
			break ;
		if (sqr_modul(vars->z) > (1 << 16))
		{
			color = vars->palet[vars->i];
			//V = log(sqr_modul(vars->z)) / pow;
			//color = (log(V) + vars->i) * 1000;
			break ;
		}
		next_der(vars);
		next_z(vars);
		//pow *= 2;
		vars->i++;
	}
	return (color);
}