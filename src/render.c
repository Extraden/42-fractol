/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/17 18:10:32 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fractol.h"

// Color hint
 int red = (255 << 16) | (0 << 8) | 0;
 int green = (0 << 16) | (255 << 8) | 0;
 int blue = (0 << 16) | (0 << 8) | 255;

int	render_mandelbrot(void)
{
	void	*mlx;
  void  *mlx_window;
	t_data	img;
  t_complex c;
  t_complex res;

	mlx = mlx_init();
  mlx_window = mlx_new_window(mlx, 1920, 1080, "Fractol");
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

  res = (t_complex){0};

  c.real = 0;
  while (c.real < 1920)
  {
    c.i = 0;
    while (c.i < 1080)
    {
      res = sequence_mandelbrot(c);
      if (res.i * res.i + res.real * res.real > 4)

        mlx_pixel_put(mlx, mlx_window, c.real, c.i, COLOR(255, 0, 0));
      
      c.i++;
    }
    c.real++;
  } 
  mlx_loop(mlx);
	return (0);
}
