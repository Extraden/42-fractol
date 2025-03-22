/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/22 16:44:13 by dsemenov         ###   ########.fr       */
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
# define REAL_CENTER -0.1
# define IM_CENTER 0.5
# define ZOOM 200


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

typedef struct	s_img_data
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;


typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fractal_type;
	char	*fractal_name;
	t_complex	c;
	t_img_data	img;

}	t_fractal;

size_t		sequence_mandelbrot(t_complex c);
size_t		sequence_julia(t_complex z0, t_complex c);
int			render(t_fractal fractal);
t_complex   pixel_to_complex(t_pixel pixel);
t_pixel     complex_to_pixel(t_complex complex_point);
double  	ft_atof(const char *arr);

#endif
