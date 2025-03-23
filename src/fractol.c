/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/23 18:15:43 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void	fractal_init(t_fractal *fractal, char *type)
{
		fractal->fractal_name = type;
		fractal->vars.width = 1000;
		fractal->vars.height = 1000;
		fractal->vars.zoom = 200;
		fractal->vars.real_center = 0;
		fractal->vars.im_center = 0;
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	
	fractal = &(t_fractal){0};
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || \
		(argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal_init(fractal, argv[1]);
		if (!ft_strncmp(fractal->fractal_name, "julia", 6))
		{
			fractal->c.real = ft_atof(argv[2]);
			fractal->c.imag = ft_atof(argv[3]);
		}
		init_mlx_system(fractal);
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