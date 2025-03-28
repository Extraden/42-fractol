/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:02 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:05:21 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex(t_pixel pixel, t_viewport viewport)
{
	t_complex	complex_point;

	complex_point.real = ((double)pixel.x - viewport.width / 2.0)
		/ viewport.zoom + viewport.real_center;
	complex_point.imag = ((double)pixel.y - viewport.height / 2.0)
		/ viewport.zoom + viewport.im_center;
	return (complex_point);
}
