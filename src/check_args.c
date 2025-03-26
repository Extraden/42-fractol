#include "fractol.h"
#include "libft.h"

void	print_error_msg(void)
{
	ft_putendl_fd("Wrong arguments!", 2);
	ft_putendl_fd("Examples:", 2);
	ft_putendl_fd("./fractol mandelbrot", 2);
	ft_putendl_fd("./fractol julia -0.8 0.156", 2);
	ft_putendl_fd("./fractol burningship", 2);
}

t_result	check_args(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractal->name = MANDELBROT;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
		fractal->name = JULIA;
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship", 12))
		fractal->name = BURNINGSHIP;
	else
	{
		print_error_msg();
		return (FAILURE);
	}
	return (SUCCESS);
}
