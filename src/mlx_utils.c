/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:38:42 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 16:28:20 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

// ((r << 16) | (g << 8) | (b))

int	get_color(size_t iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;
	
	if (iter == ITERATIONS)
		return (COLOR(0, 0, 0));
	t = (double)iter / (double)ITERATIONS;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = ((r << 16) | (g << 8) | b);
	return (color);
}

t_result	init_mlx_system(t_fractal *fractal, char *name)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return (FAILURE);
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		return (FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
		free(fractal->mlx_ptr);
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
	mlx_hook(fractal->win_ptr, 4, 1L << 2, handle_scroll, fractal);
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, handle_arrow_click,
		fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, 0, handle_close, fractal);
}
