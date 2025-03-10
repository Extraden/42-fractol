/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/06 16:22:48 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "fractol.h"

t_complex	print_sequence(t_complex c, t_complex z0)
{
	int	i;
	double	tmp_real;
	double	tmp_i;
	t_complex	zn;

	zn = z0;
	i = 0;
	while (i < ITERATIONS)
	{
		tmp_real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp_i = 2 * zn.real * zn.i;
		zn.real = tmp_real + c.real;
		zn.i = tmp_i + c.i;
		printf("z%d:\nReal part: %f\nImaginary part: %f\n\n", i + 1, zn.real, zn.i);
		if (zn.real * zn.real + zn.i * zn.i > 4)
			return (zn);
		i++;
	}
	return (zn);
}

// 1 argument: C real part, 2 arg: C imaginary part, 3 argument: z0 real part, 4 arg: z0 imaginary part, 5 arg: number of iterations
int	main(int argc, char **argv)
{
	t_complex	c;
	t_complex	z0;
	t_complex	res;

	if (argc != 5)
	{
		printf("Enter arguments:\n1.C real part 2.C imaginary part 3.z0 real part 4.z0 imaginary part\n");
    	printf("Example: %s -0.8 0.156 0.2 0\n", argv[0]);
    	return (1);
	}
	c.real = atof(argv[1]);
	c.i = atof(argv[2]);
	z0.real = atof(argv[3]);
	z0.i = atof(argv[4]);
	res = print_sequence(c, z0);
	if (res.real * res.real + res.i * res.i > 4)
		printf("\nz0 doesn't relate to Julia set\n");
	else
		printf("\nz0 %f %f relates to Julia set\n", z0.real, z0.i);
	return (0);
}
