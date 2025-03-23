/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:52 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/23 18:46:10 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int handle_arrow_click(int keycode, void *fractal)
{
  t_fractal *f = (t_fractal *) fractal;

  if (keycode == 65361)
  {
    f->vars.real_center -= f->vars.zoom * 0.0001;
  }
  if (keycode == 65362)
  {
    f->vars.im_center -= f->vars.zoom * 0.0001;
  }
  if (keycode == 65363)
  {
    f->vars.real_center += f->vars.zoom * 0.0001;
  }
  if (keycode == 65364)
  {
    f->vars.im_center += f->vars.zoom * 0.0001;
  }
  render(f);
  printf("Key clicked: %d\n", keycode);
  return (0);
}

static int handle_close(void *fractal)
{
    t_fractal *f = (t_fractal *) fractal;
    
    mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
    exit(0);
    return (0);
}

static int handle_scroll(int button, int x, int y, void *fractal)
{
  t_fractal *f = (t_fractal *) fractal;

  (void) x;
  (void) y;
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
void  init_mlx_system(t_fractal *fractal)
{
  fractal->mlx_ptr = mlx_init();
  if (!fractal->mlx_ptr)
  {
    perror("mlx_init");
    exit(EXIT_FAILURE);
  }  
  fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->fractal_name);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel,
  &fractal->img.line_length, &fractal->img.endian);
}

int	render(t_fractal *fractal)
{
  t_complex c;
  t_complex z;
  t_pixel pixel;
  size_t  max_iteration;
  int     color;
  
  //int offset = (y * fractal.img.line_length + x * (fractal.img.bits_per_pixel / 8));
  pixel.x = 0;
  while (pixel.x < fractal->vars.width)
  {
    pixel.y = 0;
    while (pixel.y < fractal->vars.height)
    {
      if (!(ft_strncmp(fractal->fractal_name, "mandelbrot", 11)))
      {
        c = pixel_to_complex(pixel, fractal->vars);
        max_iteration = calculate_mandelbrot_sequence(c);
      }
      else if (!ft_strncmp(fractal->fractal_name, "julia", 6))
      {
        z = pixel_to_complex(pixel, fractal->vars);
        max_iteration = calculate_julia_sequence(z, fractal->c);
      }
      color = get_color(max_iteration);
      mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, pixel.x, pixel.y, color);
      pixel.y++;
    }
    pixel.x++;
  }
  // mlx_hook(fractal->win_ptr, , fractal)
  mlx_hook(fractal->win_ptr, 4, 1L << 2, handle_scroll, fractal);
  mlx_hook(fractal->win_ptr, 2, 1L << 0, handle_arrow_click, fractal);
  mlx_hook(fractal->win_ptr, 17, 0, handle_close, fractal);
  mlx_loop(fractal->mlx_ptr);
	return (0);
}