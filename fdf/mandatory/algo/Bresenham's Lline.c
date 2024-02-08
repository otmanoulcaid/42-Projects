#include "../fdf.h"

bresenham(t_point p1, t_point p2, t_fdf *data)
{
    float x_step;
    float y_step;
    float max;

    x_step  = p2.x - p1.x;
    y_step  = p2.y - p1.y;
    max = fmax(abs(x_step), abs(x_step));
    x_step /= max;
    y_step /= max;
    while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
    {
        my_mlx_pixel_put(data, p1.x, p1.y, 0xff00ff);
        p1.x+=x_step;
        p1.y+=y_step;
    }
}
