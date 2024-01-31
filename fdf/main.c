#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2 || !valid_arg(av + 1, &data) || !valid_content_file(&data))
		ft_throw("invalid data");
	data.mlx = mlx_init();
	if (!data.mlx)
		perror("init Error");
	data.win_ptr = mlx_new_window(data.mlx, data.size_x * 60, data.size_y * 60, "FDF");
	if (!data.win_ptr)
		ft_throw("error creating window");
	fdf(&data);
	mlx_destroy_window(data.mlx, data.win_ptr);
	return (0);
}
