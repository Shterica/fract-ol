#include "fractol.h"

t_vars	*ft_error_handler(void)
{
	printf("%s\n", "dai argumenti eblan");
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i += 1;
	}
	res = s1[i] - s2[i];
	return (res);
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

	(void)ac;
	(void)av;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->next_z = &next_z_mandel;
	vars->next_der = &next_der_mandel;
	vars->init = &init_mandel;
	vars->point_color = &fractal_point_color;
	return (vars);
}

t_vars	*ft_julia_parser(int ac, char **av)
{
	t_vars *vars;

	(void)ac;
	(void)av;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->c = complex(-0.8, 0.156);
	vars->next_z = &next_z_mandel;
	vars->next_der = &next_der_mandel;
	vars->init = &init_julia;
	vars->point_color = &fractal_point_color;
	return (vars);
}