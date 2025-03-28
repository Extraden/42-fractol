/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:07:05 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:32:59 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	print_wrong_args_msg(void)
{
	ft_putendl_fd("\nWrong arguments!\n", 2);
	ft_putendl_fd("Type one of examples below:\n", 2);
	ft_putendl_fd("./fractol mandelbrot", 2);
	ft_putendl_fd("./fractol julia -0.8 0.156", 2);
	ft_putendl_fd("./fractol burningship", 2);
}

t_result	parse(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		fractal->name = MANDELBROT;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
		fractal->name = JULIA;
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship", 12))
		fractal->name = BURNINGSHIP;
	else
		return (FAILURE);
	return (SUCCESS);
}
