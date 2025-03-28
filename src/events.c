/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:26 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:54:37 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

int	handle_arrow_click(int keycode, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	if (keycode == XK_Left)
		f->viewport.real_center -= 15 / f->viewport.zoom;
	if (keycode == XK_Up)
		f->viewport.im_center -= 15 / f->viewport.zoom;
	if (keycode == XK_Right)
		f->viewport.real_center += 15 / f->viewport.zoom;
	if (keycode == XK_Down)
		f->viewport.im_center += 15 / f->viewport.zoom;
	if (keycode == XK_space)
		f->color_map.color *= 2000;
	if (keycode == XK_Escape)
		handle_close(fractal);
	f->to_render = 1;
	return (0);
}

int	handle_close(void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	mlx_loop_end(f->mlx_ptr);
	return (0);
}

int	handle_scroll(int button, int x, int y, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	(void)x;
	(void)y;
	if (button == SCROLL_IN)
	{
		f->viewport.zoom *= 1.1;
	}
	else if (button == SCROLL_OUT)
	{
		f->viewport.zoom /= 1.1;
	}
	f->to_render = 1;
	return (0);
}

int	loop_hook(void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	if (f->to_render)
	{
		render(fractal);
		f->to_render = 0;
	}
	return (0);
}
