#include "fractol.h"

int		julia(t_complex z, t_complex c)
{
	int			i;
	int			i_max;
	t_complex	zsq;
	double		xtemp;

	i = 0;
	i_max = 10000;
	zsq.x = z.x * z.x;
	zsq.y = z.y * z.y;
	while (zsq.x + zsq.y < 16 && i < i_max)
	{
		xtemp = zsq.x - zsq.y;
		z.y = 2 * z.x * z.y + c.y;
		z.x = xtemp + c.x;
		zsq.x = z.x * z.x;
		zsq.y = z.y * z.y;
		i++;
	}
	if (i == i_max)
		return (0x0);
	else
		return (i_max - i);
}