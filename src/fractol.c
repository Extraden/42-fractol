/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/26 19:10:09 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

t_result	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->vars.width = WIDTH;
	fractal->vars.height = HEIGHT;
	fractal->vars.zoom = 200;
	fractal->vars.real_center = 0;
	fractal->vars.im_center = 0;
	if (fractal->name == JULIA)
	{
		if (ft_atof(argv[3], &fractal->c.real) != SUCCESS || ft_atof(argv[4],
				&fractal->c.imag) != SUCCESS)
		{
			print_error_msg();
			return (FAILURE);
		}
	}
	init_mlx_system(fractal, argv[1]);
	mlx_handle_hooks(fractal);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = &(t_fractal){0};
	check_args(fractal, argc, argv);
	if (!fractal_init(fractal, argv))
	{
		printf("Could not initialize program");
		return (EXIT_FAILURE);
	}
	render(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
