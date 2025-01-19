/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:20:33 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/19 18:23:03 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void three_alg(t_stack **a)
{
    if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n && (*a)->next->n < (*a)->next->next->n) // 15 2 13
        ra(a);
    else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n && (*a)->next->n > (*a)->next->next->n) // 15 13 2
    {
        ra(a);
        sa((*a));
    }
    else if ((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n && (*a)->next->n > (*a)->next->next->n) // 2 15 13
    {
        rra(a);
        sa((*a));
    }
    else if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n && (*a)->next->n < (*a)->next->next->n) // 13 2 15
        sa((*a));
    else if ((*a)->n < (*a)->next->n && (*a)->n > (*a)->next->next->n && (*a)->next->n > (*a)->next->next->n) // 13 15 2
        rra(a);
}

void four_alg(t_stack **a, t_stack **b)
{
    if (smallest_index(a) == 3)
        rra(a);
    else if (smallest_index(a) >=  2 && smallest_index(a) != 3)
    {
        rra(a);
        rra(a);
    }
    else if (smallest_index(a) < 2 && smallest_index(a) != 0)
    {
        ra(a);
    }
    pb(a, b);
    three_alg(a);
    pa(a, b);
}
void five_algo(t_stack **a, t_stack **b)
{
    if (smallest_index(a) == 4)
        rra(a);
    else if (smallest_index(a) == 3)
    {
        rra(a);
        rra(a);
    }
    else if (smallest_index(a) ==  2)
    {
        ra(a);
        ra(a);
    }
    else if (smallest_index(a) ==  1)
        ra(a);
    // print(*a);
    pb(a, b);
    // print(*a);
    four_alg(a, b);
    // print(*a);
    pa(a, b);
}

void more_algo(t_stack **a, t_stack **b, int *tab)
{
    int total = (*a)->total + 1;
    int end = total / 6;
    
}

void algoes(int *tab,t_stack **a, t_stack **b, int size)
{
    if (size  <= 3)
    {
        if (size == 2)
        {
            if ((*a)->n > (*a)->next->n)
                sa(*a);
        } 
        else
            three_alg(a);
    }
    else if (size == 4)
        four_alg(a, b);
    else if (size == 5)
        five_algo(a, b);
    else
        more_algo(a, b, tab);
}