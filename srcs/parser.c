#include "fractol.h"
#include "keys.h"

int	button_pars(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
		closing(vars);
	else if (keycode == K_LEFT_ARROW)
		move_left(vars);
	else if (keycode == K_UP_ARROW)
		move_up(vars);
	else if (keycode == K_RIGHT_ARROW)
		move_right(vars);
	else if (keycode == K_DOWN_ARROW)
		move_down(vars);
	return (0);
}

int	mouse_pars(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		zoom_in(x, y, vars);
	else if (button == 5)
		zoom_out(x, y, vars);
	return (0);
}
