/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/21 16:19:56 by dsemenov         ###   ########.fr       */
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
	t_fractal	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || \
		(argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.fractal_name = argv[1];
		if (!ft_strncmp(fractal.fractal_name, "julia", 6))
		{
			fractal.c.real = atof(argv[2]);
			fractal.c.i = atof(argv[3]);
		}
		render(fractal);
		return (0);
	}
	else
	{
		printf("Wrong number of arguments!\n");
		printf("Example: ./fractol mandelbrot\n");
		printf("Or: ./fractol julia -0.8 0.156\n");

		return (1);
	}
	return (0);
}