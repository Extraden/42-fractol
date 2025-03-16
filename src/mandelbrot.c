/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/14 20:12:31 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fractol.h"

t_complex	print_sequence_mandelbrot(t_complex c)
{
	int	i;
	t_complex	zn;
	t_complex	tmp;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < ITERATIONS)
	{
		tmp.real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp.i = 2 * zn.real * zn.i;
		if (i && fabs((tmp.real + c.real) - zn.real) < EPSILON && fabs((tmp.i + c.i) - zn.i) < EPSILON)
			return (zn);
		zn.real = tmp.real + c.real;
		zn.i = tmp.i + c.i;
		printf("z%d:\nReal part: %f\nImaginary part: %f\n\n", i + 1, zn.real, zn.i);
		if (zn.real * zn.real + zn.i * zn.i > 4)
			return (zn);
		i++;
	}
	return (zn);
}
