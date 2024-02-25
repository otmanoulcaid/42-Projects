#include "../fdf.h"

void	ft_throw(char *strerr)
{
	ft_putendl_fd(strerr, 2);
	exit(EXIT_FAILURE);
}

void	faillure(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		(free(str[i]), str[i] = NULL);
	free(str);
}
