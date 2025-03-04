/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/04 20:09:44 by dsemenov         ###   ########.fr       */
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
	t_complex	zn = c;
	
	i = 0;
	while (i < n)
	{
		tmp_real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp_i = 2 * zn.real * zn.i;
		zn.real = tmp_real + c.real;
		zn.i = tmp_i + c.i;
		printf("Real part: %f\n Imaginary part: %f\n", zn.real, zn.i);
		i++;
	}
	return (zn);
}

int	main(int argc, char **argv)
{
	t_complex	c;
	int	n;
	if (argc != 4)
	{
		printf("Wrong number of arguments");
		return (0);
	}
	c.real = atof(argv[1]);
	c.i = atof(argv[2]);
	n = atoi(argv[3]);
	printf("%f\n%f\n", c.real, c.i);
	print_sequence(n, c);
	return (0);
}
