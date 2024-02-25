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

/*------helpful macros------*/

# define MAX_WIDTH 1800
# define MAX_HEIGH 1000
# define MENU_WIDTH 150
# define ZOOM 60
# pragma GCC diagnostic ignored "-Wunused-parameter"

typedef enum keys_s
{
	INIT		= 49,
	QUIT		= 53,
	ROT_X_DOWN	= 84,
	ROT_Y_L		= 86,
	ROT_Y_R		= 88,
	ROT_X_UP	= 91,
	ROT_Z_R		= 85,
	ROT_Z_L		= 92,
	PROJECT		= 83,
	ALT_DOWN	= 82,
	ALT_UP		= 87,
	MOVE_LEFT	= 123,
	MOVE_RIGHT	= 124,
	MOVE_DOWN	= 125,
	MOVE_UP		= 126,
}	keys_t;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	
	int		width;
	int		height;
	int		bbp;
	int		endian;
	int		win_x;
	void	*img;
	char	*img_addr;
	t_point	**cord;
	t_list	*list;
}	t_map;

typedef struct s_fdf
{
	int		z_scale;
	int		x_scale;
	int		y_scale;
	double	alpha;
	double	beta;
	double	gama;
	int		zoom;
	int		is_iso;
	int		fd;
	int		bits_per_pixel;
	void	*mlx;
	void	*win_ptr;
	t_map	*map;
}	t_fdf;

/*-----------error----------*/
void	faillure(char **str);
void	ft_throw(char *strerr);

/*-----------utils----------*/
char	*get_next_line(int fd);

/*--------bool-------*/
int		valid_arg(char **av, t_fdf *data);
int		valid_content(t_fdf *fdf, char *av);
int		is_all_num(char *str);
int		ternary(int boolean, int a, int b);

/*------------fdf----------*/
void	my_mlx_pixel_put(t_fdf *data, t_point *x, t_point *y);
void	init_mlx_content(t_fdf *data);
void	fdf(t_fdf *data);
void	bresenham(t_point p1, t_point p2, t_fdf *data);
void	print_menu(t_fdf *data);
void 	draw_bg(t_fdf *data);
void    set_coordinate(t_point *p1, t_point *p2, t_fdf *data);
int		event_handling(int key, t_fdf *data);
void	rotate(int key, t_fdf *data);

#endif