/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/19 18:51:35 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef ITERATIONS
#  define ITERATIONS 100
# endif
# define EPSILON 1e-6
# define COLOR(r, g, b) ((r << 16) | (g << 8) | (b))
# define WIDTH 800
# define HEIGHT 800
# define REAL_CENTER -0.4
# define IM_CENTER 0
# define ZOOM 250

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	real;
	double	i;
	size_t	last_iteration;
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
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	t_img	img;

}	t_fractal;

t_complex	sequence_mandelbrot(t_complex c);
t_complex	print_sequence_julia(t_complex c, t_complex z0);
int	render_mandelbrot(void);
t_complex   pixel_to_complex(t_pixel pixel);
t_pixel     complex_to_pixel(t_complex complex_point);

#endif
