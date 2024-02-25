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
		data->z_scale += 10;
	else if (key == ALT_DOWN)
		data->z_scale -= 10;
}

static void	finish(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->map->img);
	mlx_clear_window(data->mlx, data->win_ptr);
	mlx_destroy_window(data->mlx, data->win_ptr);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	event_handling(int key, t_fdf *data)
{
	if (key == INIT && data->is_iso)
		initial_state(data);
	else if (key == MOVE_RIGHT || key == MOVE_LEFT || key == MOVE_UP || 
		key == MOVE_DOWN || key == ALT_UP || key == ALT_DOWN)
		translating(key, data);
	else if (key == ROT_X_DOWN || key == ROT_X_UP || key == ROT_Y_L ||
		key == ROT_Y_R || key == ROT_Z_R || key == ROT_Z_L)
		rotating(key, data);
	else if (key == PROJECT)
		data->is_iso = 0;
	else if (key == QUIT)
		finish(data);
	fdf(data);
	printf("%d\n", key);
	return (1);
}