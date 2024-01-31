#include "../../fdf.h"

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

static int	verify_matrix(t_list *lst, t_fdf *data)
{
	int		i;

	i = 0;
	data->x_y_z = (char **)malloc(sizeof(char *) * data->size_y);
	if (!data->x_y_z)
		ft_throw("ERROR: (malloc)");
	while (lst)
	{
		if (!is_all_num(lst->data) || size_x(lst->data) != data->size_x)
			ft_throw("invalid file content");
		(data->x_y_z)[i] = ft_strdup(lst->data);
		if (!(data->x_y_z)[i++])
			ft_throw("ERROR: (strdup)");
		lst = lst->next;
	}
	ft_lstclear(&lst, free);
	return (1);
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
	(line = get_next_line(fd));
	if (!line)
		ft_throw("ERROR: (get_next_line1)");
	data->size_x = size_x(line);
	while (line)
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			(ft_lstclear(&list, free), ft_throw("ERROR: (creat_node)"));
		(ft_lstadd_back(&list, tmp), data->size_y++);
		line = get_next_line(fd);
	}
	close(fd);
	verify_matrix(list, data);
	return (1);
}
