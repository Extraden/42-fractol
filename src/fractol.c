/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/14 20:48:56 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 4 && !strcmp(argv[1], "mandelbrot"))
	{
		// 1 argument: real part, 2 arg: imaginary part
		t_complex c;
		t_complex z;

		c.real = atof(argv[2]);
		c.i = atof(argv[3]);
		z = print_sequence_mandelbrot(c);
		if (z.real * z.real + z.i * z.i > 4)
			printf("\nC doesn't relate to Mandelbrot set\n");
		else
			printf("\nC relates to Mandelbrot set\n");
	  /*printf("Mandelbrot");*/
	}
	else if (argc == 6 && !strcmp(argv[1], "julia"))
	{
		// 1 argument: C real part, 2 arg: C imaginary part, 3 argument: z0 real part, 4 arg: z0 imaginary part
//Example: %s -0.8 0.156 0.2 0
		t_complex	c;
		t_complex	z0;
		t_complex	res;

		c.real = atof(argv[1]);
		c.i = atof(argv[2]);
		z0.real = atof(argv[3]);
		z0.i = atof(argv[4]);
		res = print_sequence_julia(c, z0);
		if (res.real * res.real + res.i * res.i > 4)
		printf("\nz0 doesn't relate to Julia set\n");
		else
		printf("\nz0 %f %f relates to Julia set\n", z0.real, z0.i);

	}
	else
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	return (0);
}
