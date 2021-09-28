#include "fractol.h"

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

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static double	ft_atof(char *s)
{
	double		div;
	int			i;
	long double	res;

	i = 0;
	res = 0.0;
	div = 10;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res + (s[i++] - 48) / div;
		div *= 10;
	}
	return (res);
}

double	ft_atod(char *s)
{
	long double	res;
	int			minus;
	int			i;

	res = 0.0;
	i = 0;
	minus = 1;
	while (ft_is_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			minus *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	if (s[i] == '.')
		res += ft_atof(s + i + 1);
	return (res * minus);
}

void	init_common_vars(t_vars *vars)
{
	vars->color_id = 0;
	vars->set_color[0] = 0x0;
	vars->set_color[1] = 0xC70039;
	vars->set_color[2] = 0x112336;
	vars->set_color[3] = 0x1B6E91;
	vars->set_color[4] = 0x0;
	vars->set_color[5] = 0x0;
	vars->color_offset[0] = 0;
	vars->color_offset[1] = -777;
	vars->color_offset[2] = 302;
	vars->color_offset[3] = 110;
	vars->color_offset[4] = 255;
	vars->color_offset[5] = 0;
}
