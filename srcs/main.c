#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	*fractol;

	fractol = argument_parser(ac, av);
	if (fractol)
		ft_fractol(fractol);
	return (0);
}
