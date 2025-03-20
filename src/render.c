/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/20 13:42:20 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fractol.h"

// Color hint
 int red = (255 << 16) | (0 << 8) | 0;
 int green = (0 << 16) | (255 << 8) | 0;
 int blue = (0 << 16) | (0 << 8) | 255;

static int	get_color(size_t iter)
{
    if (iter == ITERATIONS)
        return COLOR(0, 0, 0); // Точка принадлежит множеству — чёрная.

    // t от 0 до 1
    double t = (double)iter / (double)ITERATIONS;

    // Полиномиальные формулы для r, g, b.
    // Можно менять коэффициенты (9, 15, 8.5) и степени, чтобы добиться разных эффектов.
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return COLOR(r, g, b);
}

int	render_mandelbrot(void)
{
	void	*mlx;
  void  *mlx_window;
	t_img	img;
  t_complex c;
  t_pixel pixel;
  size_t  max_iteration;
  int     color;

	mlx = mlx_init();
  mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

  pixel.x = 0;
  while (pixel.x < WIDTH)
  {
    pixel.y = 0;
    while (pixel.y < HEIGHT)
    {
      c = pixel_to_complex(pixel);
      max_iteration = sequence_mandelbrot(c);
      color = get_color(max_iteration);
      mlx_pixel_put(mlx, mlx_window, pixel.x, pixel.y, color);
      pixel.y++;
    }
    pixel.x++;
  } 
  mlx_loop(mlx);
	return (0);
}
int	render_julia(t_complex c)
{
	void	*mlx;
  void  *mlx_window;
	t_img	img;
  t_pixel pixel;
  t_complex z;
  size_t  max_iteration;
  int     color;

	mlx = mlx_init();
  mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Julia");
	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

  pixel.x = 0;
  while (pixel.x < WIDTH)
  {
    pixel.y = 0;
    while (pixel.y < HEIGHT)
    {
      z = pixel_to_complex(pixel);
      max_iteration = sequence_julia(z, c);
      color = get_color(max_iteration);
      mlx_pixel_put(mlx, mlx_window, pixel.x, pixel.y, color);
      pixel.y++;
    }
    pixel.x++;
  } 
  mlx_loop(mlx);
	return (0);
}