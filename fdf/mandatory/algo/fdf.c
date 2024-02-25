#include "../fdf.h"
#include <stdlib.h>

void	draw_menu(t_fdf *data)
{
	int	i;

	i = 0;
	mlx_string_put(data->mlx, data->win_ptr, 100, 50, 0xffffff,"CONTROL PANEL");
	while (i < MAX_WIDTH / 5)
		mlx_pixel_put(data->mlx, data->win_ptr, i++, 120, 0xffffff);
	mlx_string_put(data->mlx, data->win_ptr, 25, 150, 0xffffff, "- 0     : set the altitude down");
	mlx_string_put(data->mlx, data->win_ptr, 25, 180, 0xffffff, "- 5     : set the altitude up");
	mlx_string_put(data->mlx, data->win_ptr, 25, 210, 0xffffff, "- >	    : move to the right");
	mlx_string_put(data->mlx, data->win_ptr, 25, 240, 0xffffff, "- <	    : move to the left");
	mlx_string_put(data->mlx, data->win_ptr, 25, 270, 0xffffff, "- space : initial stat");
	mlx_string_put(data->mlx, data->win_ptr, 25, 300, 0xffffff, "- v     : move down");
	mlx_string_put(data->mlx, data->win_ptr, 25, 330, 0xffffff, "- ^     : move up");
	mlx_string_put(data->mlx, data->win_ptr, 25, 360, 0xffffff, "- esc   : quit");
}

void draw_bg(t_fdf *data)
{
	int *img;
	int i;
	
	bzero(data->map->img_addr, MAX_HEIGH * MAX_WIDTH);
	i = 0;
	img = (int *)data->map->img_addr;
	while (i < MAX_HEIGH * MAX_WIDTH)
	{
		if (i % MAX_WIDTH < MAX_WIDTH / 5)
			img[i++] = 0x18171d;
		else
			img[i++] = 0x242424;
	}
}

void	fdf(t_fdf *data)
{
	t_point	**matrice;
	int		x;
	int		y;

	matrice = data->map->cord;
	draw_bg(data);
	y = 0;
	matrice = data->map->cord;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (y < data->map->height - 1)
				bresenham(matrice[y + 1][x], matrice[y][x], data);
			if (x < data->map->width - 1)
				bresenham(matrice[y][x], matrice[y][x+1], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->map->img, 0, 0);
	draw_menu(data);
}

