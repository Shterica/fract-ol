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

double	ft_atod(char *s)
{
	long double res;
	int minus;
	double div;
	int i;

	res = 0.0;
	i = 0;
	div = 10;
	minus = 0;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || \
			s[i] == '\r' || s[i] == '\t' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			minus = 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res + (s[i] - 48) / div;
		div *= 10;
		i++;
	}
	if (minus)
		res *= -1;
	return (res);
}