/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/24 20:10:43 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>

void	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->fractal_name = argv[1];
	fractal->vars.width = WIDTH;
	fractal->vars.height = HEIGHT;
	fractal->vars.zoom = 200;
	fractal->vars.real_center = 0;
	fractal->vars.im_center = 0;
	if (!ft_strncmp(fractal->fractal_name, "julia", 6))
	{
		fractal->c.real = ft_atof(argv[2]);
		fractal->c.imag = ft_atof(argv[3]);
	}
	init_mlx_system(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = &(t_fractal){0};
	check_args(argc, argv);
	fractal_init(fractal, argv);
	render(fractal);
	return (0);
}
