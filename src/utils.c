/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:47:51 by dsemenov          #+#    #+#             */
/*   Updated: 2025/03/26 19:12:15 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_make_sign(const char **ptr, int *sign)
{
	if (**ptr == '-' || **ptr == '+')
	{
		if (**ptr == '-')
			*sign *= -1;
		*ptr = *ptr + 1;
	}
}

t_result	ft_atof(const char *arr, double *value)
{
	double res;
	double factor;
	int sign;

	res = 0;
	factor = 0.1;
	sign = 1;
	while ((*arr >= 9 && *arr <= 13) || *arr == ' ')
	arr++;
	skip_make_sign(&arr, &sign);
	while (*arr >= '0' && *arr <= '9')
	{
		res = (res * 10) + (*arr - '0');
		arr++;
	}
	if (*arr == '.')
		arr++;
	int i = 0;
	while (arr[i] && (arr[i] >= '0' && arr[i] <= '9'))
	{
		res += (arr[i] - '0') * factor;
		factor *= 0.1;
		i++;
	}
	if (arr[i] != '\0')
		return (FAILURE);
	*value = (res * sign);
	return (SUCCESS);
}
