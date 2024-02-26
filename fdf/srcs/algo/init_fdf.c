/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:42:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 00:09:20 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_zoom(t_fdf *data)
{
	if (data->map->width < 8)
		return (30);
	else if (data->map->width < 10)
		return (25);
	else if (data->map->width < 20)
		return (20);
	else if (data->map->width < 30)
		return (15);
	else if (data->map->width < 40)
		return (10);
	return (4);
}

void	init_mlx_content(t_fdf *data)
{
	data->is_iso = 1;
	data->zoom = get_zoom(data);
	data->x_scale = MAX_WIDTH / 2;
	data->y_scale = MAX_HEIGH / 3;
	data->z_scale = 3;
	data->alpha = M_PI;
	data->beta = M_PI;
	data->gama = M_PI;
}