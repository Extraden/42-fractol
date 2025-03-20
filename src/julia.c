/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:17:22 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/20 13:29:29 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"

size_t	sequence_julia(t_complex z0, t_complex c)
{
	t_complex	tmp;
	t_complex	zn;
	size_t		i;
	
	zn = z0;
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