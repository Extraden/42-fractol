/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:26 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/24 16:53:29 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

int	handle_arrow_click(int keycode, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	if (keycode == 65361)
		f->vars.real_center -= 7 / f->vars.zoom;
	if (keycode == 65362)
		f->vars.im_center -= 7 / f->vars.zoom;
	if (keycode == 65363)
		f->vars.real_center += 7 / f->vars.zoom;
	if (keycode == 65364)
		f->vars.im_center += 7 / f->vars.zoom;
	render(f);
	return (0);
}

int	handle_close(void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_scroll(int button, int x, int y, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	(void)x;
	(void)y;
	if (button == 4)
	{
		f->vars.zoom *= 1.1;
		render(f);
	}
	if (button == 5)
	{
		f->vars.zoom /= 1.1;
		render(f);
	}
	return (0);
}
