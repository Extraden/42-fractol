/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/26 19:17:05 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	render(t_fractal *fractal)
{
	if (fractal->name == MANDELBROT)
		draw_mandelbrot(fractal);
	else if (fractal->name == JULIA)
		draw_julia(fractal);
	else if (fractal->name == BURNINGSHIP)
		draw_burning_ship(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
	return (0);
}
