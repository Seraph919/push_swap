/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraph <seraph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:04 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/14 20:04:18 by seraph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void push_given(t_stack *given ,t_stack **to)
{
	if (given)
	{
		if (given->prev)
		{
			given->prev->next = given->next;
			given->next->prev = given->prev;
		}
		given->next = *to;
		given->prev = NULL;
		// (*to)->prev = given;
		*to = given;
	}
}