/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:42:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 17:48:33 by ooulcaid         ###   ########.fr       */
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
	return (1);
}

void	init_mlx_content(t_fdf *data)
{
	data->is_iso = 1;
	data->zoom = get_zoom(data);
	data->x_scale = 0;
	data->y_scale = 0;
	data->z_scale = 15;
	data->alpha = M_PI;
	data->beta = M_PI;
	data->gama = M_PI;
}
