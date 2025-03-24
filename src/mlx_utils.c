#include "fractol.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>

int	get_color(size_t iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == ITERATIONS)
		return (COLOR(0, 0, 0));
	t = (double)iter / (double)ITERATIONS;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (COLOR(r, g, b));
}

void	init_mlx_system(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->fractal_name);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
}

void	my_mlx_pixel_put(t_img_data *image_data, int x, int y, int color)
{
	char	*dst;

	dst = image_data->pixels_ptr + (y * image_data->line_length + x
			* (image_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_handle_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, 4, 1L << 2, handle_scroll, fractal);
	mlx_hook(fractal->win_ptr, 2, 1L << 0, handle_arrow_click, fractal);
	mlx_hook(fractal->win_ptr, 17, 0, handle_close, fractal);
}