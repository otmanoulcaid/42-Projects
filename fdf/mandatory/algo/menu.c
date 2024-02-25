#include "../fdf.h"

void	print_menu(t_fdf *data)
{
	char	*menu;

	menu = "CLICK [ENTER] TO GET BACK TO FIRST STAT";
	mlx_string_put(data->mlx, data->win_ptr, 20, 10, 0xf000ff, menu);
	menu = "PRESS [SPACE] TO SWITCH BETWEEN 3D/2D MODES";
	mlx_string_put(data->mlx, data->win_ptr, 20, 45, 0xf000ff, menu);
	menu = "PRESS [+/-] TO ZOOM IN OR OUT";
	mlx_string_put(data->mlx, data->win_ptr, 20, 80, 0xf000ff, menu);
	menu = "PRESS [C] TO CHANGE COLORS MODE";
	mlx_string_put(data->mlx, data->win_ptr, 20, 115, 0xf000ff, menu);
	menu = "PRESS [1/2] KEYS FOR Z-SCALING";
	mlx_string_put(data->mlx, data->win_ptr, 20, 150, 0xf000ff, menu);
	menu = "PRESS [4/5] KEYS FOR ROTATING THE MODEL";
	mlx_string_put(data->mlx, data->win_ptr, 20, 185, 0xf000ff, menu);
	menu = "RESS ARROW KEYS TO MOVE PICTURE";
	mlx_string_put(data->mlx, data->win_ptr, 20, 220, 0xf000ff, menu);
}
