/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:30 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/19 18:20:38 by asoudani         ###   ########.fr       */
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
void more_arguments(char **av, t_stack **a, t_stack **b)
{
    int i = 1;
    int n ;
    while (av[i])
        {
            if (ft_strchr(av[i], ' '))
            {
                if (is_only_signs(av[i]))
                    return(ft_putstr("Error\n"), fire_force(a), exit(1));
                split_arg(av[i], a, &i); 
            }
            else 
            {
                if (is_only_signs(av[i]))
                    return(ft_putstr("Error\n"), fire_force(a), exit(1));
                n = ft_atol(av[i]);
                if (check_invalid(n))
                    return(ft_putstr("Error\n"), fire_force(a), exit(1));
                ft_lstadd_back(a, ft_lstnew(n));
                i++;
            }
        }
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *temp;
    t_data *data;
    int     i;
    long     n;

    a = NULL;
    b = NULL;
    i = 1;
    if (ac == 1 || ac == 2 && !ft_strchr(av[1], ' '))
    {
        return(ft_putstr("Error\n"), fire_force(&a), 1);
    }
    else if (ac == 2 && ft_strchr(av[1], ' '))
    {
        split_arg(av[i], &a, &i); 
    }
    else if (ac > 2)
    {
        more_arguments(av, &a, &b);
        print(a);
    }
    if (check_repeat(a, &a) == 1 || check_sorted(a) == 1)
        return (fire_force(&a), 1);
    int *tab = prep_index(a);
    indexed(tab, i);
    algoes(tab, &a, &b, a->total + 1);
    print(a);
    free(tab);
    fire_force(&a);
    fire_force(&b);

}

// ! As u see It's already sorted! this already sorted shouldnt be
// ! handle the cases where the input is already sorted!!!! 
// * DONE!
// ! handle empty strings..
// * index fun, split the code, make stuff more clear        DONE!
// TODO :  i need to implemet in the index algorithm so i can sort the stack in a fewer ops..
