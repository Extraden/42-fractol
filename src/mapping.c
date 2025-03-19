#include "fractol.h"
#include <stdio.h>

t_complex   pixel_to_complex(t_pixel pixel)
{
    t_complex   complex_point;
    
    complex_point.real = ((double) pixel.x - WIDTH / 2.0) / ZOOM + REAL_CENTER;
    complex_point.i = ((double) pixel.y - HEIGHT / 2.0) / ZOOM + IM_CENTER;
    return (complex_point);
}

int main(void)
{
    t_pixel     pixel;
    t_complex   res;

    pixel.x = 0;
    pixel.y = 800;

    res = pixel_to_complex(pixel);
    printf("%f\n%f\n", res.real, res.i);
    return (0);
}

// fx = (x - W/2) / zoom + center_x
// fy = (y - H/2) / zoom + center_y

// t_pixel     complex_to_pixel(t_complex)
// {
//     return ();
// }