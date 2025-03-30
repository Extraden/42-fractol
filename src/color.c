#include "fractol.h"

int	get_color(size_t iter, t_color_map *color_map, size_t iterations)
{
	if (iter == ITERATIONS)
	{
		color_map->color = 0x000000;
		return (color_map->color);
	}
	color_map->t = (double)iter / (double)iterations;
	color_map->r = (int)(9 * (1 - color_map->t) * color_map->t * color_map->t
			* color_map->t * 255);
	color_map->g = (int)(15 * (1 - color_map->t) * (1 - color_map->t)
			* color_map->t * color_map->t * 255);
	color_map->b = (int)(8.5 * (1 - color_map->t) * (1 - color_map->t) * (1
				- color_map->t) * color_map->t * 255);
	color_map->color = ((color_map->r << 16) | (color_map->g << 8) | color_map->b);
	return (color_map->color);
}