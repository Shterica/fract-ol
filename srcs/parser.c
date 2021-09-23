#include "fractol.h"

t_vars	*ft_error_handler(void)
{
	printf("%s\n", "Error: invalid argument");
	printf("%s\n", "Please, enter arguments as follows:");
	printf("%s", "For Mandelbrot set enter './fractol mandelbrot'.");
	printf("%s\n", " Optionally you can enter parameters for a desired point.");
	printf("%s", "For Julia set enter './fractol julia' and two point parameters.");
	printf("%s\n", " Default parameters for Julia set are: -0.8 0.156");
	printf("%s\n", "For Collatz fractal enter './fractol collatz'");
	return (NULL);
}


t_vars	*argument_parser(int ac, char **av)
{
	t_vars *vars;

	vars = NULL;
	if (ac < 2)
		return (ft_error_handler());
	if (!(ft_strcmp(av[1], "mandelbrot")))
		vars = ft_mandelbrot_parser(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "julia"))
		vars = ft_julia_parser(ac - 2, av + 2);
	/*else if (!ft_strcmp(av[1], "collatz"))
		vars = ft_collatz_parser(ac - 2, av + 2);
	*/
	if (!vars)
		return (ft_error_handler());
	return (vars);
}

t_vars	*ft_mandelbrot_parser(int ac, char **av)
{
	t_vars *vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	if (ac == 2)
	{
		vars->c = complex(ft_atod(av[0]), ft_atod(av[1]));
		init_vars_mandel(vars);
	}
	else
		init_vars_default(vars);
	vars->next_z = &next_z_mandel;
	vars->next_der = &next_der_mandel;
	vars->init = &init_mandel;
	vars->point_color = &fractal_point_color;
	return (vars);
}

t_vars	*ft_julia_parser(int ac, char **av)
{
	t_vars *vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	if (ac == 2)
		vars->c = complex(ft_atod(av[0]), ft_atod(av[1]));
	else
		vars->c = complex(-0.8, 0.156);
	vars->next_z = &next_z_mandel;
	vars->next_der = &next_der_mandel;
	vars->init = &init_julia;
	vars->point_color = &fractal_point_color;
	init_vars_julia(vars);
	return (vars);
}