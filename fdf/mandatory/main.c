
#include "fdf.h"

#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

void	check(void)
{
	system("leaks fdf");
}

void	init_mlx_content(t_fdf *data)
{
	data->is_iso = 1;
	data->zoom = 40;
	data->x_scale = MAX_WIDTH / 2;
	data->y_scale = MAX_HEIGH / 3;
	data->z_scale = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gama = 0;
}

int	main(int ac, char **av)
{
	t_fdf	data;

	// atexit(check);
	if (ac != 2 || !valid_arg(av + 1, &data) || !valid_content(&data, av[1]))
		ft_throw("invalid data");
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_throw("init Error");
	data.win_ptr = mlx_new_window(data.mlx, MAX_WIDTH, MAX_HEIGH, "FDF");
	if (!data.win_ptr)
		(free(data.mlx), ft_throw("error creating window"));
	data.map->img = mlx_new_image(data.mlx, MAX_WIDTH, MAX_HEIGH);
	if (!data.map->img)
		ft_throw("ERROR creating image");
	data.map->img_addr = mlx_get_data_addr(data.map->img, &data.map->bbp,
	&data.map->win_x, &data.map->endian);
	init_mlx_content(&data);
	fdf(&data);
	mlx_hook(data.win_ptr, 2, 0, &event_handling, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
