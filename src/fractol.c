/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:42:31 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/14 20:48:56 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 4 && !strcmp(argv[1], "mandelbrot"))
  {
      t_complex c;
      t_complex z;

      c.real = atof(argv[1]);
      c.i = atof(argv[2]);
      z = print_sequence_mandelbrot(c);
	  /*printf("Mandelbrot");*/
  }
	return (0);
}
