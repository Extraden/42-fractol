/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:12 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/30 16:40:44 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stddef.h>

size_t	calculate_burning_ship_sequence(t_complex c, size_t iterations)
{
	t_complex	zn;
	t_complex	tmp;
	size_t		i;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < iterations)
	{
		zn.imag = fabs(zn.imag);
		zn.real = fabs(zn.real);
		tmp.real = (zn.real * zn.real) - (zn.imag * zn.imag);
		tmp.imag = 2 * zn.real * zn.imag;
		if (zn.real * zn.real + zn.imag * zn.imag > 4)
			return (i);
		zn.real = tmp.real + c.real;
		zn.imag = tmp.imag + c.imag;
		i++;
	}
	return (iterations);
}

void	draw_burning_ship(t_fractal *fractal)
{
	t_pixel		pixel;
	t_complex	c;
	size_t		max_iteration;
	int			color;

	pixel.y = 0;
	while (pixel.y < fractal->viewport.height)
	{
		pixel.x = 0;
		while (pixel.x < fractal->viewport.width)
		{
			c = pixel_to_complex(pixel, fractal->viewport);
			max_iteration = calculate_burning_ship_sequence(c, fractal->iterations);
			color = get_color(max_iteration, &fractal->color_map, fractal->iterations);
			my_mlx_pixel_put(&fractal->img, pixel.x, pixel.y, color);
			pixel.x++;
		}
		pixel.y++;
	}
}
