#include "fractol.h"

void	colormap_init(t_color_map *color_map)
{
	color_map->r = 0;
	color_map->g = 0;
	color_map->b = 0;
	color_map->color = 0;
}

void  shift_colors(t_color_map *color_map)
{
		color_map->r = (color_map->r + 25) % 255;
		color_map->g = (color_map->g + 25) % 255;
		color_map->b = (color_map->b + 25) % 255;
}

int	get_color(size_t iter, t_color_map *color_map, size_t iterations)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (iter == ITERATIONS)
	{
		color_map->color = 0x000000;
		return (color_map->color);
	}
	double t = (double)iter / (double)iterations;
    r = (int)(9 * (1 - t) * t * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    r = (r + color_map->r) % 256;
    g = (g + color_map->g) % 256;
    b = (b + color_map->b) % 256;

    return ((r << 16) | (g << 8) | b);
}

