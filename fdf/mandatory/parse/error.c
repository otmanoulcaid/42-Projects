#include "../../fdf.h"

void	ft_throw(char *strerr)
{
	ft_putendl_fd(strerr, 2);
	exit(EXIT_FAILURE);
}
