/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:46:34 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static t_result	julia_init(t_fractal *fractal, char **argv)
{
	if (ft_atof(argv[2], &fractal->c.real) != SUCCESS || ft_atof(argv[3],
			&fractal->c.imag) != SUCCESS)
	{
		print_wrong_args_msg();
		return (FAILURE);
	}
	return (SUCCESS);
}

t_result	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->viewport.width = WIDTH;
	fractal->viewport.height = HEIGHT;
	fractal->viewport.zoom = 200;
	fractal->viewport.real_center = 0;
	fractal->viewport.im_center = 0;
	fractal->to_render = 1;
	if (fractal->name == JULIA)
		if (julia_init(fractal, argv) == FAILURE)
			return (FAILURE);
	if (init_mlx_system(fractal, argv[1]) == FAILURE)
		return (FAILURE);
	mlx_handle_hooks(fractal);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_memset(&fractal, 0, sizeof(t_fractal));
	if (parse(&fractal, argc, argv) == FAILURE)
	{
		print_wrong_args_msg();
		return (1);
	}
	if (fractal_init(&fractal, argv) == FAILURE)
	{
		ft_putendl_fd("MLX error", 2);
		return (1);
	}
	render(&fractal);
	mlx_loop(fractal.mlx_ptr);
	mlx_destroy_window(fractal.mlx_ptr, fractal.win_ptr);
	mlx_destroy_image(fractal.mlx_ptr, fractal.img.img_ptr);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
	return (0);
}
