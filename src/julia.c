/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/31 15:25:15 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

size_t	calculate_julia_sequence(t_complex z0, t_complex c, size_t iterations)
{
	t_complex	tmp;
	t_complex	zn;
	size_t		i;
	double		r2;
	double		i2;

	zn = z0;
	i = 0;
	while (i < iterations)
	{
		r2 = zn.real * zn.real;
		i2 = zn.imag * zn.imag;
		if (r2 + i2 > 4)
			return (i);
		tmp.real = r2 - i2;
		tmp.imag = 2 * zn.real * zn.imag;
		zn.real = tmp.real + c.real;
		zn.imag = tmp.imag + c.imag;
		i++;
	}
	return (iterations);
}

void	draw_julia(t_fractal *fractal)
{
	t_pixel		pixel;
	t_complex	z;
	size_t		max_iteration;
	int			color;

	pixel.y = 0;
	while (pixel.y < fractal->viewport.height)
	{
		pixel.x = 0;
		while (pixel.x < fractal->viewport.width)
		{
			z = pixel_to_complex(pixel, fractal->viewport);
			max_iteration = calculate_julia_sequence(z, fractal->c,
					fractal->iterations);
			color = get_color(max_iteration, &fractal->color_map,
					fractal->iterations);
			my_mlx_pixel_put(&fractal->img, pixel.x, pixel.y, color);
			pixel.x++;
		}
		pixel.y++;
	}
}
