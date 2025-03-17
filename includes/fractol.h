/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/17 18:06:17 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef ITERATIONS
#  define ITERATIONS 500
# endif
# define EPSILON 1e-6
# define COLOR(r, g, b) ((r << 16) | (g << 8) | (b))

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

t_complex	sequence_mandelbrot(t_complex c);
t_complex	print_sequence_julia(t_complex c, t_complex z0);
int	render_mandelbrot(void);

#endif
