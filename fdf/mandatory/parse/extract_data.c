#include "../fdf.h"
#include "../../get_next_line/get_next_line.h"

static	int	size_x(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		while (*line >= '0' && *line <= '9')
			line++;
		i++;
		while (*line && (*line < '0' || *line > '9'))
			line++;
	}
	return (i);
}

static	void	fill_nums(t_fdf *data)
{
	t_list	*tmp;
	char	**splited_line;
	int		i;
	int		j;

	tmp = data->map->list;
	i = 0;
	while (tmp)
	{
		splited_line = ft_split(tmp->data, ' ');
		if (!splited_line)
			ft_throw(strerror(errno));
		data->map->cord[i] = (t_point *)malloc(sizeof(t_point) * data->map->width);
		if (!data->map->cord[i++])
			(ft_throw(strerror(errno)), faillure(splited_line));
		j = 0;
		while (splited_line[j++])
		{
			data->map->cord[i - 1][j - 1].z = ft_atoi(splited_line[j - 1]);
			data->map->cord[i - 1][j - 1].y = i - 1;
			data->map->cord[i - 1][j - 1].x = j - 1;
		}
		tmp = tmp->next;
		(faillure(splited_line), splited_line = NULL);
	}
}

static	void	init_fdf(t_fdf *fdf, char *file)
{
	fdf->fd = open(file, O_RDONLY);
	if (!fdf->fd)
		ft_throw(strerror(errno));
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		ft_throw(strerror(errno));
	fdf->map->list = NULL;
	fdf->map->height = 0;
	fdf->map->width = 0;
}

int	valid_content(t_fdf *data, char *file)
{
	char	*line;
	t_list	*tmp;

	init_fdf(data, file);
	line = get_next_line(data->fd);
	if (!line)
		ft_throw("ERROR: (get_next_line1)");
	data->map->width = size_x(line);
	data->map->height = 0;
	while (line)
	{
		tmp = ft_lstnew(line);
		if (!tmp || !is_all_num(tmp->data))
			(ft_lstclear(&data->map->list, free),
				ft_throw("ERROR getting data from file"));
		(ft_lstadd_back(&data->map->list, tmp), data->map->height++,
			tmp->length = size_x(line));
		if (data->map->width != tmp->length)
			ft_throw("invalid file content");
		line = get_next_line(data->fd);
	}
	data->map->cord = (t_point **)malloc(sizeof(t_point *) * data->map->height);
	if (!data->map->cord)
		ft_throw(strerror(errno));
	return (close(data->fd), fill_nums(data), 1);
}
