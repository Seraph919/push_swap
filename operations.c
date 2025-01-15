/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:38 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:10 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void push(t_stack **from, t_stack **to)
{
    if (*from)
    {
        t_stack *temp = *from;
        *from = (*from)->next;
        if (*to == NULL)
        {
            *to = temp;
            (*to)->next = NULL;
        }
        else
        {
            temp->next = *to;
            *to = temp;
        }
    }
}
void pa(t_stack **a, t_stack **b)
{
    push(b,a);
    ft_putstr("pa\n");
}
void pb(t_stack **a, t_stack **b)
{
    push(a,b);
    ft_putstr("pb\n");
}
void sb(t_stack *b)
{
    int temp;

    temp = b->n;
    b->n = b->next->n;
    b->next->n = temp;
    ft_putstr("sb\n");
}
void sa(t_stack *a)
{
    int temp;

    temp = a->n;
    a->n = a->next->n;
    a->next->n = temp;
    ft_putstr("sa\n");
}