#include "fractol.h"

int	button_pars(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
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
	return (0);
}

int	mouse_pars(int button, int x, int y, t_vars *vars)
{
	printf("%d\n", button);
	if (button == 4)
		zoom_in(x, y, vars);
	else if (button == 5)
		zoom_out(x, y, vars);
	return (0);
}