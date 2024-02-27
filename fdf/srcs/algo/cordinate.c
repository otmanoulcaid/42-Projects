/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:27 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 17:31:35 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x(t_point *p1, t_point *p2, t_fdf *data)
{
	int	prev_y;

	prev_y = p1->y;
	p1->y = prev_y * cos(data->alpha) - p1->z * sin(data->alpha);
	p1->z = prev_y * sin(data->alpha) + p1->z * cos(data->alpha);
	prev_y = p2->y;
	p2->y = prev_y * cos(data->alpha) - p2->z * sin(data->alpha);
	p2->z = prev_y * sin(data->alpha) + p2->z * cos(data->alpha);
}

void	rotate_y(t_point *p1, t_point *p2, t_fdf *data)
{
	int	prev_x;

	prev_x = p1->x;
	p1->x = prev_x * cos(data->beta) + p1->z * sin(data->beta);
	p1->z = p1->z * cos(data->beta) - prev_x * sin(data->beta);
	prev_x = p2->x;
	p2->x = prev_x * cos(data->beta) + p2->z * sin(data->beta);
	p2->z = p2->z * cos(data->beta) - prev_x * sin(data->beta);
}

void	rotate_z(t_point *p1, t_point *p2, t_fdf *data)
{
	int	prev_x;

	prev_x = p1->x;
	p1->x = prev_x * cos(data->gama) - p1->y * sin(data->gama);
	p1->y = prev_x * sin(data->gama) + p1->y * cos(data->gama);
	prev_x = p2->x;
	p2->x = prev_x * cos(data->gama) - p2->y * sin(data->gama);
	p2->y = prev_x * sin(data->gama) + p2->y * cos(data->gama);
}

void	iso(t_point *p, t_fdf *data)
{
	int	x;

	x = (p->x - p->y) * cos(M_PI / 6);
	p->y = (p->x + p->y) * sin(M_PI / 6) - p->z;
	p->x = x;
}

void	set_coordinate(t_point *p1, t_point *p2, t_fdf *data)
{
	p1->x -= data->map->width / 2;
	p1->y -= data->map->height / 2;
	p2->x -= data->map->width / 2;
	p2->y -= data->map->height / 2;
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p1->z *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
	p2->z *= data->zoom;
	if (p1->z)
		p1->z *= data->z_scale * 0.05;
	if (p2->z)
		p2->z *= data->z_scale * 0.05;
	rotate_x(p1, p2, data);
	rotate_y(p1, p2, data);
	rotate_z(p1, p2, data);
	if (data->is_iso)
		(iso(p1, data), iso(p2, data));
	p1->x += 1080 + data->x_scale;
	p1->y += 500 + data->y_scale;
	p2->x += 1080 + data->x_scale;
	p2->y += 500 + data->y_scale;
}
