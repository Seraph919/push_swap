/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:30 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/15 14:31:19 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void total(t_stack **a,int i)
{
    (*a)->total = i;
}
int smallest_index(t_stack **a)
{
    t_stack *temp = *a;
    int smallest = temp->n;
    int i = 0;
    int index = 0;
    while (temp)
    {
        if (temp->n < smallest)
        {
            smallest = temp->n;
            index = i;
        }
        temp = temp->next;
        ++i;
    }
    total(a, i);
    return (index);
}

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

void more_algo(t_stack **a, t_stack **b)
{
    printf("%3d", (*a)->total);
}
void fire_force(t_stack **a)
{
    t_stack *temp;
    
    while (*a)
    {
        temp = *a;
        *a = (*a)->next;
        free(temp);
    }
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *temp;
    int     i;
    int     n;

    a = NULL;
    b = NULL;
    i = 1;
    if (ac >= 3)
    {
        while (av[i])
        {
            n = ft_atoi(av[i]);
            temp = ft_lstnew(n);
            ft_lstadd_back(&a, temp);
            i++;
        }
        i = 0;
        print(a);
        a->total = i;
        smallest_index(&a);
        if (a->total  <= 3)
        {
            if (a->total == 2)
            {
                if (a->n > a->next->n)
                    sa(a);
            } 
            else
                three_alg(&a);
        }
        else if (a->total == 4)
            four_alg(&a, &b);
        else if (a->total == 5)
            five_algo(&a, &b);
        else
            more_algo(&a, &b);
        print(a);
        fire_force(&a);
        fire_force(&b);
        // temp = a;
        // while (temp)
        // {
        //     printf("%d the index is : %d\n",temp->n, temp->index);
        //     temp = temp->next;
        // }
    }
}
// ! handle the cases where the input is already sorted!!!!
// ! make sure thaat u removed .a in solong
// }
// // printf("before pb :\na->n = %d\nthe last n is  = %d\n", a->n, ft_lstlast(a)->n);
//         rra(&a);
//         printf("after pb :\n");
//         i = 1;
//         temp = a;
//         while (temp)
//         {
//             printf("%d is %d\n", i++,temp->n);
//             temp = temp->next;
//         }
//         // printf("aftaa pb :\na->n = %d\nthe last n is = %d\n", a->n, ft_lstlast(a)->n);
// 