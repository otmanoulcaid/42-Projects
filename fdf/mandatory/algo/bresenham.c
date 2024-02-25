#include "../fdf.h"

void slope_bigger_than_one(t_fdf *data, int dx, int dy, t_point *a, t_point *b)
{
	int p;
	int i;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	while (++i < abs(dy))
	{
	my_mlx_pixel_put(data, a, b);
		if (dy > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
  		{
			if (dx > 0)
				a->x++;
			else
				a->x--;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
	}
}

void slope_less_than_one(t_fdf *data, int dx, int dy, t_point *a, t_point *b)
{
	int p;
	int i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	while (++i < abs(dx))
	{
	my_mlx_pixel_put(data, a, b);
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
  		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
	}
}

void bresenham(t_point p1, t_point p2, t_fdf *data)
{
	int	dx;
	int	dy;

	set_coordinate(&p1, &p2, data);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) > abs(dy))
		slope_less_than_one(data, dx, dy, &p1, &p2);
	else
		slope_bigger_than_one(data, dx, dy, &p1, &p2);
}


