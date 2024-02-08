#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->size_x + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	link_pixels(t_fdf *data, int x, int y)
// {

// }

void	put_pixels_on_image(t_fdf *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while(i < data->size_y)
	{
		j = 0;
		while (j < data->size_y)
		{
			x = ((sqrt((double)3) / 2) * i) - ((double)0.5 * j);
			y = ((sqrt((double)3) / 2) * i) + ((double)0.5 * j);
			my_mlx_pixel_put(data, x * GRAND + 200, y * GRAND + 150, 0xFF00FF);
			// link_pixels(data, x, y);
			j++;
		}
		i++;
	}
}

void	fdf(t_fdf *data)
{
	int	bpp;
	int	endian;
	int	s_x;

	data->img_addr = mlx_get_data_addr(data->img, &bpp, &s_x, &endian);
	put_pixels_on_image(data);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img,0 , 0);
	mlx_loop(data->mlx);
	return ;
}



// void	put_pixels(t_fdf *data, int j)
// {
// 	int	x;

// 	x = 0.1 * GRAND * data->size_x;
// 	while (x < 0.9 * GRAND * data->size_x)
// 		mlx_pixel_put(data->mlx, data->win_ptr, x++, j, 0xff14ff);
// }
// int	x;
// int	start_x = 0.1 * GRAND * data->size_x;
// int	start_y = 0.1 * GRAND * data->size_y;
// int	y = start_y;
// while (y <= 0.9 * GRAND * data->size_y)
// 	{
// 		x = start_x;
// 		if ((y - start_y) % start_y == 0)
// 			put_pixels(data, y);
// 		while(x <= 0.9 * GRAND * data->size_x)
// 		{
// 			mlx_pixel_put(data->mlx, data->win_ptr, x, y, 0xff11ff);
// 			x += start_x;
// 		}
// 		y++;
// 	}