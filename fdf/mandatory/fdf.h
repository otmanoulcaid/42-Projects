#ifndef FDF_H

# define FDF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define MAX_WIDTH 1500
# define MAX_HEIGH 1000
# define GRAND 60
# pragma GCC diagnostic ignored "-Wunused-parameter"

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_fdf
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
	char	*file;
	int		**cordinates;
	int		size_y;
	int		size_x;
	int		bits_per_pixel;
	int		endian;
	t_list	*list;
}	t_fdf;

/*-----------error----------*/

void	faillure(char **str);
void	ft_throw(char *strerr);

/*-----------utils----------*/

char	*get_next_line(int fd);

/*------------fdf----------*/
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		valid_arg(char **av, t_fdf *data);
int		valid_content_file(t_fdf *data);
void	fdf(t_fdf *data);

#endif