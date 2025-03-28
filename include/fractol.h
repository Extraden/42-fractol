/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:32 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 20:47:53 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include <stddef.h>

# define FRACTOL_H
# define ITERATIONS 50
# define WIDTH 800
# define HEIGHT 800
# define SCROLL_IN 4
# define SCROLL_OUT 5

typedef enum e_result
{
	FAILURE,
	SUCCESS
}				t_result;

typedef enum e_name
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}				t_name;

typedef struct s_viewport
{
	int			width;
	int			height;
	double		real_center;
	double		im_center;
	double		zoom;
}				t_viewport;

typedef struct s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_color_map
{
	double		t;
	int			r;
	int			g;
	int			b;
	int			color;
}				t_color_map;

typedef struct s_img_data
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			to_render;
	t_name		name;
	t_complex	c;
	t_img_data	img;
	t_viewport	viewport;
	t_color_map	color_map;

}				t_fractal;

size_t			calculate_mandelbrot_sequence(t_complex c);
size_t			calculate_julia_sequence(t_complex z0, t_complex c);
size_t			calculate_burning_ship_sequence(t_complex c);
int				render(t_fractal *fractal);
t_complex		pixel_to_complex(t_pixel pixel, t_viewport viewport);
t_result		ft_atof(const char *arr, double *value);
t_result		init_mlx_system(t_fractal *fractal, char *name);
int				handle_arrow_click(int keycode, void *fractal);
int				handle_close(void *fractal);
int				handle_scroll(int button, int x, int y, void *fractal);
int				get_color(size_t iter, t_color_map *color);
void			my_mlx_pixel_put(t_img_data *image_data, int x, int y,
					int color);
int				loop_hook(void *fractal);
void			mlx_handle_hooks(t_fractal *fractal);
t_result		parse(t_fractal *fractal, int argc, char **argv);
void			print_wrong_args_msg(void);
t_result		fractal_init(t_fractal *fractal, char **argv);
void			draw_mandelbrot(t_fractal *fractal);
void			draw_julia(t_fractal *fractal);
void			draw_burning_ship(t_fractal *fractal);

#endif
