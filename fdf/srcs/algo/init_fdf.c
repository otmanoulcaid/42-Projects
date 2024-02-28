/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:42:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/28 13:48:51 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_fdf(t_fdf *data, char *file, int height)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		ft_throw(strerror(errno));
	data->map->height = height;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_throw("init Error");
	data->win_ptr = mlx_new_window(data->mlx, MAX_WIDTH, MAX_HEIGH, "FDF");
	if (!data->win_ptr)
		(free(data->mlx), ft_throw("error creating window"));
	data->map->img = mlx_new_image(data->mlx, MAX_WIDTH, MAX_HEIGH);
	if (!data->map->img)
		ft_throw("ERROR creating image");
	data->map->img_addr = mlx_get_data_addr(data->map->img, &data->map->bbp,
			&data->map->win_x, &data->map->endian);
	data->map->cord = malloc(sizeof(t_point *) * data->map->height);
	if (!data->map->cord)
		ft_throw(strerror(errno));
	data->map->width = 0;
}

void	init_mlx_content(t_fdf *data)
{
	errno = 0;
	data->is_iso = 1;
	data->zoom = 1;
	data->x_scale = 0;
	data->y_scale = 0;
	data->z_scale = 15;
	data->alpha = M_PI;
	data->beta = M_PI;
	data->gama = M_PI;
}
