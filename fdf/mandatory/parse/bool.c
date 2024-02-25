#include "../fdf.h"

int	ternary(int boolean, int a, int b)
{
	return ((boolean * a) + (!boolean * b));
}

int	is_all_num(char *str)
{
	while (*str && *str != '\n')
	{
		while (*str && *str == ' ')
			str++;
		if (*str && (*str < '0' || *str > '9'))
			return (0);
		if (*str)
			str++;
	}
	return (1);
}

int	valid_arg(char **av, t_fdf *data)
{
	char	*s;

	s = NULL;
	if (av)
		s = ft_strrchr(*av, '.');
	if (s && !ft_strncmp(s + 1, "fdf", 3))
		return (1);
	return (0);
}
