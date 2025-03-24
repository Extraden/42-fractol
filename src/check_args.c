#include "fractol.h"
#include "libft.h"

int	check_args(int argc, char **argv)
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)) || (argc == 2
			&& !ft_strncmp(argv[1], "burningship", 12)))
		return (0);
	else
	{
		ft_putendl_fd("Wrong arguments!", 2);
		ft_putendl_fd("Examples:", 2);
		ft_putendl_fd("./fractol mandelbrot", 2);
		ft_putendl_fd("./fractol julia -0.8 0.156", 2);
		ft_putendl_fd("./fractol burningship", 2);
		exit(1);
	}
}
