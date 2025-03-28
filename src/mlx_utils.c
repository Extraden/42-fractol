/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:38:42 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:54:53 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	get_color(size_t iter, t_color_map *color_map)
{
	if (iter == ITERATIONS)
	{
		color_map->color = 0x000000;
		return (color_map->color);
	}
	color_map->t = (double)iter / (double)ITERATIONS;
	color_map->r = (int)(9 * (1 - color_map->t) * color_map->t * color_map->t
			* color_map->t * 255);
	color_map->g = (int)(15 * (1 - color_map->t) * (1 - color_map->t)
			* color_map->t * color_map->t * 255);
	color_map->b = (int)(8.5 * (1 - color_map->t) * (1 - color_map->t) * (1
				- color_map->t) * color_map->t * 255);
	color_map->color = ((color_map->r << 16) | (color_map->g << 8) | color_map->b);
	return (color_map->color);
}

void	mlx_destroy_all(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	if (fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
}

t_result	init_mlx_system(t_fractal *fractal, char *name)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		return (FAILURE);
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_all(fractal);
		return (FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_all(fractal);
		return (FAILURE);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	return (SUCCESS);
}

void	my_mlx_pixel_put(t_img_data *image_data, int x, int y, int color)
{
	char	*dst;

	dst = image_data->pixels_ptr + (y * image_data->line_length + x
			* (image_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_handle_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, handle_scroll,
		fractal);
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, handle_arrow_click,
		fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, NoEventMask, handle_close,
		fractal);
	mlx_loop_hook(fractal->mlx_ptr, loop_hook, fractal);
}
