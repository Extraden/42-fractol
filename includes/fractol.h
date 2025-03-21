/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/21 16:56:45 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define MANDELBROT 1
# define JULIA 2
# ifndef ITERATIONS
#  define ITERATIONS 100
# endif
# define COLOR(r, g, b) ((r << 16) | (g << 8) | (b))
# define WIDTH 1200
# define HEIGHT 1200
# define REAL_CENTER 0.4
# define IM_CENTER 0.2
# define ZOOM 2000

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;


typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fractal_type;
	char	*fractal_name;
	t_complex	c;
	t_img	img;

}	t_fractal;

size_t		sequence_mandelbrot(t_complex c);
size_t		sequence_julia(t_complex z0, t_complex c);
int			render(t_fractal fractal);
t_complex   pixel_to_complex(t_pixel pixel);
t_pixel     complex_to_pixel(t_complex complex_point);

#endif
