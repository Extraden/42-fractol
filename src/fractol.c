/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/19 16:39:03 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fractol.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && !strncmp(argv[1], "mandelbrot", 11))
	{
		render_mandelbrot();
		return (0);
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
