#include <math.h>

void skip_make_sign(const char **ptr, int *sign)
{
    if (**ptr == '-' || **ptr == '+')
	{
		if (**ptr == '-')
			*sign *= -1;
		*ptr = *ptr + 1;
	}
}

double  ft_atof(const char *arr)
{
    double  res;
    int     sign;

    res = 0;
    sign = 1;
	while ((*arr >= 9 && *arr <= 13) || *arr == ' ')
		arr++;
    skip_make_sign(&arr, &sign);
	while (*arr >= '0' && *arr <= '9')
	{
		res = (res * 10) + (*arr - 48);
		arr++;
	}
    if (*arr == '.')
        arr++;
    int i = 0;
    while (arr[i] && (arr[i] >= '0' && arr[i] <= '9'))
	{
		res = res + (arr[i] - 48) * pow(10, -(i + 1));
		i++;
	}
	return (res * sign);
}