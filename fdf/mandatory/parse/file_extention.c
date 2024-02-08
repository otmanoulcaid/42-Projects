#include "../fdf.h"

int	valid_arg(char **av, t_fdf *data)
{
	char	*s;

	s = NULL;
	if (av)
		s = ft_strrchr(*av, '.');
	if (s && !ft_strncmp(s + 1, "fdf", 3))
	{
		data->file = ft_strdup(*av);
		if (!data->file)
			ft_throw("ERROR STRDUP");
		return (1);
	}
	return (0);
}
