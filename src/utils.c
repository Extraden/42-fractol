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
    double  factor;
    int     sign;

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
	return (res * sign);
}