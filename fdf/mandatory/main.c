#include "fdf.h"

void	check()
{
	system("leaks fdf");
}


void	init_fdf_content(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_throw("init Error");
	data->win_ptr = mlx_new_window(data->mlx, MAX_WIDTH, MAX_HEIGH, "FDF");
	if (!data->win_ptr)
		(free(data->mlx), ft_throw("error creating window"));
	data->img = mlx_new_image(data->mlx, MAX_WIDTH, MAX_HEIGH);
	if (!data->img)
		(free(data->mlx), free(data->win_ptr), ft_throw("ERROR creating image"));
}

int	main(int ac, char **av)
{
	t_fdf	data;

	atexit(check);
	if (ac != 2 || !valid_arg(av + 1, &data) || !valid_content_file(&data))
		ft_throw("invalid data");
	(init_fdf_content(&data), fdf(&data));
	return (0);
}

