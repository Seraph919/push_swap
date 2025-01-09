#include "pushswap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	casee;
	int	number;

	i = 0;
	casee = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			casee *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10 + (str[i++] - '0');
	}
	return (number * casee);
}