/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:51 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 14:13:12 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ra(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    temp = (*a);
    *a = (*a)->next;
    last = ft_lstlast(temp);
    last->next = temp;
    temp->next = NULL;
    write(1, "ra\n", 4);
}
void rb(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    temp = (*b);
    *b = (*b)->next;
    last = ft_lstlast(temp);
    last->next = temp;
    temp->next = NULL;
    write(1, "rb\n", 4);
}

void rra(t_stack **a)
{
    t_stack *b_last;
    t_stack *temp;
    t_stack *last;

    b_last = ft_before_last(*a);
    last = b_last->next;
    b_last->next = NULL;
    temp = *a;
    *a = last;
    last->next = temp;
    write(1, "rra\n", 4);
}
void rrb(t_stack **b)
{
    t_stack *last;
    t_stack *sec;
    t_stack *temp;

    last = ft_lstlast(*b);
    sec->next = NULL;
    temp = *b;
    *b = last;
    last->next = temp;
    write(1, "rrb\n", 4);
}
