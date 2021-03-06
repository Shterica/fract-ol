#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pain_ting(t_vars *vars)
{
	int			yp;
	int			xp;
	int			color;
	t_complex	p;

	xp = 0;
	while (xp < vars->window_width)
	{
		yp = 0;
		while (yp < vars->window_height)
		{
			p.x = ((vars->x1 - vars->x0) / vars->window_width) * xp + vars->x0;
			p.y = ((vars->y1 - vars->y0) / vars->window_height) \
			 * (-yp) + vars->y1;
			color = vars->point_color(vars, p);
			my_mlx_pixel_put(vars, xp, yp, color);
			yp++;
		}
		xp++;
	}
	mlx_put_image_to_window(vars->mlx_pnt, vars->window_pnt, vars->img, 0, 0);
}
