/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraph <seraph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:00 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 23:11:11 by seraph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}

t_stack	*ft_before_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, int n)
{
    t_stack *new;

    new = ft_lstnew(n);
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	static int	index;
	static int total;
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
        new->index = 0;
		(*lst)->total = 1;
		return ;
	}
	if (lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
        new->index = ++index;
		(*lst)->total = ++total;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int		counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}