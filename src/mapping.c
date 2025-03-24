/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:02 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:26 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_complex	pixel_to_complex(t_pixel pixel, t_vars vars)
{
	t_complex	complex_point;

	complex_point.real = ((double)pixel.x - WIDTH / 2.0) / vars.zoom
		+ vars.real_center;
	complex_point.imag = ((double)pixel.y - HEIGHT / 2.0) / vars.zoom
		+ vars.im_center;
	return (complex_point);
}

t_pixel	complex_to_pixel(t_complex complex_point, t_vars vars)
{
	t_pixel	pixel;

	pixel.x = (int)((complex_point.real - vars.real_center) * vars.zoom + (WIDTH
				/ 2));
	pixel.y = (int)((complex_point.imag - vars.im_center) * vars.zoom + (HEIGHT
				/ 2));
	return (pixel);
}
