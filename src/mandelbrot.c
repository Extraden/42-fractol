/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/19 18:44:42 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fractol.h"
#include <stdlib.h>

t_complex	sequence_mandelbrot(t_complex c)
{
	t_complex	zn;
	t_complex	tmp;

	zn = (t_complex){0, 0, 0};
	c.last_iteration = 0;
	while (c.last_iteration < ITERATIONS)
	{
		tmp.real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp.i = 2 * zn.real * zn.i;
		if (c.last_iteration && fabs((tmp.real + c.real) - zn.real) < EPSILON && fabs((tmp.i + c.i) - zn.i) < EPSILON)
		{
			zn.last_iteration = c.last_iteration;
			return (zn);
		}
		zn.real = tmp.real + c.real;
		zn.i = tmp.i + c.i;
		if (zn.real * zn.real + zn.i * zn.i > 4)
		{
			zn.last_iteration = c.last_iteration;
			return (zn);
		}
		c.last_iteration++;
	}
	zn.last_iteration = c.last_iteration;
	return (zn);
}
