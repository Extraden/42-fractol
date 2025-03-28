/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 16:25:23 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

static t_result	julia_init(t_fractal *fractal, char **argv)
{
	if (ft_atof(argv[2], &fractal->c.real) != SUCCESS || ft_atof(argv[3],
			&fractal->c.imag) != SUCCESS)
	{
		print_error_msg();
		return (FAILURE);
	}
	return (SUCCESS);
}

t_result	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->vars.width = WIDTH;
	fractal->vars.height = HEIGHT;
	fractal->vars.zoom = 200;
	fractal->vars.real_center = 0;
	fractal->vars.im_center = 0;
	if (fractal->name == JULIA)
		if (!julia_init(fractal, argv))
			return (FAILURE);
	if (!init_mlx_system(fractal, argv[1]))
		return (FAILURE);
	mlx_handle_hooks(fractal);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = &(t_fractal){0};
	if (!check_args(fractal, argc, argv))
	{
		print_error_msg();
		return (FAILURE);
	}
	if (!fractal_init(fractal, argv))
	{
		print_error_msg();
		return (FAILURE);
	}
	render(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (SUCCESS);
}
