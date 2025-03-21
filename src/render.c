/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/21 20:55:01 by dsemenov         ###   ########.fr       */
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

int	render(t_fractal fractal)
{
	void	*mlx;
  void  *mlx_window;
//	t_img	img;
  t_complex c;
  t_complex z;
  t_pixel pixel;
  size_t  max_iteration;
  int     color;

	mlx = mlx_init();
  perror("mlx_init");
  exit(EXIT_FAILURE);
  mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, fractal.fractal_name);
	// img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	// img.pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

  pixel.x = 0;
  while (pixel.x < WIDTH)
  {
    pixel.y = 0;
    while (pixel.y < HEIGHT)
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
      mlx_pixel_put(mlx, mlx_window, pixel.x, pixel.y, color);
      pixel.y++;
    }
    pixel.x++;
  } 
  mlx_loop(mlx);
	return (0);
}