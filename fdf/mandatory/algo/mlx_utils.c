#include "../fdf.h"

int get_color(t_point *a, t_point *b)
{
	int color;

	color = 0xffffff;
	if (a->z || b->z)
		color = 0x00ff00;
	return (color);
}

void	my_mlx_pixel_put(t_fdf *data, t_point *a, t_point *b)
{
	int			i;
	static int	j;
	int 		color;

	if (a->x > MAX_WIDTH / 5 && a->x < MAX_WIDTH && a->y > 0 && a->y < MAX_HEIGH)
	{
		color = get_color(a, b);
		if ((a->z && !b->z) || (!a->z && b->z))
		{
			j++;
			color += j;
		}
		i = (a->y * data->map->win_x) + (a->x * data->map->bbp / 8);
		data->map->img_addr[i] = color;
		data->map->img_addr[++i] = color >> 8;
		data->map->img_addr[++i] = color >> 16;
	}
}
