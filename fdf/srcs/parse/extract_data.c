/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:59 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 13:47:59 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parse_line(t_fdf *data, char**line, int index, int words)
{
	int		i;

	if (!data->map->width && words)
		data->map->width = words;
	else if (data->map->width != words || (data->map->width && !words))
		ft_throw("invalid map");
	data->map->cord[index] = (t_point *)malloc(sizeof(t_point) * words);
	if (!data->map->cord[index])
		ft_throw("invalid map");
	i = 0;
	while (line[i])
	{
		if (!in_hexa(line[i]))
			(faillure(line), ft_throw("map should contain only numbers"));
		data->map->cord[index][i].z = ft_atoi(line[i]);
		data->map->cord[index][i].y = index;
		data->map->cord[index][i].x = i;
		if (ft_strchr(line[i++], ','))
			data->map->cord[index][i].color
				= ft_atoi_base(ft_strchr(line[i - 1], 'x') + 1);
		else
			data->map->cord[index][i - 1].color = 0xf0f0f0;
	}
}

void	parse_map(t_fdf *data, char *file)
{
	char	**splited_line;
	char	**map_line;
	int		j;
	int		words;

	j = 0;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		ft_throw("open parse_map");
	map_line = get_lines(data->fd, &words);
	init_fdf(data, file, words);
	while (map_line[j])
	{
		splited_line = ft_split(map_line[j], ' ', &words);
		if (!splited_line)
			ft_throw("split parse_map");
		parse_line(data, splited_line, j, words);
		(faillure(splited_line), splited_line = NULL);
		(free(map_line[j]), map_line[j] = NULL);
		j++;
	}
	data->zoom = get_zoom(data);
	free(map_line);
	if (close(data->fd) < 0)
		ft_throw(strerror(errno));
}
