#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->size_x + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}