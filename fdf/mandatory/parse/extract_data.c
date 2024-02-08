#include "../fdf.h"
#include "../../get_next_line/get_next_line.h"


static int	size_x(char *line)
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

static	int	is_all_num(char *str)
{
	while (*str && *str != '\n')
	{
		while (*str && *str == ' ')
			str++;
		if (*str && (*str < '0' || *str > '9'))
			return (0);
		if (*str)
			str++;
	}
	return (1);
}

void	get_row(char **splited_line, int *nums)
{
	int	i;

	if (!splited_line)
		ft_throw(strerror(errno));
	i = 0;
	while (splited_line[i])
	{
		nums[i] = ft_atoi(splited_line[i]);
		i++;
	}
}

void	fill_nums(t_fdf *data)
{
	t_list	*tmp;
	char 	**splited_line;
	int		i;
	int		j;

	data->cordinates = (int **)malloc(sizeof(int *) * data->size_x);
	if (!data->cordinates)
		ft_throw(strerror(errno));
	tmp = data->list;
	i = 0;
	while (tmp)
	{
		splited_line = ft_split(tmp->data, ' ');
		if (!splited_line)
			ft_throw(strerror(errno));
		data->cordinates[i] = (int *)malloc(sizeof(int) * tmp->length);
		if (!data->cordinates[i++])
			ft_throw(strerror(errno)), faillure(splited_line);
		j = 0;
		while (splited_line[j++])
			data->cordinates[i - 1][j - 1] = ft_atoi(splited_line[j - 1]);
		tmp = tmp->next;
		(faillure(splited_line), splited_line = NULL);
	}
}

int	valid_content_file(t_fdf *data)
{
	char	*line;
	t_list	*list;
	t_list	*tmp;
	int		fd;

	list = NULL;
	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		ft_throw("ERROR (OPEN)");
	data->size_y = 0;
	data->size_x = 0;
	line = get_next_line(fd);
	if (!line)
		ft_throw("ERROR: (get_next_line1)");
	while (line)
	{
		tmp = ft_lstnew(line);
		if (!tmp || !is_all_num(tmp->data))
			(ft_lstclear(&list, free), ft_throw("ERROR getting data from file"));
		(ft_lstadd_back(&list, tmp), data->size_y++, tmp->length = size_x(line));
		if (data->size_x < tmp->length)
			data->size_x = tmp->length;
		line = get_next_line(fd);
	}
	return (data->list = list, close(fd), fill_nums(data), 1);
}
