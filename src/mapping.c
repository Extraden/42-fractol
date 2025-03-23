#include "fractol.h"
#include <stdio.h>

t_complex   pixel_to_complex(t_pixel pixel, t_vars vars)
{
    t_complex   complex_point;
    
    complex_point.real = ((double) pixel.x - WIDTH / 2.0) / vars.zoom + vars.real_center;
    complex_point.imag = ((double) pixel.y - HEIGHT / 2.0) / vars.zoom + vars.im_center;
    return (complex_point);
}

t_pixel     complex_to_pixel(t_complex complex_point, t_vars vars)
{
    t_pixel pixel;

    pixel.x = (int) ((complex_point.real - vars.real_center) * vars.zoom + (WIDTH / 2));
    pixel.y = (int) ((complex_point.imag - vars.im_center) * vars.zoom + (HEIGHT / 2));
    return (pixel);
}