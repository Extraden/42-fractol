/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/22 20:33:14 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include "fractol.h"
#include "libft.h"

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

// static void	my_mlx_pixel_put(t_img_data *image_data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = image_data->pixels_ptr + (y * image_data->line_length + x * (image_data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	mouse_hook(int keycode, t_fractal *fractal)
{
  (void) fractal;
  if (keycode == 1)
	  printf("Hello from key_hook!\n");
	return (0);
}

int	render(t_fractal fractal)
{
  t_complex c;
  t_complex z;
  t_pixel pixel;
  size_t  max_iteration;
  int     color;
  int width;
  int height;
	fractal.mlx_ptr = mlx_init();
  if (!fractal.mlx_ptr)
  {
    perror("mlx_init");
    exit(EXIT_FAILURE);
  }  
  fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, WIDTH, HEIGHT, fractal.fractal_name);
	fractal.img.img_ptr = mlx_new_image(fractal.mlx_ptr, WIDTH, HEIGHT);
	fractal.img.pixels_ptr = mlx_get_data_addr(fractal.img.img_ptr, &fractal.img.bits_per_pixel,
  &fractal.img.line_length, &fractal.img.endian);
  //int offset = (y * fractal.img.line_length + x * (fractal.img.bits_per_pixel / 8));


  width = 800;
  height = 800;
  pixel.x = 0;
  while (pixel.x < width)
  {
    pixel.y = 0;
    while (pixel.y < height)
    {
      if (!(ft_strncmp(fractal.fractal_name, "mandelbrot", 11)))
      {
        c = pixel_to_complex(pixel);
        max_iteration = sequence_mandelbrot(c);
      }
      else if (!ft_strncmp(fractal.fractal_name, "julia", 6))
      {
        z = pixel_to_complex(pixel);
        max_iteration = sequence_julia(z, fractal.c);
      }
      color = get_color(max_iteration);
      mlx_pixel_put(fractal.mlx_ptr, fractal.win_ptr, pixel.x, pixel.y, color);
      pixel.y++;
    }
    pixel.x++;
  }
  mlx_mouse_hook(fractal.win_ptr, mouse_hook, &fractal);
  mlx_loop(fractal.mlx_ptr);
	return (0);
}