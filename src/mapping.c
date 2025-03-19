#include "fractol.h"
#include <stdio.h>

t_complex   pixel_to_complex(t_pixel pixel)
{
    t_complex   complex_point;
    
    complex_point.real = ((double) pixel.x - WIDTH / 2.0) / ZOOM + REAL_CENTER;
    complex_point.i = ((double) pixel.y - HEIGHT / 2.0) / ZOOM + IM_CENTER;
    return (complex_point);
}

t_pixel     complex_to_pixel(t_complex complex_point)
{
    t_pixel pixel;

    pixel.x = (int) ((complex_point.real - REAL_CENTER) * ZOOM + (WIDTH / 2));
    pixel.y = (int) ((complex_point.i - IM_CENTER) * ZOOM + (HEIGHT / 2));
    return (pixel);
}