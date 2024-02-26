/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:37:20 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 10:37:20 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

void	draw_menu(t_fdf *data)
{
	int		width;
	int		height;

	data->map->c_panel = mlx_xpm_file_to_image(data->mlx,
			"srcs/algo/control_panel.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win_ptr,
		data->map->c_panel, 0, 0);
}

void	draw_bg(t_fdf *data)
{
	int	*img;
	int	i;

	ft_bzero(data->map->img_addr, MAX_HEIGH * MAX_WIDTH);
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
				bresenham(matrice[y][x], matrice[y][x + 1], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->map->img, 0, 0);
	draw_menu(data);
}
