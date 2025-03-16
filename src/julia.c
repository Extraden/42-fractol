/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/14 20:13:21 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

t_complex	print_sequence_julia(t_complex c, t_complex z0)
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
