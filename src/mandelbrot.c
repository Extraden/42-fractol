/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/22 16:49:29 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "fractol.h"

size_t	sequence_mandelbrot(t_complex c)
{
	t_complex	zn;
	t_complex	tmp;
	size_t		i;

	zn = (t_complex){0, 0};
	i = 0;
	while (i < ITERATIONS)
	{
		tmp.real = (zn.real * zn.real) - (zn.i * zn.i);
		tmp.i = 2 * zn.real * zn.i;
		if (zn.real * zn.real + zn.i * zn.i > 4)
			return (i);
		zn.real = tmp.real + c.real;
		zn.i = tmp.i + c.i;
		i++;
	}
	return (ITERATIONS);
}