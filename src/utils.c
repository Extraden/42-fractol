/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:47:51 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/28 16:21:09 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_sign(const char **ptr, int *sign)
{
	if (**ptr == '-' || **ptr == '+')
	{
		if (**ptr == '-')
			*sign *= -1;
	}
}

t_result	ft_atof(const char *arr, double *value)
{
	double	res;
	double	factor;
	int		sign;

	res = 0;
	factor = 0.1;
	sign = 1;
	while ((*arr >= '\t' && *arr <= '\r') || *arr == ' ')
		arr++;
	get_sign(&arr, &sign);
	arr++;
	while ('0' <= *arr && *arr <= '9')
		res = (res * 10) + (*arr++ - '0');
	if (*arr == '.')
		arr++;
	while ('0' <= *arr && *arr <= '9')
	{
		res += (*arr++ - '0') * factor;
		factor *= 0.1;
	}
	*value = (res * sign);
	return (*arr == '\0');
}
