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

int	get_height(int fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		(height++, free(line), line = NULL);
		line = get_next_line(fd);
	}
	return (height);
}

static	void	init_fdf(t_fdf *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		ft_throw(strerror(errno));
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		ft_throw(strerror(errno));
	data->map->height = get_height(data->fd);
	data->map->cord = malloc(sizeof(t_point *) * data->map->height);
	if (!data->map->cord)
		ft_throw(strerror(errno));
	data->map->width = 0;
	if (close(data->fd) < 0)
		ft_throw(strerror(errno));
}

void	parse_line(t_fdf *data, char**line, int index,int words)
{
	int		i;

	if (!data->map->width)
		data->map->width = words;
	else if (data->map->width < words)
		ft_throw("invalid map");
	data->map->cord[index] = (t_point *)malloc(sizeof(t_point) * words);
	if (!data->map->cord[index])
		ft_throw("invalid map");
	i = 0;
	while (line[i])
	{
		data->map->cord[index][i].z = ft_atoi(line[i]);
		data->map->cord[index][i].y = index;
		data->map->cord[index][i].x = i;
		if (ft_strchr(line[i++], ','))
			data->map->cord[index][i].color =
				ft_atoi_base(ft_strchr(line[i - 1], 'x') + 1);
		else
			data->map->cord[index][i].color = 0xf0f0f0;
		free(line[i - 1]);
	}
	(free(line), line = NULL);
}

void	parse_map(t_fdf *data, char *file)
{
	char	*line;
	char	**splited_line;
	int		j;
	int		words;

	j = 0;
	init_fdf(data, file);
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		ft_throw(strerror(errno));
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		splited_line = ft_split(line, ' ', &words);
		if (!splited_line)
			ft_throw(strerror(errno));
		parse_line(data, splited_line, j++, words);
		(free(line), line = NULL);
	}
	if (close(data->fd) < 0)
		ft_throw(strerror(errno));
}
