/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:04 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 16:52:41 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void print(t_stack *a)
{
    t_stack *temp;

    temp = a;
    printf(".............\n");
    while (temp)
    {
        printf("%d\n",temp->n);
        temp = temp->next;
    }
    printf(".............\n");
}

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

t_stack *find_smallest(t_stack *a)
{
	t_stack *returned = a;
	int smallest = a->n;
	while (a)
	{
		if (smallest > a->n)
		{
			smallest = a->n;
			returned = a;
		}
		a = a->next;
	}
	return (returned);
}
void find_and_push(t_stack **from ,t_stack **to)
{
	if (smallest_index(from) > ft_lstsize(*from) / 2)
	{
		while (smallest_index(from) != 0)
		{
			rra(from);
		}
	}
	// else if (smallest_index(from) == ft_lstsize(*from) / 2)
	// {
	// 	while (smallest_index(from) != 0)
	// 	{
	// 		rra(from);
	// 	}
	// 	rra(from);
	// }
	else if (smallest_index(from) < ft_lstsize(*from) / 2)
	{
		while (smallest_index(from) != 0)
		{
			ra(from);
		}
	}
}
void ft_putstr(char *s)
{
	while (*s)
		write(1, &(*s++), 1);
}