#include "pushswap.h"

int check_invalid(long n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return (0);
}
int check_repeat(t_stack *lst)
{
    static int iteration = 1;
    int i;
    int n;
    int k;
    int *tab;
    int total = lst->total;
    printf("the number of iteration is :%d\n", iteration++);
    tab = malloc((total * sizeof(int)) + 1);
    i = 0;
    n = 0;
    if (!tab)
        return (1);
    while(lst)
    {
        tab[i] = lst->n;
        lst = lst->next;
        i++;
    }
    while (n < total)
    {
        printf("tab [%d] = %d\n", n,tab[n]);
        n++;
    }
    n = 0;
    while (i < total)
    {
        while (n < total)
        {
            if (tab[i] == tab[n])
                return (1);
            k++;
        }
        i++;
    }
    free(tab);
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
void split_arg (char *av, t_stack **a)
{
    int i = 0;
    t_stack *temp;
    long n;
    char **s = ft_split(av, ' ');
    while (s[i])
    {
        n = ft_atol(s[i]);
        if (check_invalid(n))
            exit(666);
        temp = ft_lstnew(n);
        ft_lstadd_back(a, temp);
        i++;
    }
}