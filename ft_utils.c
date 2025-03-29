#include "philo.h"

long	ft_atol(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10) && str[i]
				- '0' > LONG_MAX % 10))
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}
