#include "fractol.h"

int		Mandelbrot(t_complex c)
{
	t_complex z;
	t_complex zsq;
	t_complex der;
	t_complex new_der;
	int i;
	int max_i;
	int color;
	int	color1;
	int	color2;
	double	log_zn;
	double	nu;

	z = c;
	zsq.x = z.x * z.x;
	zsq.y = z.y * z.y;
	der.x = 1;
	der.y = 0;
	i = 0;
	max_i = 5000;
	color = 0x0;
	while (i < max_i)
	{
		if (der.x * der.x + der.y * der.y < 0.001)
		{
			color = 0x0;
			break ;
		}
		else if (zsq.x + zsq.y > (1 << 16))
		{
			log_zn = log(zsq.x + zsq.y) / 2;
			nu = log(log_zn / log(2)) / log(2);
			color1 = palette(i, max_i);
			color2 = palette(i + 1, max_i);
			color = lin_inter(color1, color2, fmod(i + 1 - nu, 1));
			break ;
		}
		new_der.x = 2 * (z.x * der.x - z.y * der.y);
		new_der.y = 2 * (z.x * der.y + z.y * der.x);
		der = new_der;
		z.y = (z.x + z.x) * z.y + c.y;
		z.x = zsq.x - zsq.y + c.x;
		zsq.x = z.x * z.x;
		zsq.y = z.y * z.y;
		i++;
	}
	return (color);
}