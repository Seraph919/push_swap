/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:23:38 by asoudani          #+#    #+#             */
/*   Updated: 2025/01/16 18:44:18 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_sorted(t_stack *lst)
{
    t_stack *temp;

    temp = lst;
    while (lst)
    {
        temp = lst->next;
        while (temp)
        {
            if (lst->n > temp->n)
            {
                return (0);
            }
            temp = temp->next;
        }
        lst = lst->next;
    }
    return (1);
}
int is_only_signs(char *s)
{
    int  i = 0;
    while (s[i])
    {
        if (s[i] != '-' && s[i] != '+' && s[i] != '\0' && s[i] != '\t' && s[i] != ' ')
            return (0);
        i++;
    }
    // if (s[0] == '\0')
    return (1);
}
static int	sign_or_isdigit(int argument)
{
	return ((argument >= '0' && argument <= '9') 
        || argument == '-' || argument == '+');
}
int check_strings(char **s)
{
    int i = 0;
    int k;
    while (s[i])
    {
        if (is_only_signs(s[i]))
            return (1);
        k = 0;
        while (s[i][k])
        {
            if (!sign_or_isdigit(s[i][k]))
                return(1);
            k++;  
        }
        i++;
    }
    return (0);
}
int check_invalid(long n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return (0);
}
int check_repeat(t_stack *lst)
{
    t_stack *temp;

    while (lst)
    {
        temp = lst->next;
        while (temp)
        {
            if (lst->n == temp->n)
            {
                ft_putstr("INVALID INPUT!\n"),
                printf("lst %d in index : %d is the same as lst %d in index : %d"
                    , temp->n, temp->index, lst->n, lst->index);
                return (1);
            }
            temp = temp->next;
        }
        lst = lst->next;
    }
    return (0);
}