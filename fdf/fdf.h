#ifndef FDF_H

# define FDF_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

typedef struct s_fdf
{
	void	*mlx;
	void	*win_ptr;
	int		size_y;
	int		size_x;
	char	*file;
	char	**x_y_z;
}	t_fdf;

/*-----------utils----------*/

char	*get_next_line(int fd);

/*------------fdf----------*/
int		valid_arg(char **av, t_fdf *data);
int		valid_content_file(t_fdf *data);
void	fdf(t_fdf *data);
void	ft_throw(char *strerr);

#endif