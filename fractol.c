/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/05 15:56:11 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "fractol.h"

t_complex	print_sequence(int n, t_complex c)
{
	size_t	i;
	double	tmp_real;
	double	tmp_i;
	t_complex	zn;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < n)
	{
		tmp_real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp_i = 2 * zn.real * zn.i;
		zn.real = tmp_real + c.real;
		zn.i = tmp_i + c.i;
		printf("z%lu:\nReal part: %f\nImaginary part: %f\n\n", i + 1, zn.real, zn.i);
		i++;
	}
	return (zn);
}

// 1 argument: real part, 2 arg: imaginary part: 3 arg: number of iterations
int	main(int argc, char **argv)
{
	t_complex	c;
	t_complex	z;
	int	n;
	if (argc != 4)
	{
		printf("Wrong number of arguments");
		return (0);
	}
	c.real = atof(argv[1]);
	c.i = atof(argv[2]);
	n = atoi(argv[3]);
	z = print_sequence(n, c);
	if (z.real * z.real + z.i * z.i > 4) printf("\nC doesn't relate to Mandelbrot set\n");
	printf("\nC relates to Mandelbrot set\n");
	return (0);
}
