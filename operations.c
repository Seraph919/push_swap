/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:38 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 14:11:17 by asoudani         ###   ########.fr       */
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
    write(1, "pa\n", 4);
}
void pb(t_stack **a, t_stack **b)
{
    push(a,b);
    write(1, "pb\n", 4);
}
void sb(t_stack *b)
{
    int temp;

    temp = b->n;
    b->n = b->next->n;
    b->next->n = temp;
    write(1, "sb\n", 4);
}
void sa(t_stack *a)
{
    int temp;

    temp = a->n;
    a->n = a->next->n;
    a->next->n = temp;
    write(1, "sa\n", 4);
}