/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/14 20:14:34 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef ITERATIONS
#  define ITERATIONS 500
# endif
# define EPSILON 1e-6

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
	int		endian;
	int		line_len;
}	t_img;


typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;

	t_img	img;

}	t_fractal;

t_complex	print_sequence_mandelbrot(t_complex c);
t_complex	print_sequence_julia(t_complex c, t_complex z0);

#endif
