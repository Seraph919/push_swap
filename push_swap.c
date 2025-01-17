/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:30 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/17 10:50:28 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void total(t_stack **a,int i)
{
    (*a)->total = i;
}
int biggest_index(t_stack *a)
{
    t_stack *temp = a;
    int biggest = temp->n;
    int i = 0;
    int index = 0;
    while (temp)
    {
        if (temp->n > biggest)
        {
            biggest = temp->n;
            index = i;
        }
        temp = temp->next;
        ++i;
    }
    return (index);
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
    while (ft_lstsize(*a) > 5)
    {
        find_and_push(a, b);
        pb(a, b);
    }
    five_algo(a, b);
    while (ft_lstsize(*b) > 0)
        pa(a, b);
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
    long     n;

    a = NULL;
    b = NULL;
    i = 1;
    if (ac == 2 && ft_strchr(av[1], ' '))
    {
        split_arg(av[i], &a, &i); 
    }
    else if (ac >= 3)
    {
        while (av[i])
        {
            if (ft_strchr(av[i], ' '))
            {
                if (is_only_signs(av[i]))
                    return(ft_putstr("Error\n"), fire_force(&a), 1);
                split_arg(av[i], &a, &i); 
            }
            else 
            {
                if (is_only_signs(av[i]))
                    return(ft_putstr("Error\n"), fire_force(&a), 1);
                n = ft_atol(av[i]);
                // printf("the number from atol is %ld\n", n);
                if (check_invalid(n))
                    return(ft_putstr("Error\n"), fire_force(&a), 1);
                temp = ft_lstnew(n);
                ft_lstadd_back(&a, temp);
                i++;
            }
        }
    }
    else if (ac == 1 || ac == 2 && !ft_strchr(av[1], ' '))
    {
        return(ft_putstr("Error\n"), fire_force(&a), 1);
    }
    if (check_repeat(a, &a) == 1 || check_sorted(a) == 1)
        return (fire_force(&a), 1);
    // printf("the total arguments is : %d\n", a->total);
    if (a->total + 1  <= 3)
    {
        if (a->total + 1== 2)
        {
            if (a->n > a->next->n)
                sa(a);
        } 
        else
            three_alg(&a);
    }
    else if (a->total + 1 == 4)
        four_alg(&a, &b);
    else if (a->total + 1 == 5)
        five_algo(&a, &b);
    else
        more_algo(&a, &b);
    // print(a);
    fire_force(&a);
    fire_force(&b);
    // temp = a;
    // while (temp)
    // {
    //     printf("%d the index is : %d\n",temp->n, temp->index);
    //     temp = temp->next;
    // }
}
// ! this case should'nt work
// TODO:  ./push_swap  "                           2" 
// ! As u see It's already sorted! this already sorted shouldnt be
// ! handle the cases where the input is already sorted!!!! 
// * DONE!
// ! handle empty strings..
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