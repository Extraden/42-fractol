/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/24 20:33:57 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>

int	render(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->fractal_name, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->fractal_name, "julia", 6))
		draw_julia(fractal);
	else if (!ft_strncmp(fractal->fractal_name, "burningship", 12))
		draw_burning_ship(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
	mlx_handle_hooks(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
