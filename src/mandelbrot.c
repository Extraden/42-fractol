/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/31 15:25:03 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stddef.h>

size_t	calculate_mandelbrot_sequence(t_complex c, size_t iterations)
{
	t_complex	zn;
	t_complex	tmp;
	size_t		i;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < iterations)
	{
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

void	draw_mandelbrot(t_fractal *fractal)
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
			max_iteration = calculate_mandelbrot_sequence(c,
					fractal->iterations);
			color = get_color(max_iteration, &fractal->color_map,
					fractal->iterations);
			my_mlx_pixel_put(&fractal->img, pixel.x, pixel.y, color);
			pixel.x++;
		}
		pixel.y++;
	}
}
