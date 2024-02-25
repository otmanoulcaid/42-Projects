#include "../fdf.h"

void	rotate_x(t_point *p, t_fdf *data)
{
    int prev_y;

    prev_y = p->y;
    p->y =  prev_y * cos(data->alpha) + p->z * sin(data->alpha);
    p->z = -prev_y * sin(data->alpha) + p->z * cos(data->alpha);
}

void	rotate_y(t_point *p, t_fdf *data)
{
    int prev_x;

    prev_x = p->x;
    p->x = prev_x * cos(data->beta) - p->x * sin(data->beta);
    p->z = prev_x * sin(data->beta) + p->z * cos(data->beta);
}

void	rotate_z(t_point *p, t_fdf *data)
{
    int prev_y;
    int prev_x;

    prev_y = p->y;
    prev_x = p->x;
    p->x = prev_x * cos(data->gama) - prev_y* sin(data->gama);
    p->y = prev_x * sin(data->gama) + prev_y* cos(data->gama);
    
}

void    iso(t_point *p, t_fdf *data)
{
    int x;

    x = (p->x - p->y) * cos((float)(M_PI / 6));
	p->y = (p->x + p->y) * sin((float)(M_PI / 6)) - p->z;
    p->x = x;
}

void    set_coordinate(t_point *p1, t_point *p2, t_fdf *data)
{
    p1->x *= data->zoom;
    p1->y *= data->zoom;
    p1->z *= data->zoom;
    p2->x *= data->zoom;
    p2->y *= data->zoom;
    p2->z *= data->zoom;
    (rotate_x(p1, data), rotate_x(p2, data));
    (rotate_y(p1, data), rotate_y(p2, data));
    (rotate_z(p1, data), rotate_z(p2, data));
    if (p1->z)
        p1->z += data->z_scale;
    if (p2->z)
        p2->z += data->z_scale;
    if (data->is_iso)
        (iso(p1, data), iso(p2, data));
    p1->x += data->x_scale;
    p1->y += data->y_scale;
    p2->x += data->x_scale;
    p2->y += data->y_scale;
}