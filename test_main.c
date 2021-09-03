#include <mlx.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_vars
{
	void	*mlx_pnt;
	void	*window_pnt;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		window_width;
	int		window_height;
	double	x0;
	double	x1;
	double	y0;
	double	y1;
}				t_vars;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

void	init_list(t_vars *vars)
{
	double	cx = 0.001643721971153;
	double	cy = 0.822467633298876;
	vars->x0 = cx - 0.0001;
	vars->x1 = cx + 0.0001;
	vars->y0 = cy - 0.0001;
	vars->y1 = cy + 0.0001;

	vars->window_width = 200 * 4;
	vars->window_height = 200 * 4;
}

int		palette(int	iter, int max_iter)
{
	int c1;
	int c2;
	double max_iter_d;

	max_iter_d = (double)max_iter;
	
	c1 = 0x000000FF;
	c2 = 0x00FF0000;
	return(iter * ((c2 - c1) / max_iter_d));
}

double	lin_inter(double c1, double c2, double i)
{
	return (c1 + i * (c2 - c1));
}

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
	max_i = 10000;
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

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_pnt, vars->img);
	mlx_destroy_window(vars->mlx_pnt, vars->window_pnt);
	free(vars->mlx_pnt);
	//mlx_destroy_display(vars->mlx_pnt);
	exit(0);
}

void	pain_ting(t_vars *vars)
{
	int	yp;
	int	xp;
	int	color;
	t_complex	c;

	xp = 0;
	while (xp < vars->window_width)
	{
		yp = 0;
		while (yp < vars->window_height)
		{
			c.x = ((vars->x1 - vars->x0) / vars->window_width) * xp + vars->x0;
			c.y = ((vars->y1 - vars->y0) / vars->window_height) * (-yp) + vars->y1;
			color = Mandelbrot(c);
			my_mlx_pixel_put(vars, xp, yp, color);
			yp++;
		}
		xp++;
	}
	mlx_put_image_to_window(vars->mlx_pnt, vars->window_pnt, vars->img, 0, 0);
}

void	zoom_in(int x, int y, t_vars *vars)
{
	double	x_length;
	double	y_length;

	x_length = vars->x1 - vars->x0;
	y_length = vars->y1 - vars->y0;
	vars->x1 -= x_length * 0.05;
	vars->x0 += x_length * 0.05;
	vars->y1 -= y_length * 0.05;
	vars->y0 += y_length * 0.05;
	pain_ting(vars);
}

void	zoom_out(int x, int y, t_vars *vars)
{
	double	x_length;
	double	y_length;

	x_length = vars->x1 - vars->x0;
	y_length = vars->y1 - vars->y0;
	vars->x1 += x_length * 0.05;
	vars->x0 -= x_length * 0.05;
	vars->y1 += y_length * 0.05;
	vars->y0 -= y_length * 0.05;
	pain_ting(vars);
}

void	move_left(t_vars *vars)
{
	double	x_length;

	x_length = vars->x1 - vars->x0;
	vars->x1 -= x_length * 0.05;
	vars->x0 -= x_length * 0.05;
	pain_ting(vars);
}

void	move_up(t_vars *vars)
{
	double	y_length;

	y_length = vars->y1 - vars->y0;
	vars->y1 += y_length * 0.05;
	vars->y0 += y_length * 0.05;
	pain_ting(vars);
}

void	move_right(t_vars *vars)
{
	double	x_length;

	x_length = vars->x1 - vars->x0;
	vars->x1 += x_length * 0.05;
	vars->x0 += x_length * 0.05;
	pain_ting(vars);
}

void	move_down(t_vars *vars)
{
	double	y_length;

	y_length = vars->y1 - vars->y0;
	vars->y1 -= y_length * 0.05;
	vars->y0 -= y_length * 0.05;
	pain_ting(vars);
}

int	button_pars(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close(vars);
	else if (keycode == 65361)
		move_left(vars);
	else if (keycode == 65362)
		move_up(vars);
	else if (keycode == 65363)
		move_right(vars);
	else if (keycode == 65364)
		move_down(vars);
}

int	mouse_pars(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		zoom_in(x, y, vars);
	else if (button == 5)
		zoom_out(x, y, vars);
}

int main()
{
	t_vars		vars;

	init_list(&vars);

	vars.mlx_pnt = mlx_init();
    vars.window_pnt = mlx_new_window(vars.mlx_pnt, vars.window_width, vars.window_height, "test");
    vars.img = mlx_new_image(vars.mlx_pnt, vars.window_width, vars.window_height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	pain_ting(&vars);
	//mlx_put_image_to_window(vars.mlx_pnt, vars.window_pnt, vars.img, 0, 0);
	mlx_key_hook(vars.window_pnt, button_pars, &vars);
	mlx_mouse_hook(vars.window_pnt, mouse_pars, &vars);
	mlx_loop(vars.mlx_pnt);
	return (0);
}