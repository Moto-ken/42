
#include "push_swap.h"

int is_valid_number(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return (1);
    while (*str)
	{
        if (*str < '0' || *str > '9')
            return (1);
        str++;
    }
    return (0);
}

int	new_ft_atoi(const char *nptr, int *out)
{
	int		i = 0;
	int		sign = 1;
	long	nb = 0;

	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && -nb < INT_MIN))
			return (1);
		i++;
	}
	if (nptr[i] != '\0')
		return (1);
	*out = (int)(nb * sign);
	return (0);
}

int parse_arguments(int count, char **vale, t_node **stack_a)
{
	int i = 0;
	int nb = 0;
	t_node *new = NULL;
	while (i < count)
	{
		if (is_valid_number(vale[i]))
			return (1);
		if (new_ft_atoi(vale[i], &nb))
			return (1);
		new = new_node(nb);
		if (!new)
			return (1);
		push_node(stack_a, new);
		i++;
	}
	return (0);
}
