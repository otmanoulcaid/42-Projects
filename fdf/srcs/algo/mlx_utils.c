/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:46:46 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 17:54:09 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_color(t_point *a, t_point *b)
{
	int	color;

	color = 0xffffff;
	if (a->z || b->z)
		color = 0x00f0f0;
	return (color);
}

void	my_mlx_pixel_put(t_fdf *data, t_point *a, t_point *b)
{
	int			i;
	static int	j;
	int			color;

	if (a->x > MAX_WIDTH / 5 && a->x < MAX_WIDTH && a->y > 0
		&& a->y < MAX_HEIGH)
	{
		color = get_color(a, b);
		if ((a->z && b->z) || (!a->z && b->z))
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
