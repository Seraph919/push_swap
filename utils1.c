#include "pushswap.h"

int check_invalid(long n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return (0);
}
int check_repeat(t_stack *lst)
{
    t_stack *temp;

    temp = lst;
    while (lst)
    {
        temp = lst->next;
        while (temp)
        {
            if (lst->n == temp->n)
            {
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

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)search_str == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}
void split_arg (char *av, t_stack **a, int *index)
{
    t_stack *temp;
    int i;
    long n;
    char **s;
    
    s = ft_split(av, ' ');
    i = 0;
    while (s[i])
    {
        n = ft_atol(s[i]);
        if (check_invalid(n))
            exit(666);
        temp = ft_lstnew(n);
        ft_lstadd_back(a, temp);
        i++;
    }
    *index += 1;
}

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
                printf("lst %d in index : %d is the same as lst %d in index : %d"
                    , temp->n, temp->index, lst->n, lst->index);
                return (0);
            }
            temp = temp->next;
        }
        lst = lst->next;
    }
    return (1);
}