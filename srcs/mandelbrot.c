#include "fractol.h"

static void	next_der_mandel(t_vars *vars)
{
	t_complex new_der;

	new_der.x = 2 * (vars->z.x * vars->der.x - vars->z.y * vars->der.y);
	new_der.y = 2 * (vars->z.x * vars->der.y + vars->z.y * vars->der.x);
	vars->der = new_der;
}

static void	next_z_mandel(t_vars *vars)
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

static int	smooth_color(t_vars *vars)
{
	double	log_zn;
	double	nu;
	int	color1;
	int	color2;
	
	log_zn = log(sqr_modul(vars->z)) / 2;
	nu = log(log_zn / log(2)) / log(2);
	color1 = palette(vars->i, vars->max_i);
	color2 = palette(vars->i + 1, vars->max_i);
	return (lin_inter(color1, color2, fmod(vars->i + 1 - nu, 1)));
}

int		mandelbrot(t_vars *vars)
{
	int color;
	
	vars->z = vars->c;
	vars->der = complex(1, 0);
	vars->i = 0;
	vars->max_i = 15000;
	color = 0x0;
	while (vars->i < vars->max_i)
	{
		if (sqr_modul(vars->der) < 0.002)
			break ;
		else if (sqr_modul(vars->z) > (1 << 16))
		{
			color = smooth_color(vars);
			break ;
		}
		next_der_mandel(vars);
		next_z_mandel(vars);
		vars->i++;
	}
	return (color);
}