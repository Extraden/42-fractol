/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/19 18:53:54 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fractol.h"

// Color hint
 int red = (255 << 16) | (0 << 8) | 0;
 int green = (0 << 16) | (255 << 8) | 0;
 int blue = (0 << 16) | (0 << 8) | 255;

// // Пример функции для расчёта цвета на основе числа итераций.
// // Можно заменить формулу на любую другую, здесь приведён вариант градиента.
// static int	get_color(size_t iter)
// {
//     int	color;
//     if (iter == ITERATIONS)
//         return (COLOR(0, 0, 0)); // Точка принадлежит множеству — чёрная.

//     // Простейший градиент: серый цвет от чёрного до белого.
//     double t = (double)iter / (double)ITERATIONS;
//     int gray = (int)(t * 255);
//     color = COLOR(gray, gray, gray);
    
//     // Можно использовать и более сложную схему, например:
//     // int r = (int)(9 * (1 - t) * t * t * t * 255);
//     // int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     // int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//     // color = COLOR(r, g, b);
    
//     return (color);
// }


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
  t_complex complex_res;
  int     color;

	mlx = mlx_init();
  mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);

	img.pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

  complex_res = (t_complex){0};
  c = (t_complex){0};

  pixel.x = 0;
  while (pixel.x < WIDTH)
  {
    pixel.y = 0;
    while (pixel.y < HEIGHT)
    {
      c = pixel_to_complex(pixel);
      complex_res = sequence_mandelbrot(c);
      if (complex_res.i * complex_res.i + complex_res.real * complex_res.real > 4)
      {
        pixel_to_complex(pixel);
        complex_to_pixel(complex_res);
        color = get_color(complex_res.last_iteration);
        mlx_pixel_put(mlx, mlx_window, pixel.x, pixel.y, color);
      }
      pixel.y++;
    }
    pixel.x++;
  } 
  mlx_loop(mlx);
	return (0);
}
