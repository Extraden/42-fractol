/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/20 13:20:40 by dsemenov         ###   ########.fr       */
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
	else if (argc == 4 && !strcmp(argv[1], "julia"))
	{
		// 1 argument: C real part, 2 arg: C imaginary part, 3 argument: z0 real part, 4 arg: z0 imaginary part
//Example: %s -0.8 0.156 0.2 0
	t_complex	c;

	c.real = atof(argv[2]);
	c.i = atof(argv[3]);
	render_julia(c);
	return (0);
	}
	else
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	return (0);
}