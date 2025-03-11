/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/11 18:01:27 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"

t_complex	print_sequence(t_complex c)
{
	int	i;
	double	tmp_real;
	double	tmp_i;
	t_complex	zn;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < ITERATIONS)
	{
		tmp_real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp_i = 2 * zn.real * zn.i;
		if (i && fabs((tmp_real + c.real) - zn.real) < EPSILON && fabs((tmp_i + c.i) - zn.i) < EPSILON)
			return (zn);
		zn.real = tmp_real + c.real;
		zn.i = tmp_i + c.i;
		printf("z%d:\nReal part: %f\nImaginary part: %f\n\n", i + 1, zn.real, zn.i);
		if (zn.real * zn.real + zn.i * zn.i > 4)
			return (zn);
		i++;
	}
	return (zn);
}

// 1 argument: real part, 2 arg: imaginary part
int	main(int argc, char **argv)
{
	t_complex	c;
	t_complex	z;

	if (argc != 3)
	{
		printf("Wrong number of arguments!\n");
		printf("Usage: %s <real_part> <imaginary_part>\n", argv[0]);
		printf("Example: %s 0.2 0.3\n", argv[0]);
		return (1);
	}
	c.real = atof(argv[1]);
	c.i = atof(argv[2]);
	z = print_sequence(c);
	if (z.real * z.real + z.i * z.i > 4)
		printf("\nC doesn't relate to Mandelbrot set\n");
	else
		printf("\nC relates to Mandelbrot set\n");
	return (0);
}
