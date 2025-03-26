/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:26 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/26 12:10:30 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	handle_arrow_click(int keycode, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	if (keycode == XK_Left)
		f->vars.real_center -= 15 / f->vars.zoom;
	if (keycode == XK_Up)
		f->vars.im_center -= 15 / f->vars.zoom;
	if (keycode == XK_Right)
		f->vars.real_center += 15 / f->vars.zoom;
	if (keycode == XK_Down)
		f->vars.im_center += 15 / f->vars.zoom;
	if (keycode == XK_Escape)
		handle_close(fractal);
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

#define SCROLL_IN 4
#define SCROLL_OUT 5

int	handle_scroll(int button, int x, int y, void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	(void)x;
	(void)y;
	if (button == SCROLL_IN)
		f->vars.zoom *= 1.1;
	else if (button == SCROLL_OUT)
		f->vars.zoom /= 1.1;
	render(f);
	return (0);
}
