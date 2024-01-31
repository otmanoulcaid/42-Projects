#include "../fdf.h"

void	fdf(t_fdf *data)
{
	if (data)
		printf("(%d)sucess\n", data->size_x);
	mlx_loop(data->mlx);
	return ;
}
