/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:18 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/28 13:47:40 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initial_state(t_fdf *data)
{
	if (data->is_iso)
		init_mlx_content(data);
	else
	{
		init_mlx_content(data);
		data->is_iso = 0;
	}
	data->zoom = get_zoom(data);
}

static void	rotating(int key, t_fdf *data)
{
	if (key == ROT_X_DOWN)
		data->alpha -= 0.05;
	if (key == ROT_X_UP)
		data->alpha += 0.05;
	if (key == ROT_Y_L)
		data->beta -= 0.05;
	if (key == ROT_Y_R)
		data->beta += 0.05;
	if (key == ROT_Z_L)
		data->gama -= 0.05;
	if (key == ROT_Z_R)
		data->gama += 0.05;
}

static void	translating(int key, t_fdf *data)
{
	if (key == MOVE_RIGHT)
		data->x_scale += 10;
	else if (key == MOVE_LEFT)
		data->x_scale -= 10;
	else if (key == MOVE_UP)
		data->y_scale -= 10;
	else if (key == MOVE_DOWN)
		data->y_scale += 10;
	else if (key == ALT_UP)
		data->z_scale++;
	else if (key == ALT_DOWN)
		data->z_scale--;
}

int	event_handling(int key, t_fdf *data)
{
	if (key == INIT)
		initial_state(data);
	else if (key == MOVE_RIGHT || key == MOVE_LEFT || key == MOVE_UP
		|| key == MOVE_DOWN || key == ALT_UP || key == ALT_DOWN)
		translating(key, data);
	else if (key == ROT_X_DOWN || key == ROT_X_UP || key == ROT_Y_L
		|| key == ROT_Y_R || key == ROT_Z_R || key == ROT_Z_L)
		rotating(key, data);
	else if (key == PROJECT && data->is_iso)
		data->is_iso = 0;
	else if (key == PROJECT && !data->is_iso)
		data->is_iso = 1;
	else if (key == ZOOM_IN)
		data->zoom++;
	else if (key == ZOOM_OUT)
		data->zoom--;
	else if (key == QUIT)
		exit(EXIT_SUCCESS);
	fdf(data);
	return (1);
}
