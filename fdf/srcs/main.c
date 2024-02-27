/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:28:06 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/25 19:28:06 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	t_fdf	data;

	atexit(check);
	if (ac != 2 || !valid_extention(av[1]))
		ft_throw("invalid data");
	parse_map(&data, av[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_throw("init Error");
	data.win_ptr = mlx_new_window(data.mlx, MAX_WIDTH, MAX_HEIGH, "FDF");
	if (!data.win_ptr)
		(free(data.mlx), ft_throw("error creating window"));
	data.map->img = mlx_new_image(data.mlx, MAX_WIDTH, MAX_HEIGH);
	if (!data.map->img)
		ft_throw("ERROR creating image");
	data.map->img_addr = mlx_get_data_addr(data.map->img, &data.map->bbp,
			&data.map->win_x, &data.map->endian);
	init_mlx_content(&data);
	fdf(&data);
	mlx_hook(data.win_ptr, 2, 0, &event_handling, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
