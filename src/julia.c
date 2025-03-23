/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/23 18:10:34 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"

size_t	calculate_julia_sequence(t_complex z0, t_complex c)
{
	t_complex	tmp;
	t_complex	zn;
	size_t		i;
	
	zn = z0;
	i = 0;
	while (i < ITERATIONS)
	{
		tmp.real = (zn.real * zn.real) - (zn.imag * zn.imag);
		tmp.imag = 2 * zn.real * zn.imag;
		if (zn.real * zn.real + zn.imag * zn.imag > 4)
			return (i);
		zn.real = tmp.real + c.real;
		zn.imag = tmp.imag + c.imag;
		i++;
	}
	return (ITERATIONS);
}
